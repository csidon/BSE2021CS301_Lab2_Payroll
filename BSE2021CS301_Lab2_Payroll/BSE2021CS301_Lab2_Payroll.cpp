#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Employees {
	string firstName, middleName, lastName, streetAdd, suburb, city, emailAdd;
	int id, contactNum, irdNum, taxCode; 
	float hoursWorked, hourlyRate, grossWkPay, taxRate, taxDeduct, netWkPay;

	//constructor (to help computer allocate space to struct)
	Employees(string fN = "", string mN = "", string lN = "", string sA = "", string s = "", string c = "", string eA = "", int i = 000, int cN = 0, int ird = 0, int t = 0, float hW = 0.0, float hR = 0.0, float gWp = 0.0, float tR = 0.0, float tD = 0.0, float nWp = 0.0)
	{
		//static values
		firstName = fN;
		middleName = mN;
		lastName = lN;
		streetAdd = sA;
		suburb = s;
		city = c;
		emailAdd = eA;
		contactNum = cN;
		id = i;
		irdNum = ird;
		taxCode = t;
		hourlyRate = hR;

		//input (changing) values
		hoursWorked = hW;
		//calculated values
		grossWkPay = gWp;
		taxRate = tR;
		taxDeduct = tD;
		netWkPay = nWp;
	}

};

//function prototype
struct Employees* inputValue(struct Employees* p);
struct Employees* outputValue(struct Employees* p);
void line(int lineLen);
void whatWeek();


int main() 
{
	//Defining a variable "details" in Struct Employees 
	int numRecords;

	Employees record[3];
	Employees* empPtr;
	empPtr = record; //creating a pointer for the array set "record"
	numRecords = sizeof(empPtr);
	cout << "size of employee records is " << numRecords;

	
	
	//fstream recordsIOfile;
	//recordsIOfile.open("C:/Users/Chris/Desktop/Yoobee/CS103_Oct21/BSE2021CS301_Lab2_Payroll/payroll.csv", ios::app);
	//for (int i = 0; i < numRecords; i++)
	//{
	//	enterRecords(recordsIOfile);
	//}


	line(50);
	whatWeek();
	line(50);

	inputValue(empPtr);

	line(50);
	outputValue(empPtr);


}

void line(int lineLen)
{
	for (int i = 0; i < lineLen; i++)
	{
		cout << "-";
	}
}

//void enterRecords(fileRecords)
//{
//	
//
//}

void whatWeek()
{
	string startDate, endDate;
	cout << "\nEnter Week Start Date [DD/MM/YY]:\t";
	getline(cin, startDate);
	cout << "\nEnter Week End Date [DD/MM/YY]:\t\t";
	getline(cin, endDate);
}

//void whatWeek()
//{
//	string startDate, endDate;
//	cout << "\nEnter Week Start Date [DD/MM/YY]:\t";
//	getline(cin, startDate);
//	cout << "\nEnter Week End Date [DD/MM/YY]:\t\t";
//	getline(cin, endDate);
//}

//Creating a function that takes inputs pointing to the variables within Employees struct
struct Employees* inputValue(struct Employees* p)
{
	cout << "\nEnter Employee ID:\t";
	cin >> p->id;			//#############!!!!!!!!!!!!!!!### Ask Beula why it skips in console
	cout << "Enter First Name:\t";
	getline(cin, p->firstName);
	cout << "Enter Middle Initials:\t";
	getline(cin, p->middleName);
	cout << "Enter Last Name:\t";
	getline(cin, p->lastName);
	cout << "Enter Street Address:\t";
	getline(cin, p->streetAdd);
	cout << "Enter Suburb:\t\t";
	getline(cin, p->suburb);
	cout << "Enter City:\t\t";
	getline(cin, p->city);
	cout << "Enter Contact Number:\t";
	cin >> p->contactNum;
	cout << "Enter Email Address:\t";
	getline(cin, p->emailAdd);
	cout << "Enter IRD number:\t";
	cin >> p->irdNum;
	cout << "Enter Tax Code:\t\t";
	cin >> p->taxCode;
	cout << "Enter Hours Worked:\t";
	cin >> p->hoursWorked;
	cout << "Enter Hourly Rate:\t";
	cin >> p->hourlyRate;
	cout << "Enter Tax Rate:\t\t";
	cin >> p->taxRate;

	return(p);
}

//Creating a function that takes outputs pointing to the variables within Employees struct
struct Employees* outputValue(struct Employees* p)
{
	cout << "\nEmployee ID:\t" << p->id;
	cout << "\nFull Name:\t"<< p->firstName << " " << p->middleName << " " << p->lastName;
	cout << "\nAddress:\t" << p->streetAdd;
	cout << "\nContact Number:\t" << p->contactNum;
	cout << "\nEmail Address:\t" << p->emailAdd;
	return(p);
}