//Source code by Fatina Maisara Izamuddin 

#include<iostream> //This header file contains definitions to objects like cin, cout etc.
#include<iomanip> //This file contains definitions of setw.
#include<conio.h> //This file contains definitions of getch()
#include<fstream> /*This header file is used to handle the data being read from a file as input  
                    or data being written into the file as output.*/

using namespace std;

struct Covid19		//A structure representing a record in a Covid19 patient system
{
	string fname, lname;				//Data elements in the stucture
	int age, dayin, monthin, yearin;
	char gender;
	string icNo;
};

void mainmenu ();                                   //to display the main menu
void writeFile(Covid19 p[]);						//to register patient details
void readfile (ifstream& patientfile, Covid19 p[]); //to check patient records
void beds (Covid19 p[]);							//to check segmentation bedding
void date (int day, int month, int year);			//to check discharge date

int main()		//Start of main program
{
struct Covid19 p[3];		//Array of patients
	mainmenu();
	ifstream patientfile;   //Represents the input file stream and to read information from files
	patientfile.open("PatientDetails.txt"); 
	return 0;
}		//End of main program

void mainmenu()		//For displaying main menu
{
	struct Covid19 p[3];
	int day, month, year;
	int choice;
	ifstream patientfile;

while(choice!=5)	//while-loop for choosing choice
{
system("cls");
cout<<"\n\t\t\t\t************************************************************";
cout<<"\n\t\t\t\t SEGMENT COVID-19 PATIENT BEDDING IN QUARANTINE HALL SYSTEM ";
cout<<"\n\t\t\t\t 			 * MAIN MENU *			 		   	";
cout<<"\n\t\t\t\t************************************************************";
cout<<"\n\n\n\t\t\t1.Patient Registration";
cout<<"\n\t\t\t2.Patient Records";
cout<<"\n\t\t\t3.Check segmentation bedding";
cout<<"\n\t\t\t4.Check Discharge Date";
cout<<"\n\t\t\t5.Exit";
cout<<"\n\n\t\t\tEnter Your Choice: ";

cin>>choice;
if (choice==1)
{
	writeFile (p);
}else if (choice==2)
{
	readfile (patientfile, p);
}else if (choice==3)
{
	beds (p);
}else if (choice==4)
{
	date (day, month, year);
}
else if (choice==5){
	break;
}
else{
	cout<<"\n\n\t\t\tWrong choice...";
	cout<<"\n\t\t\tPress any key to continue...";
	getch();	//This function is used to pause the final output 
}}}			//End of menu function

void writeFile(Covid19 p[])		//function for register patient details
{
system("cls");
ofstream patientfile;		//Represents the output file stream and to write information to files.
patientfile.open("PatientDetails.txt");		//function 'open()' defines the file should be opened
cout<<"\n\t\t\t\t * Patient Registration *			 		   	";
for (int i = 0; i <3; i++)		//for-loop for number of patients
{
	cout << "\nEnter your first name: ";
	cin >> p[i].fname;
	cout << "Enter your last name: ";
	cin >> p[i].lname;
	cout << "Enter your gender: ";
	cin >> p[i].gender;
	cout << "Enter your age: ";
	cin >> p[i].age; 
	cout << "Enter your ic number: ";
	cin >> p[i].icNo;
	patientfile << p[i].fname <<" "<< p[i].lname <<"\t"<< p[i].gender //information written in file
				<<"\t" << p[i].age <<"\t"<< p[i].icNo<<endl;		  //on this order.
}
	getch();	
}		//End of register patient details

void readfile (ifstream& patientfile, Covid19 p[])		//function for patient records
{
	system("cls");
	cout<<"\n\t\t\t\t * Patient Records *			 		   	\n";
	cout<<"\n"<<setw(20)<<"Name\t\t"		//setw() is to set the field width in output operations
		<<right<<setw(10)<<"Gender"
		<<right<<setw(8)<<"Age"
		<<right<<"\tIC Number\n";
	
	for (int i = 0; i <3; i++)
	{
		patientfile >> p[i].fname >> p[i].lname >> p[i].gender >> p[i].age >> p[i].icNo;
		cout <<(i+1)<<". "<< p[i].fname <<" "<<left<<setw(19)<< p[i].lname 
		     <<right<<"\t\t"<< p[i].gender 
		     <<right<<"\t"<< p[i].age 
			 <<right<<"\t"<< p[i].icNo << endl;
	}
	patientfile.close();	//function 'close()' to close all-open files
	cin.ignore();
	getch();
}		//End of patient records

