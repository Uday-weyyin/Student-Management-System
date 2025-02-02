
#include<stdio.h>
#include<string.h>

void addstudent();
void editstudent();
void deletestudent();
void searchstudent();
void displaylistofstudent();

int rollnumber[100];
char name[100][21];
int numberofstudentadded;

int main()
{
int ch;
numberofstudentadded=0;
while(1)
{
printf("1. Add Student\n");
printf("2. Edit Student\n");
printf("3. Delete Student\n");
printf("4. Search Student\n");
printf("5. Display List of Student\n");
printf("6. exit\n");
printf("Enter your choice(1-6) : ");
scanf("%d",&ch);
fflush(stdin);
if(ch<1||ch>6)
{
printf("Invalid choice,select(1-6)\n");
continue;
}
if(ch==1&&numberofstudentadded==100)
{
printf("You cannot add more than 100 students\n");
continue;
}
if(ch>=2&&ch<=5&&numberofstudentadded==0)
{
printf("You have not added a single student\n");
continue;
}
if(ch==1)addstudent();
if(ch==2)editstudent();
if(ch==3)deletestudent();
if(ch==4)searchstudent();
if(ch==5)displaylistofstudent();
if(ch==6)break;
}
return 0;
}

void addstudent()
{
int vrollnumber;
char vname[22];
char e,m;
printf("Student (Add module)\n");
printf("Enter roll number : ");
scanf("%d",&vrollnumber);
fflush(stdin);
if(vrollnumber<=0)
{
printf("invalid roll number\n");
return;
}
e=0;
while(e<numberofstudentadded)
{
if(vrollnumber==rollnumber[e])
{
printf("That roll number alloted to %s\n",name[e]);
return;
}
e++;
}
printf("Enter name : ");
fgets(vname,22,stdin);
fflush(stdin);
vname[strlen(vname)-1]='\0';
printf("save(y/n): ");
m=getchar();
fflush(stdin);
if(m!='y'&&m!='y')
{
printf("Student not added\n");
return;
}
rollnumber[numberofstudentadded]=vrollnumber;
strcpy(name[numberofstudentadded],vname);
numberofstudentadded++;
printf("student added, press enter to continue..\n");
getchar();
fflush(stdin);
}


voideditstudent()
{
int vrollnumber;
char vname[22];
char m;
int e,found;
printf("student(edit module)\n");
printf("Enter roll number of the student to edit : ");
scanf("%d",&vrollnumber);
fflush(stdin);
if(vrollnumber<=0)
{
printf("Invalid roll number\n");
return;
}
found=0;
e=0;
while(e<numberofstudentadded)
{
if(vrollnumber==rollnumber[e])
{
found=1;
break;
}
e++;
}
if(found==0)
{
printf("Invalid roll number\n");
return;
}
printf("Name : %s\n",name[e]);
printf("edit(Y/N) : ");
m=getchar()
fflush(stdin);
if(m!='Y'&&m!='y')
{
printf("Student not edited\n");
return;
}
printf("Student not edited\n");
return;
}
printf("Enter new name : ");
fgets(vname,22,stdin);
fflush(stdin);
vname[strlen(vname)-1]='\0';
printf("update(Y/N) : ");
m=getchar();
fflush(stdin);
if(m!='y'&&m!='y')
{
printf("Student not updated\n");
return;
}
strcpy(name[e],vname);
printf("Student updated, press enter to continue...");
getchar();
fflush(stdin);
}

void deletestudent()
{
int vrollnumber;
int e,found,ep;
char m;
printf("Student(Delete module)\n");
printf("Enter roll number of the student to delete : ");
scanf("%d",&vrollnumber);
fflush(stdin);
if(vrollnumber<=0)
{
printf("Invalid roll number\n");
return;
}
found=0;
e=0;
while(e<numberofstudentadded)
{
if(vrollnumber==rollnumber[e])
{
found=1;
break;
}
e++;
}
if(found==0)
{
printf("Invalid roll number\n");
return;
}
printf("Name:%s\n"n,name[e]);
printf("Delete(Y/N): ");
m=getchar();
fflush(stdin);
if(m!='y'&&m!='y')
{
printf("student not deleted\n");
return;
}
ep=numberofstudentadded-2;
while(e<=ep)
{
rollnumber[e]=rollnumber[e+1];
strcpy(name[e],name[e+1]);
e++;
}
numberofstudentadded--;
printf("Student deleted, press enter to continue...");
getchar();
fflush(stdin);
}


