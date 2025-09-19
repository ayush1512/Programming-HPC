class Student:

    SchoolName="CDAC"       #Class Level Variable

    #This method is constructor of the class
    def __init__(self, Name, RollNo):
        self.RollNo=RollNo
        self.Name=Name

    def Fun1(self):
        print("Hello Am Fun1")

    def Fun2(self):
        print("Hello Am Fun2")

    def PrintData(self):
        print("Name: ",self.Name," Roll No: ", self.RollNo)

    def __str__(self):
        return f"Name: {self.Name} Roll No: {self.RollNo} School Name: {self.SchoolName}"

#Student Manager class to manage the student list
class StudentManager:

    def __init__(self):
        self.students=[]    #here students is the empty list
    
    def AddStudent(self, student):
        self.students.append(student)
        print("Student Added Successfully")

    def ViewStudents(self):
        for stu in self.students:
            print(stu)

    def SortByName(self):
        self.students.sort(key=lambda s: s.Name)
        self.ViewStudents()

    def SortByRollNo(self):
        self.students.sort(key=lambda s: s.RollNo)
        self.ViewStudents()

    def FilterByNameStartsWith(self, nsw):
        filteredStudents=filter(self.students, key=lambda s: s.Name.startswith(nsw))
        return filteredStudents

sm=StudentManager()5
choice=0
while(choice!=6):
    print("-------Student Adminstration----------")
    print("Press 1 to add the student")
    print("Press 2 to view the student")
    print("Press 3 to Sort Record by Name")
    print("Press 4 to Sort Record By Roll No")
    print("Press 5 to Filter Records by Name Starts with ...")
    print("Press 6 to Exit")
    print("---------------------------")
    choice=int(input("Enter Your Choice: "))
    if(choice==1):
        sname=input("Enter Name: ")
        srollno=int(input("Enter Roll No: "))
        s=Student(sname, srollno)
        sm.AddStudent(s)
    elif(choice==2):
        sm.ViewStudents()
    elif(choice==3):
        sm.SortByName()
    elif(choice==4):
        sm.SortByRollNo()
    elif(choice==5):
        list=sm.FilterByNameStartsWith("Ab")
        for s in list:
            print(s)
    elif(choice==6):
        print("Exiting the Program: ")
    else:
        print("Wrong Choice: ")