/* ||  STUDENTS' RECORDS AND DETAILS  ||
   || ------------------------------- ||
   ||		  MADE BY -           ||
   ||	         ----------           ||
   ||	         NITIN BABU           ||
   ||	        ------------          ||
   ||	       ROLL NO:-12122         ||
   ||	      CLASS:- XII - 'A'       ||
   ||_________________________________||

************************* HEADER FILES REQUIRED/USED *********************** */
#include<bits/stdc++.h>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<process.h>
#include<cstdlib>

using namespace std;
//**************************************************************************

//-----------------------------CLASS NAMED FILE-----------------------------

class file
{
  int roll;              //roll no of the student
  float age;             //age of the student
  int adm;               //admission of the student
  char gender[10];       //gender of the student
  char name[25];         //name of the student
  char categ[100];         //address of the student
  int cl;                //class of the student
  public:
  void input();          //function for input of details of a student
  void show();           //function for showing of details of a student
  char *getn()
  {                      //to to return name when found
  return name;
  }
}fileobj;               //object of the class FILE

//---------------------------- CLASS OVER ----------------------------------

//*************************** INPUT FUNCTION *******************************

void file ::input()
{
cout<<"\n Enter the  ADMISSION NUMBER of the student:- ";
cin>>adm;
cout<<"\n Enter the CLASS of the student:- ";
cin>>cl;
cout<<"\n Enter ROLL NUMBER .of the student:- ";
cin>>roll;
cout<<"\n Enter the NAME of the student:- ";
cin>>name;
cout<<"\n Enter the GENDER of the student:- ";
cin>>gender;
cout<<"\n Enter the AGE of the student:- ";
cin>>age;
cout<<"\n Enter the CATEGORY of the student:- ";
cin>>categ;
}

//************************ INPUT FUNCTION OVER *****************************

//-------------------------- OUTPUT FUNCTION -------------------------------

void file::show()
{
cout<<"\n ADMISSION NUMBER:- "<<adm;
cout<<"\n CLASS:- "<<cl;
cout<<"\n ROLL NUMBER:- "<<roll;
cout<<"\n NAME:- "<<name;
cout<<"\n GENDER:- "<<gender;
cout<<"\n AGE:- "<<age;
cout<<"\n CATEGORY:- "<<categ<<endl;
}

//------------------------ OUTPUT FUNCTION OVER ----------------------------

//**************** DECLARARTION OF FUNCTION PROTOTYPES *********************

void create();
void add();
void display() ;
void displayP();
void modify();
void Delete();
fstream fil;     //creating object of fstream

//************************* DECLARATION OVER *******************************

//-------------------- MAIN FUNCTION BODY/DEFINITION -----------------------

int main()
{
int opt;
while(1)   //loop for giving choices to user
{
system("cls");
cout<<"\n\t             WELCOME TO STUDENTS' RECORD DATABASE\n";
cout<<"\t             KENDRIYA VIDYALAYA AIR FORCE STATION\n";
cout<<"\t                        PUNE - 411032\n";
cout<<"1. Create new register and enter records"<<endl;
cout<<"2. Enter new records in opened register"<<endl;
cout<<"3. Display all students' records from register"<<endl;
cout<<"4. Display Particular Record from register"<<endl;
cout<<"5. Modify Particular Record from register"<<endl;
cout<<"6. Delete Particular Record from register"<<endl;
cout<<"7. Exit from the program"<<endl;
cout<<"\n Enter your choice"<<endl;

cin>>opt;   //user is entering his/her choice

switch(opt) //cases after selecting the choice
{
case 1:{
	create();
	cout<<"Display Main menu"<<endl;
	cin.get();
	break;
       }

case 2:{
	add();
	cout<<"Display main menu"<<endl;
	cin.get();
	break;
       }

case 3:{
	display();
	cout<<"Display main menu"<<endl;
	cin.get();
	break;
       }

case 4:{
	displayP();
	cout<<"Display main menu"<<endl;
	cin.get();
	break;
       }

case 5:{
	modify();
	cout<<"Display main menu"<<endl;
	cin.get();
	break;
       }

case 6:{
	Delete();
	cout<<"Display main menu"<<endl;
	cin.get();
	break;
       }

case 7:{
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n";
	cout<<"\t\t      \n";
	cout<<"\t\t       THANK YOU FOR USING OUR PROGRAM \n";
	cout<<"\t\t       PRESS ENTER TO EXIT THE PROGRAM \n";
	cout<<"\t\t      \n";
	cin.get();
	exit(0);
       }

default:{
	 cout<<"Worng choice!!!!!";
	 cin.get();
	 system("cls");
	}
} //closing switch case
} //closing while loop
} //closing main

