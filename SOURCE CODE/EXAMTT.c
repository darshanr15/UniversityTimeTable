#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char days[7][10] = {"Sunday",   "Monday", "Tuesday", "Wednesday",
                    "Thursday", "Friday", "Saturday"};

struct date {
  int d;
  int m;
  int year;
};

struct course

{
  char courseCode[10];
  char courseName[20];
  char type[7];
  char session[7];
};

struct schedule {
  struct date dt;
  char day[10];
  char courseCode[10];
  char courseName[20];
  char type[7];
  char session[7];
};

struct room {
  char roomNo[5];
  int roomCapacity;
  int status;
  int remainingSeats;
};
struct Invigilator {
  char facultyName[20];
  int avail;
};

struct student {
  int rno;
  int regNo;
  char name[20];
};

struct class {
  char dept[10];
  int deptCode;
  int noOfStudents;
  int regNos[60];
};
struct hallAllocation {
  char hallNo[5];
  int regNoAssigned[30];
  int currentCnt;
};

int dayfind(struct date stdate) {
  int e = (365 * (stdate.year - 1)) + (stdate.d - 1) +
          ((stdate.year / 4) - (stdate.year / 100) + (stdate.year / 400));

  for (int d = 1; d < stdate.m; d++)
  {
    e += (d == 2) ? (28)
                  : ((d == 4 || d == 6 || d == 9 || d == 11) ? (30) : (31));
  }
  int dayIndex = e % 7 + 1;
  if (dayIndex == 7)
    dayIndex = 0;
  return dayIndex;
}

int holidaycheck(struct date stdate, struct date holidays[10], int N) {
  for (int k = 0; k < N; k++) {
    if (stdate.m == holidays[k].m) {
      if (stdate.d == holidays[k].d) {
        stdate.d += 1;
        if (stdate.d == holidays[k].d) {
          stdate.d += 1;
        }
      }
    }
  }
  return stdate.d;
}

int leapyear(struct date st) {
  if (st.year % 400 == 0) {
 if (st.year % 100 == 0) {
    return 0;
  } else if (st.year % 4 == 0) {
    return 1;
  } else {
    return 0;
  }
}
  }

void prepareSchedule(struct date st, struct course CS[], int n,
                     struct schedule S[], int day, struct date holis[]) {
  int i, j, ran;
  j = 0;
  srand(time(NULL));
  for (i = 0; i < n; i++) {
    ran = rand()%3 + 4;
    S[i].dt.d = st.d + j;
    S[i].dt.m = st.m;
    if (S[i].dt.m == 2) {
      int y = leapyear(S[i].dt);
      if (y == 1) {
        if (S[i].dt.d > 29) {
          printf("%d-%d-%d \n", S[i].dt.d, S[i].dt.m, S[i].dt.year);
          S[i].dt.d -= 29;
          S[i].dt.m += 1;
        }
      } else {
        if (S[i].dt.d > 28) {
          S[i].dt.d -= 28;
          S[i].dt.m += 1;
        }
      }
    }
    if (S[i].dt.d > 31) {
      S[i].dt.d -= 31;
      S[i].dt.m += 1;
    }
    S[i].dt.year = st.year;
    if (S[i].dt.m > 12) {
      S[i].dt.m -= 12;
      S[i].dt.year += 1;
    }
    strcpy(S[i].courseCode, CS[i].courseCode);
    strcpy(S[i].courseName, CS[i].courseName);
    strcpy(S[i].type, CS[i].type);
    strcpy(S[i].session, CS[i].session);
    j = j + ran;
    day = day + ran;
    for (int k = 0; k < 3; k++) {
      if (S[i].dt.m == holis[k].m) {
        if (S[i].dt.d == holis[k].d) {
          S[i].dt.d += 1;
          j += 1;
          if (S[i].dt.d == holis[k].d) {
            S[i].dt.d += 1;
            j += 1;
          }
        }
      }
      if (day > 6) {
        day = day % 7;
        int res = strcmp(days[day], "Sunday");
        if (res == 0) {
          j = j + 1;
          day = day + 1;
        }
      }
    }
  }
}

