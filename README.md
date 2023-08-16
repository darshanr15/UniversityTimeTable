# UniversityTimeTable
Efficiently generates clash-free university exam timetables by optimizing scheduling.

__________________________

EXAM TIME TABLE GENERATOR
__________________________

CONTRIBUTORS: R.DARSHAN
      	      V.A.BALAJI

___________________________

EXAM TIME TABLE PROBLEM

STATEMENT:
The time table creation is a tedious process, since so many constraints to be considered before make
it. There is a need for an automatic system. To create a exam schedule for University examination for an
academic institution by considering possible constraints.

____________________________________________________________________________________________________________________________________________

The input data files are : 
 
dept.txt         (Containing department code and No. of students per department)
halls.txt	     (Containing Hall No. and Capacity per hall)
holidays.txt     (Containing No. of holidays and holidates in dd-mm-yyyy format)
invigilators.txt (Containing Name of Invigilators and Availability status as 1 or 0)
course1.txt      (Containing Courses of every department for Semester 1)
course2.txt      (Containing Courses of every department for Semester 2)
course3.txt      (Containing Courses of every department for Semester 3)
course4.txt      (Containing Courses of every department for Semester 4)

The output is created in two files:

examtt.txt       (Containing Exam Time Table for each Semester and all departments with the dates)
hallstt.txt      (Containing Hall Allocated for the Students with Invigilator Alloted)

____________________________________________________________________________________________________________________________________________

STEPS TO CREATE A TIME TABLE:

1 - The C executable file of this project is found in the Folder.
3 - The Input Data Files to be imported are found in the INPUT DATA Folder.
4 - After Importing the input Data Files now the exe file can be run.
5 - When the file is run, It asks for a start date as an Input from the user.
6 - After a date is given, THE EXAM TIME TABLE along with THE HALL INVIGILATOR ALLOCATION is created in two files in the same directory. 

____________________________________________________________________________________________________________________________________________

OPERATION OF THE EXE FILE:

SAMPLE CASE:

Enter Startdate (dd-mm-yyyy): 21-03-2022

EXAM TIMETABLE CREATED.


file examtt.txt


												EXAM TIME TABLE

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
SEMESTER - 1
FORENOON

DEPT.        21-3-2022                  26-3-2022                  31-3-2022                  4-4-2022                  8-4-2022                  14-4-2022           
CSE    Algebra and Calculus       Communicative English      Programming in Python      Engineering Chemistry      Engineering Physics        Engineering Graphics     
IT     Algebra and Calculus       Communicative English      Programming in Python      Engineering Chemistry      Engineering Physics        Engineering Graphics     
ECE    Algebra and Calculus       Communicative English      Programming in Python      Engineering Chemistry      Engineering Physics        Engineering Graphics     
EEE    Algebra and Calculus       Communicative English      Programming in Python      Engineering Chemistry      Engineering Physics        Engineering Graphics     
CIVIL  Algebra and Calculus       Communicative English      Programming in Python      Engineering Chemistry      Engineering Physics        Engineering Graphics     
MECH   Algebra and Calculus       Communicative English      Programming in Python      Engineering Chemistry      Engineering Physics        Engineering Graphics     

SEMESTER - 2
AFTERNOON

DEPT.        21-3-2022                  26-3-2022                  31-3-2022                  4-4-2022                  8-4-2022                  14-4-2022           
CSE    Laplace Transforms          Environmental Science      Basic E&E Engineering      Electives              Programming in C            Data Science             
IT     Laplace Transforms          Environmental Science      Basic E&E Engineering      Electives              Information Science         Data Structures          
ECE    Laplace Transforms          Environmental Science      Basic E&E Engineering      Electives              Circuit Analysis            Electronic Devices       
EEE    Laplace Transforms          Environmental Science      Basic E&E Engineering      Electives              Engineering Mechanics       Electrical Circuits      
CIVIL  Laplace Transforms          Environmental Science      Basic E&E Engineering      Electives              Civil Eng Fundamental       Engineering Mechanics    
MECH   Laplace Transforms          Environmental Science      Basic E&E Engineering      Electives              Mech Eng Fundamental        Engineering Mechanics    

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
SEMESTER - 3
FORENOON

DEPT.        22-3-2022                  28-3-2022                  2-4-2022                  6-4-2022                  11-4-2022                  18-4-2022           
CSE    Discrete Mathematics       Digital Principles         Data Structures            UNIX & Shell Programs      Communications              Object Oriented Program  
IT     Discrete Mathematics       Digital Electronics        C Programming              Digital Communication      Database Management        Computer Organization    
ECE    Linear Algebra             Electronic Circuits I      Digital System Design      Signals and Systems        Data Structures            Electromagnetic Fields   
EEE    Transform Techniques       Electrical Machines I      Electromagnetic Theory     Object Oriented Program    Electronic Devices          Modern Power Plant       
CIVIL  Transform Techniques       Structural Analysis        Steel Structures           Transportation             Wastewater Engineering     Ground Improvement       
MECH   Transform Techniques       Fluid Mechanics            Kinematics Machinery       Thermal Engineering        Engineering Metallurgy     Dynamics of Machines     