void beds(Covid19 p[])		//function for segmentation bedding
{
	system("cls");		//clear output screen
	cout<<"\n\t\t\t\t * Check Segmentation Bedding *			 		   	";
	int bednum1=1, bednum2=31, bednum3=61, bednum4=91;
	int bednum5=121, bednum6=151, bednum7=181, bednum8=211;
	int bednum;
	for (int i = 0; i<3; i++){
	if(p[i].gender=='M')		//control structure if-else for gender
	{
		if(p[i].age>=60){		//if-else for age
			bednum=bednum1;		
			cout << "\nName: "<< p[i].fname <<" "<< p[i].lname 
			     <<"\nGender: "<< p[i].gender 
				 <<"\nAge: "<< p[i].age
			     << "\nYour bed number is " << bednum << endl;
			bednum1=bednum+1;	//calculate bednum
		}
		else if(p[i].age>=19 && p[i].age<=59){
			bednum=bednum2;
			cout << "\nName: "<< p[i].fname <<" "<< p[i].lname 
			     <<"\nGender: "<< p[i].gender 
				 <<"\nAge: "<< p[i].age
			     << "\nYour bed number is " << bednum << endl;
			bednum2=bednum+1;
		}
		else if(p[i].age>=13 && p[i].age<=18){
			bednum=bednum3;
			cout << "\nName: "<< p[i].fname <<" "<< p[i].lname 
			     <<"\nGender: "<< p[i].gender 
				 <<"\nAge: "<< p[i].age
			     << "\nYour bed number is " << bednum << endl;
			bednum3=bednum+1;
		}
		else{
			bednum=bednum4;
			cout << "\nName: "<< p[i].fname <<" "<< p[i].lname 
			     <<"\nGender: "<< p[i].gender 
				 <<"\nAge: "<< p[i].age
			     << "\nYour bed number is " << bednum << endl;
			bednum4=bednum+1;
		}
	}
	else if(p[i].gender=='F'){
		if(p[i].age>=60){
			bednum=bednum5;
			cout << "\nName: "<< p[i].fname <<" "<< p[i].lname 
			     <<"\nGender: "<< p[i].gender 
				 <<"\nAge: "<< p[i].age
			     << "\nYour bed number is " << bednum << endl;
			bednum5=bednum+1;
		}
		else if(p[i].age>=19 && p[i].age<=59){
			bednum=bednum6;
			cout << "\nName: "<< p[i].fname <<" "<< p[i].lname 
			     <<"\nGender: "<< p[i].gender 
				 <<"\nAge: "<< p[i].age
			     << "\nYour bed number is " << bednum << endl;
			bednum6=bednum+1;
		}
		else if(p[i].age>=13 && p[i].age<=18){
			bednum=bednum7;
			cout << "\nName: "<< p[i].fname <<" "<< p[i].lname 
			     <<"\nGender: "<< p[i].gender 
				 <<"\nAge: "<< p[i].age
			     << "\nYour bed number is " << bednum << endl;
			bednum7=bednum+1;
		}
		else{
			bednum=bednum8;
			cout << "\nName: "<< p[i].fname <<" "<< p[i].lname 
			     <<"\nGender: "<< p[i].gender 
				 <<"\nAge: "<< p[i].age
			     << "\nYour bed number is " << bednum << endl;
			bednum8=bednum+1;
		}
	}
	else
	cout<<"\nInvalid code";
	getch();
}
}		//End of segmentation bedding

void date (int d, int m, int y)		//function for discharge date
{
	system("cls");
	cout<<"\n\t\t\t\t * Check Discharge Date *			 		   	";
	int dayin, monthin, yearin;
		
		cout << "\nEnter Admission Date (dd mm yy): ";
		cin >> dayin >> monthin >> yearin;
		cout << endl;
		cout << "Admission Date: " << dayin << "/" << monthin << "/" << yearin << endl;
		cout << "Discharge Date: ";
		
		if (monthin==1 || monthin==3 || monthin==5 || monthin==7 || monthin==8 ||
		monthin==10 || monthin==12) //declare monthin==i for january, march, may, july, august, 
									//october, december 
		{
			d=dayin+14;
			if (d>=31)
			{
				d=d-31;
				m=monthin+1;
				if (m>12)
				{
					m=m-12;
					y=yearin+1;
					cout << d << "/" << m << "/" << y << endl;
				}
				else { cout << d << "/" << m << "/" << yearin << endl; }
			}
			else { cout << d << "/" << monthin << "/" << yearin << endl; }
			cout << endl;
		}
		
		else if (monthin==4 || monthin==6 || monthin==9 || monthin==11)
		{		//declare monthin==i for april, june, september, november
			d=dayin+14;
			if (d>=30)
			{
				d=d-30;
				m=monthin+1;
				if (m>12)
				{
					m=m-12;
					y=yearin+1;
					cout << d << "/" << m << "/" << y << endl;
				}
				else { cout << d << "/" << m << "/" << yearin << endl; }
			}
			else { cout << d << "/" << monthin << "/" << yearin << endl; }
			cout << endl;
		}
		
		else if (monthin==2) //declare monthin==2 as february
		{
			d=dayin+14;
			if (d>=28)
			{
				d=d-28;
				m=monthin+1;
				if (m>12)
				{
					m=m-12;
					y=yearin+1;
					cout << d << "/" << m << "/" << y << endl;
				}
				else { cout << d << "/" << m << "/" << yearin << endl; }
			}
			else { cout << d << "/" << monthin << "/" << yearin << endl; }
			cout << endl;
		}
		
		else { cout << "invalid" << endl;}
	
	getch();
}		//End of discharge date