void scoreandsort(char cse[][25], char it[][25], char ece[][25], char eee[][25],
                  char civil[][25], char mech[][25]) {
  int score[6] = {0, 0, 0, 0, 0, 0};
  int i = 0, j = 0, temp = 0;
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      if (strcmp(cse[i], it[j]) == 0) {
        score[i]++;
      }
      if (strcmp(cse[i], ece[j]) == 0) {
        score[i]++;
      }
      if (strcmp(cse[i], eee[j]) == 0) {
        score[i]++;
      }
      if (strcmp(cse[i], civil[j]) == 0) {
        score[i]++;
      }
      if (strcmp(cse[i], mech[j]) == 0) {
        score[i]++;
      }
    }
  }
  for (i = 0; i < 6; i++) {
    for (j = i + 1; j < 6; j++) {
      if (score[i] < score[j]) {
        temp = score[i];
        score[i] = score[j];
        score[j] = temp;
      }
    }
  }
}

void printSchedule(char deptlist[][10], char cse[][25], char it[][25],
                   char ece[][25], char eee[][25], char civil[][25],
                   char mech[][25], struct schedule *S, int sem, FILE *fp) {

  int i = 0;
  if (sem % 2 != 0) {
    fprintf(fp, "FORENOON\n\n");
  }
  if (sem % 2 == 0) {
    fprintf(fp, "AFTERNOON\n\n");
  }
  fprintf(fp, "DEPT. ");
  for (i = 0; i < 6; i++) {
    fprintf(fp, "       %d-%d-%d           ", S[i].dt.d, S[i].dt.m,
            S[i].dt.year);
  }
  fprintf(fp, "\n");
  for (i = 0; i < 6; i++) {
    fprintf(fp, "%s", deptlist[i]);
    if (strcmp(deptlist[i], "CSE  ") == 0) {
      for (int k = 0; k < 6; k++) {
        fprintf(fp, "  %s  ", cse[k]);
      }
    }
    if (strcmp(deptlist[i], "IT   ") == 0) {
      for (int k = 0; k < 6; k++) {
        fprintf(fp, "  %s  ", it[k]);
      }
    }
    if (strcmp(deptlist[i], "ECE  ") == 0) {
      for (int k = 0; k < 6; k++) {
        fprintf(fp, "  %s  ", ece[k]);
      }
    }
    if (strcmp(deptlist[i], "EEE  ") == 0) {
      for (int k = 0; k < 6; k++) {
        fprintf(fp, "  %s  ", eee[k]);
      }
    }
    if (strcmp(deptlist[i], "CIVIL") == 0) {
      for (int k = 0; k < 6; k++) {
        fprintf(fp, "  %s  ", civil[k]);
      }
    }
    if (strcmp(deptlist[i], "MECH ") == 0) {
      for (int k = 0; k < 6; k++) {
        fprintf(fp, "  %s  ", mech[k]);
      }
    }
    fprintf(fp, "\n");
  }
}

void getInvigilators(struct Invigilator *inv, int ni, FILE *fpi) {
  int i;
  for (i = 0; i < 12; i++) {
    fscanf(fpi, "%s %d", inv[i].facultyName, &inv[i].avail);
  }
}

void getHalls(struct room halls[], int nh, FILE *fp) {
  int i;
  for (i = 0; i < nh; i++) {
    fscanf(fp, "%s %d", halls[i].roomNo, &halls[i].roomCapacity);
    halls[i].status = 1;
    halls[i].remainingSeats = halls[i].roomCapacity;
  }
}

void checkinvi(struct Invigilator *inv, int t, FILE *fph,
               struct hallAllocation Halls[], int sem) {
  int jj = 0;
  for (int i = 0; i < t; i++) {
    fprintf(fph, "  %s\t", Halls[i].hallNo);
    if (sem == 1) {
      fprintf(fph, "     3122 21 ");
    }
    if (sem == 2) {
      fprintf(fph, "     3122 20 ");
    }
    if (sem == 3) {
      fprintf(fph, "     3122 19 ");
    }
    if (sem == 4) {
      fprintf(fph, "     3122 18 ");
    }
    fprintf(fph, "%d ", Halls[i].regNoAssigned[0]);
    fprintf(fph, "To ");
    fprintf(fph, "%d\t", Halls[i].regNoAssigned[Halls[jj].currentCnt - 1]);
    for (int ii = 0; i < t; i++) {
      if (inv[ii].avail == 1) {
        fprintf(fph, "         %s", inv[i].facultyName);
        break;
      } else
        continue;
    }
    jj++;
    fprintf(fph, "\n");
  }
}