SEMESTER - 4
AFTERNOON

DEPT.        22-3-2022                  28-3-2022                  2-4-2022                  6-4-2022                  11-4-2022                  18-4-2022           
CSE    Probility                   Computer Architecture      Operating Systems           Design Algorithms          Database Management         Software Engineering      
IT     Probility                   Software Engineering       Information Theory          Microprocessors            Advanced Data Structure     Algorithm Designing      
ECE    Probility                   Basic E & I Engineering    Electronic Circuits II      Signal Processing          Integrated Circuits         Communication Systems    
EEE    Numerical methods           Electrical Machines II     Transmissions               Control Systems            Digital logic System        Analog Electronics       
CIVIL  Numerical methods           Mechanics of solids II     Hydraulic Engineering       Geotechnology I            Construction practices      Concrete Technology      
MECH   Statistic and Numerical     Mechanical operations      Chemical Processeses        Heat Transfer              Thermodynamics I            Environmental Science    

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


file hallstt.txt



SEMESTER - 1
FORENOON ( 9.00 AM - 12.15 PM )
DATES:  21-3-2022  26-3-2022  31-3-2022  4-4-2022  8-4-2022  14-4-2022 
-----------------------------------------------------
HALL NO.      REGISTER NUMBER           INVIGILATOR
  101	     3122 21 1000 To 1029	         Edna
  102	     3122 21 1030 To 1059	         Abbot
  103	     3122 21 2000 To 2029	         Bryant
  104	     3122 21 2030 To 2059	         Connor
  105	     3122 21 3000 To 3029	         Nakul
  106	     3122 21 3030 To 3059	         Orman
  201	     3122 21 4000 To 4029	         Sabhya
  202	     3122 21 4030 To 4059	         Taraksh
  203	     3122 21 5000 To 5029	         Xander
  204	     3122 21 5030 To 5059	         Milo
  205	     3122 21 6000 To 6029	         Aaron
  206	     3122 21 6030 To 6059	         Jade
-----------------------------------------------------

SEMESTER - 2
AFTERNOON ( 1.00 PM - 4.15 PM )
DATES:  21-3-2022  26-3-2022  31-3-2022  4-4-2022  8-4-2022  14-4-2022 
-----------------------------------------------------
HALL NO.      REGISTER NUMBER           INVIGILATOR
  101	     3122 20 1000 To 1029	         Leah
  102	     3122 20 1030 To 1059	         Dean
  103	     3122 20 2000 To 2029	         Isaac
  104	     3122 20 2030 To 2059	         Xavier
  105	     3122 20 3000 To 3029	         Austin
  106	     3122 20 3030 To 3059	         Silas
  201	     3122 20 4000 To 4029	         Oscar
  202	     3122 20 4030 To 4059	         Miles
  203	     3122 20 5000 To 5029	         Archer
  204	     3122 20 5030 To 5059	         Beckett
  205	     3122 20 6000 To 6029	         Ryder
  206	     3122 20 6030 To 6059	         Zane
-----------------------------------------------------

SEMESTER - 3
FORENOON ( 9.00 AM - 12.15 PM )
DATES:  22-3-2022  28-3-2022  2-4-2022  6-4-2022  11-4-2022  18-4-2022 
-----------------------------------------------------
HALL NO.      REGISTER NUMBER           INVIGILATOR
  101	     3122 19 1000 To 1029	         Edna
  102	     3122 19 1030 To 1059	         Abbot
  103	     3122 19 2000 To 2029	         Bryant
  104	     3122 19 2030 To 2059	         Connor
  105	     3122 19 3000 To 3029	         Nakul
  106	     3122 19 3030 To 3059	         Orman
  201	     3122 19 4000 To 4029	         Sabhya
  202	     3122 19 4030 To 4059	         Taraksh
  203	     3122 19 5000 To 5029	         Xander
  204	     3122 19 5030 To 5059	         Tavish
  205	     3122 19 6000 To 6029	         Milo
  206	     3122 19 6030 To 6059	         Aaron
-----------------------------------------------------

SEMESTER - 4
AFTERNOON ( 1.00 PM - 4.15 PM )
DATES:  22-3-2022  28-3-2022  2-4-2022  6-4-2022  11-4-2022  18-4-2022 
-----------------------------------------------------
HALL NO.      REGISTER NUMBER           INVIGILATOR
  101	     3122 18 1000 To 1029	         Jade
  102	     3122 18 1030 To 1059	         Ivy
  103	     3122 18 2000 To 2029	         Jasmi
  104	     3122 18 2030 To 2059	         Leah
  105	     3122 18 3000 To 3029	         Megan
  106	     3122 18 3030 To 3059	         Dean
  201	     3122 18 4000 To 4029	         Isaac
  202	     3122 18 4030 To 4059	         Joel
  203	     3122 18 5000 To 5029	         Miller
  204	     3122 18 5030 To 5059	         Santiago
  205	     3122 18 6000 To 6029	         Xavier
  206	     3122 18 6030 To 6059	         Austin
-----------------------------------------------------


The above two files are created in the same directory of the exe file.

____________________________________________________________________________________________________________________________________________


<<There is nothing impossible to they who will try>>
WISHES!!