//------------------------- MAIN FUNCTION OVER -----------------------------

//******************** FUNCTION FOR CREATING DATABASE **********************

void create()
{
 char ch='y';
 fil.open("c:\\binary.dat",ios::out|ios::binary);
 while(ch=='y'||ch=='Y')
 {
  fileobj.input();
  fil.write((char*)&fileobj, sizeof(fileobj));
  cout<<"Do you want to Continue....";
  cin>>ch;
 }
 fil.close();
}

//************************ CREATE FUNCTION OVER ****************************

//-------------------- FUNCTION FOR ADDING NEW RECORDS ---------------------

void add()
{
char ch='y';
fil.open("c:\\binary.dat",ios::app|ios::binary);
while(ch=='y'||ch=='Y')
 {
 fileobj.input();
 fil.write((char*)&fileobj, sizeof(fileobj));
 cout<<"Do you want to Continue....";
 cin>>ch;
 }
 fil.close();
}

//---------------------- ADDITION OF RECORDS OVER --------------------------

//******************** FUNCTION TO DISPLAY ALL RECORDS *********************

void display()
{
fil.open("c:\\binary.dat",ios::in|ios::binary);
if(!fil)
{
cout<<"File not found";
exit(0);
}
else
{
fil.read((char *)&fileobj,sizeof(fileobj));
while(!fil.eof())
{
fileobj.show();
cout<<"Press any key  for next Record"<<endl;
cin.get();
fil.read((char*)&fileobj,sizeof(fileobj));
}
}
fil.close();
}

//************************* DISPLAY FUNCTION OVER **************************

//---------------- FUNTION TO DISPLAY A PARTICULAR RECORD ------------------

void displayP()
{
 char n[100];
 cout<<"Enter Name that should be searched:";
 cin>>n;
 fil.open("c:\\binary.dat",ios::in|ios::binary);
 if(!fil)
 {
  cout<<"File not Found";
  exit(0);
 }
 else
 {
 fil.read((char *)&fileobj,sizeof(fileobj));
 while(!fil.eof())
 {
 if(strcmp(n,fileobj.getn())==0)
 {
 fileobj.show();
 cout<<"Press any key ...."<<endl;
 cin.get();
 }
 else
 {
 cout<<"Press any key...for search"<<endl;
 cin.get();
 }
 fil.read((char *)&fileobj,sizeof(fileobj));
 }
 }
 fil.close();
}

//---------------- PARTICULAR RECORD DISPLAY FUNCTION OVER -----------------

//***************** FUNTION TO MODIFY A PARTICULAR RECORD ******************

void modify()
{
 char n[100];
 cout<<"Enter Name that should be searched:";
 cin>>n;
 fil.open("c:\\binary.dat",ios::in|ios::out|ios::binary);
 if(!fil)
 {
  cout<<"File not Found";
  exit(0);
 }
 else
 {
 fil.read((char *)&fileobj,sizeof(fileobj));
 while(!fil.eof())
 {
 if(strcmp(n,fileobj.getn())==0)
 {
 fil.seekg(0,ios::cur);
 cout<<"Enter new record.."<<endl;
 fileobj.input();
 fil.seekp(fil.tellg()-sizeof(fileobj));
 fil.write((char *)&fileobj,sizeof(fileobj));
}
else
{
cout<<"Press any key .. for search"<<endl;
cin.get();
}
fil.read((char *)&fileobj,sizeof(fileobj));
}
}
fil.close();
}

//************* PARTICULAR RECORD MODIFICATION FUNCTION OVER ***************

//----------------- FUNTION TO DELETE A PARTICULAR RECORD ------------------

void Delete()
{
 char n[100];
 cout<<"Enter Name that should be Deleted:";
 cin>>n;
 ofstream o;
 ifstream fil;
 o.open("c:\\new.dat",ios::out|ios::binary);
 fil.open("c:\\binary.dat",ios::in|ios::binary);
 if(!fil)
 {
  cout<<"File not Found";
  exit(0);
 }
 else
 {
 fil.read((char *)&fileobj,sizeof(fileobj));
 while(!fil.eof())
 {
 if(strcmp(n,fileobj.getn())!=0)
 {
 o.write((char *)&fileobj,sizeof(fileobj));
 }
 else
{
cout<<"Press any key .. for search"<<endl;
cin.get();
}
fil.read((char *)&fileobj,sizeof(fileobj));
}
}
fil.close();
o.close();
remove("c:\\binary.dat") ;
rename("c:\\new.dat","c:\\binary.dat");
cin.get();
}

//***************** PARTICULAR RECORD DELETION FUNCTION OVER ***************