void getClasses(struct class classes[], int nc, FILE *fpd) {
  char className[10];
  char dept[10];
  int noOfStudents;
  int regNos[60];
  int i, j, k;
  char deptName[10][10] = {"CSE", "ECE", "MECH", "CIVIL", "EEE", "IT"};
  int deptCode[] = {1000, 2000, 3000, 4000, 5000, 6000};
  for (i = 0; i < nc; i++) {
    fscanf(fpd, "%d %d", &classes[i].deptCode, &classes[i].noOfStudents);
    for (j = 0; j < 6; j++) {
      if (classes[i].deptCode == deptCode[j]) {
        k = j;
        break;
      }
    }
    strcpy(classes[i].dept, deptName[k]);
    for (j = 0; j < classes[i].noOfStudents; j++) {
      classes[i].regNos[j] = deptCode[k];
      deptCode[k]++;
    }
  }
}

int allocateHalls(struct room halls[], int nh, struct class classes[], int nc,
                  struct hallAllocation Halls[]) {
  int i, j, n, totals = 0, h = 0, jj, k, ii, bal, cnt, R = 0, kk;
  int *totalR;
  for (i = 0; i < nc; i++)
    totals = totals + classes[i].noOfStudents;
  for (i = 0; i < nh; i++)
    h = h + halls[i].roomCapacity;
  if (totals > h)
    printf("Not enough number of HALLS\n");
  totalR = (int *)malloc(totals * sizeof(int));
  k = 0;

  for (i = 0; i < nc; i++) {
    for (j = 0; j < classes[i].noOfStudents; j++) {
      totalR[k] = classes[i].regNos[j];
      k++;
    }
  }
  jj = 0;
  kk = 0;
  R = 0;
  j = 0;
  while (kk < totals) {
    jj = 0;
    strcpy(Halls[j].hallNo, halls[j].roomNo);
    Halls[j].currentCnt = 0;
    while (jj < halls[j].roomCapacity) {
      if (kk > totals)
        break;
      else {
        Halls[j].regNoAssigned[jj] = totalR[kk];
        kk++;
      }
      Halls[j].currentCnt++;
      jj = jj + 1;
    }
    j++;
  }
  return j;
}

void printhalls(struct room halls[30], FILE *fp1, struct class classes[],
                FILE *fpd, struct Invigilator *inv, FILE *fph1,
                struct hallAllocation Halls[30], FILE *fpi, int sem,
                struct schedule S[10]) {

  int nh = 12;
  getHalls(halls, nh, fp1);
  int nc = 6;
  getClasses(classes, nc, fpd);
  int k = allocateHalls(halls, nh, classes, nc, Halls);
  inv = (struct Invigilator *)malloc(12 * sizeof(struct Invigilator *));
  int t = 12;
  getInvigilators(inv, t, fpi);
  fprintf(fph1, "\n");
  fprintf(fph1, "SEMESTER - %d\n", sem);
  if (sem % 2 != 0) {
    fprintf(fph1, "FORENOON ( 9.00 AM - 12.15 PM )\n");
  }
  if (sem % 2 == 0) {
    fprintf(fph1, "AFTERNOON ( 1.00 PM - 4.15 PM )\n");
  }
  fprintf(fph1, "DATES: ");
  for (int i = 0; i < 6; i++) {
    fprintf(fph1, " %d-%d-%d ", S[i].dt.d, S[i].dt.m, S[i].dt.year);
  }
  fprintf(fph1, "\n");
  fprintf(fph1, "-----------------------------------------------------\n");
  fprintf(fph1, "HALL NO.      REGISTER NUMBER         INVIGILATOR\n");
  checkinvi(inv, t, fph1, Halls, sem);
  fprintf(fph1, "-----------------------------------------------------\n");
  rewind(fp1);
  rewind(fpd);
  if (sem == 2) {
    rewind(fpi);
  }
}

int main()

{
  FILE *fp;
  FILE *fph;
  fp = fopen("examtt.txt", "w+");
  fph = fopen("holidays.txt", "r+");
  FILE *fp1, *fpd, *fpi, *fph1;
  fp1 = fopen("halls.txt", "r+");
  fpd = fopen("dept.txt", "r+");
  fpi = fopen("invigilators.txt", "r+");
  fph1 = fopen("hallstt.txt", "w+");

  struct room halls[30];
  struct class classes[10];
  struct student students[60];
  struct hallAllocation Halls[30];
  struct Invigilator *inv;
  int nr, nc, ns, nh, i, j, k, jj, ii, t;

  char deptlist[6][10] = {"CSE  ", "IT   ", "ECE  ", "EEE  ", "CIVIL", "MECH "};
  struct course courses[8];
  struct schedule S[10];
  int N;
  int sem, dayIndex;
  char day[10];
  char courselist[20][10];
  struct date stdate;
  printf("Enter Startdate (dd-mm-yyyy): ");
  scanf("%d-%d-%d", &stdate.d, &stdate.m, &stdate.year);
  if (stdate.m == 2) {
    if (stdate.d > 29) {
      printf("Enter Proper Date\n");
      printf("Enter Startdate (dd-mm-yyyy): ");
      scanf("%d-%d-%d", &stdate.d, &stdate.m, &stdate.year);
    }
  }
  fscanf(fph, "%d\n", &N);
  
  struct date holidays[10];
  for (int j = 0; j < N; j++) {

    fscanf(fph, "%d-%d-%d\n", &holidays[j].d, &holidays[j].m,
           &holidays[j].year);
  }
  
  fprintf(fp, "\n");
  fprintf(fp, "\t\t\t\t\t\t\t\t\t\t\t\tEXAM TIME TABLE\n");
  fprintf(fp, "\n");
  fprintf(fp,
          "--------------------------------------------------------------------"
          "--------------------------------------------------------------------"
          "--------------------------------------\n");
  
  sem = 1;
  if (sem == 1) {
    FILE *fpc=fopen("course1.txt","r+");
    char cse[6][25],it[6][25],ece[6][25],eee[6][25],civil[6][25],mech[6][25];
    
    for(int i=0;i<6;i++){
      fscanf(fpc,"%[^\n]\n",cse[i]);
    }
    rewind(fpc);
    for(int i=0;i<6;i++){
      fscanf(fpc,"%[^\n]\n",it[i]);
    }
    rewind(fpc);
    for(int i=0;i<6;i++){
      fscanf(fpc,"%[^\n]\n",ece[i]);
    }
    rewind(fpc);
    for(int i=0;i<6;i++){
      fscanf(fpc,"%[^\n]\n",eee[i]);
    }
    rewind(fpc);
    for(int i=0;i<6;i++){
      fscanf(fpc,"%[^\n]\n",civil[i]);
    }
    rewind(fpc);
    for(int i=0;i<6;i++){
      fscanf(fpc,"%[^\n]\n",mech[i]);
    }

    scoreandsort(cse, it, ece, eee, civil, mech);
    stdate.d = holidaycheck(stdate, holidays, N);
    dayIndex = dayfind(stdate);
    prepareSchedule(stdate, courses, 6, S, dayIndex, holidays);
    fprintf(fp, "SEMESTER - %d\n", sem);
    printSchedule(deptlist, cse, it, ece, eee, civil, mech, S, sem, fp);
    fprintf(fp, "\n");
    printhalls(halls, fp1, classes, fpd, inv, fph1, Halls, fpi, sem, S);
  }

  sem = 2;
  if (sem == 2) {
    FILE *fpc=fopen("course2.txt","r+");
    char cse[6][25],it[6][25],ece[6][25],eee[6][25],civil[6][25],mech[6][25];
    
    for(int i=0;i<6;i++){
      fscanf(fpc,"%[^\n]\n",cse[i]);
    }
    for(int i=0;i<6;i++){
      fscanf(fpc,"%[^\n]\n",it[i]);
    }
    for(int i=0;i<6;i++){
      fscanf(fpc,"%[^\n]\n",ece[i]);
    }
    for(int i=0;i<6;i++){
      fscanf(fpc,"%[^\n]\n",eee[i]);
    }
    for(int i=0;i<6;i++){
      fscanf(fpc,"%[^\n]\n",civil[i]);
    }
    for(int i=0;i<6;i++){
      fscanf(fpc,"%[^\n]\n",mech[i]);
    }

    scoreandsort(cse, it, ece, eee, civil, mech);
    stdate.d = holidaycheck(stdate, holidays, N);
    dayIndex = dayfind(stdate);
    prepareSchedule(stdate, courses, 6, S, dayIndex, holidays);
    fprintf(fp, "SEMESTER - %d\n", sem);
    printSchedule(deptlist, cse, it, ece, eee, civil, mech, S, sem, fp);
    fprintf(fp, "\n");
    printhalls(halls, fp1, classes, fpd, inv, fph1, Halls, fpi, sem, S);
  }
  fprintf(fp,
          "--------------------------------------------------------------------"
          "--------------------------------------------------------------------"
          "--------------------------------------\n");
  sem = 3;
  if (sem == 3) {

    FILE *fpc=fopen("course3.txt","r+");
    char cse[6][25],it[6][25],ece[6][25],eee[6][25],civil[6][25],mech[6][25];
    
    for(int i=0;i<6;i++){
      fscanf(fpc,"%[^\n]\n",cse[i]);
    }
    for(int i=0;i<6;i++){
      fscanf(fpc,"%[^\n]\n",it[i]);
    }
    for(int i=0;i<6;i++){
      fscanf(fpc,"%[^\n]\n",ece[i]);
    }
    for(int i=0;i<6;i++){
      fscanf(fpc,"%[^\n]\n",eee[i]);
    }
    for(int i=0;i<6;i++){
      fscanf(fpc,"%[^\n]\n",civil[i]);
    }
    for(int i=0;i<6;i++){
      fscanf(fpc,"%[^\n]\n",mech[i]);
    }

    scoreandsort(cse, it, ece, eee, civil, mech);
    stdate.d = stdate.d + 1;
    stdate.d = holidaycheck(stdate, holidays, N);
    dayIndex = dayfind(stdate);
    prepareSchedule(stdate, courses, 6, S, dayIndex, holidays);
    fprintf(fp, "SEMESTER - %d\n", sem);
    printSchedule(deptlist, cse, it, ece, eee, civil, mech, S, sem, fp);
    fprintf(fp, "\n");
    printhalls(halls, fp1, classes, fpd, inv, fph1, Halls, fpi, sem, S);
  }

  sem = 4;
  if (sem == 4) {
    FILE *fpc=fopen("course4.txt","r+");
    char cse[6][25],it[6][25],ece[6][25],eee[6][25],civil[6][25],mech[6][25];
    
    for(int i=0;i<6;i++){
      fscanf(fpc,"%[^\n]\n",cse[i]);
    }
    for(int i=0;i<6;i++){
      fscanf(fpc,"%[^\n]\n",it[i]);
    }
    for(int i=0;i<6;i++){
      fscanf(fpc,"%[^\n]\n",ece[i]);
    }
    for(int i=0;i<6;i++){
      fscanf(fpc,"%[^\n]\n",eee[i]);
    }
    for(int i=0;i<6;i++){
      fscanf(fpc,"%[^\n]\n",civil[i]);
    }
    for(int i=0;i<6;i++){
      fscanf(fpc,"%[^\n]\n",mech[i]);
    }

    scoreandsort(cse, it, ece, eee, civil, mech);
    stdate.d = holidaycheck(stdate, holidays, N);
    dayIndex = dayfind(stdate);
    prepareSchedule(stdate, courses, 6, S, dayIndex, holidays);
    fprintf(fp, "SEMESTER - %d\n", sem);
    printSchedule(deptlist, cse, it, ece, eee, civil, mech, S, sem, fp);
    fprintf(fp, "\n");
    printhalls(halls, fp1, classes, fpd, inv, fph1, Halls, fpi, sem, S);
  }
  fprintf(fp,
          "--------------------------------------------------------------------"
          "--------------------------------------------------------------------"
          "--------------------------------------\n");
  fclose(fp);
  fclose(fph);
  printf("\nEXAM TIMETABLE CREATED.\n");
}