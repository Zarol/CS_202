#include "Project12Classes.h"

//PERSON CLASS!
Person::Person(const char* firstName, const char* lastName, int age, int* ssn)
{
//	cout << "##INSIDE PERSON CONSTRUCTOR##" << endl;
	this->firstName = new char[strlen(firstName)];
	strcpy(this->firstName, firstName);
	this->lastName = new char[strlen(lastName)];
	strcpy(this->lastName, lastName);
	this->age = age;
	this->ssn = new int[9];
	if(ssn != NULL)
		for(int i = 0; i < 9; i++)
			this->ssn[i] = ssn[i];
}

Person::~Person()
{
//	cout << "##INSIDE PERSON DESTRUCTOR##" << endl;
	if(firstName != NULL)
		delete[] firstName;
	firstName = NULL;
	if(lastName != NULL)
		delete[] lastName;
	lastName = NULL;
	age = -1;
	if(ssn != NULL)
		delete[] ssn;
	ssn = NULL;
}

bool Person::setFirstName(char* firstName)
{
//	cout << "##INSIDE SET FIRST NAME##" << endl;
	if(this->firstName != NULL)
		delete[] this->firstName;
	this->firstName = new char[strlen(firstName)];
	strcpy(this->firstName, firstName);
	return true;
}

bool Person::setLastName(char* lastName)
{
//	cout << "##INSIDE SET LAST NAME##" << endl;
	if(this->lastName != NULL)
		delete[] this->lastName;
	this->lastName = new char[strlen(lastName)];
	strcpy(this->lastName, lastName);
	return true;
}

bool Person::setAge(int age)
{
//	cout << "##INSIDE SET AGE##" << endl;
	if(age < 0)
		return false;
	this->age = age;
	return true;
}

bool Person::setSSN(int* ssn)
{
//	cout << "##INSIDE SET SSN##" << endl;
	for(int i = 0; i < 9; i++)
		this->ssn[i] = ssn[i];
	return true;
}

char* Person::getFirstName()
{
//	cout << "##INSIDE GET FIRST NAME##" << endl;
	return firstName;
}

char* Person::getLastName()
{
//	cout << "##INSIDE GET LAST NAME##" << endl;
	return lastName;
}

int Person::getAge()
{
//	cout << "##INSIDE GET AGE##" << endl;
	return age;
}

int* Person::getSSN()
{
//	cout << "##INSIDE GET SSN##" << endl;
	return ssn;
}

void Person::print()
{
//	cout << "##INSIDE PERSON PRINT##" << endl;
	cout << firstName << " " << lastName << " (" << age << ") [";
	for(int i = 0; i < 9; i++)
		cout << ssn[i];
	cout << "]" << endl;
}


//EMPLOYEE CLASS!
Employee::Employee(const char* firstName, const char* lastName, int age, int* ssn, int* employeeNumber, const char* title, int salary):Person(firstName, lastName, age, ssn)
{
//	cout << "##INSIDE EMPLOYEE CONSTRUCTOR##" << endl;
	this->employeeNumber = new int[5];
	if(employeeNumber != NULL)
		for(int i = 0; i < 5; i++)
			this->employeeNumber[i] = employeeNumber[i];
	this->title = new char[strlen(title)];
	strcpy(this->title, title);
	this->salary = salary;
}

Employee::~Employee()
{
//	cout << "##INSIDE EMPLOYEE DESTRUCTOR##" << endl;
	if(employeeNumber != NULL)
		delete[] employeeNumber;
	employeeNumber = NULL;
	if(title != NULL)
		delete[] title;
	title = NULL;
	salary = -1;
}

bool Employee::setEmployeeNumber(int* employeeNumber)
{
//	cout << "##INSIDE SET EMPLOYEE NUMBER##" << endl;
	for(int i = 0; i < 5; i++)
		this->employeeNumber[i] = employeeNumber[i];
	return true;
}

bool Employee::setTitle(char* title)
{
//	cout << "##INSIDE SET TITLE##" << endl;
	if(this->title != NULL)
		delete[] this->title;
	this->title = new char[strlen(title)];
	strcpy(this->title, title);
	return true;
}

bool Employee::setSalary(int salary)
{
//	cout << "##INSIDE SET SALARY##" << endl;
	this->salary = salary;
	return true;
}

int* Employee::getEmployeeNumber()
{
//	cout << "##INSIDE GET EMPLOYEE NUMBER##" << endl;
	return employeeNumber;
}

char* Employee::getTitle()
{
//	cout << "##INSIDE GET TITLE##" << endl;
	return title;
}

int Employee::getSalary()
{
//	cout << "##INSIDE GET SALARY##" << endl;
	return salary;
}

void Employee::print()
{
//	cout << "##INSIDE EMPLOYEE PRINT##" << endl;
	Person::print();
	cout << "\t" << title << " #";
	for(int i = 0; i < 5; i++)
		cout << employeeNumber[i];
	cout << " $" << salary << endl;
}

//STUDENT CLASS!
Student::Student(const char* firstName, const char* lastName, int age, int* ssn, int* nsheNumber, const char* major, double gpa):Person(firstName, lastName, age, ssn)
{
//	cout << "##INSIDE STUDENT CONSTRUCTOR##" << endl;
	this->nsheNumber = new int[10];
	if(nsheNumber != NULL)
		for(int i = 0; i < 10; i++)
			this->nsheNumber[i] = nsheNumber[i];
	this->major = new char[strlen(major)];
	strcpy(this->major, major);
	this->gpa = gpa;
}

Student::~Student()
{
//	cout << "##INSIDE STUDENT DESTRUCTOR##" << endl;
	if(nsheNumber != NULL)
		delete[] nsheNumber;
	nsheNumber = NULL;
	if(major != NULL)
		delete[] major;
	major = NULL;
	gpa = -1.0;
}

bool Student::setNsheNumber(int* nsheNumber)
{
//	cout << "##INSIDE SET NSHE NUMBER##" << endl;
	for(int i = 0; i < 10; i++)
		this->nsheNumber[i] = nsheNumber[i];
	return true;
}

bool Student::setMajor(char* major)
{
//	cout << "##INSIDE SET MAJOR##" << endl;
	if(this->major != NULL)
		delete[] this->major;
	this->major = new char[strlen(major)];
	strcpy(this->major, major);
	return true;
}

bool Student::setGpa(double gpa)
{
//	cout << "##INSIDE SET GPA##" << endl;
	this->gpa = gpa;
	return true;
}

int* Student::getNsheNumber()
{
//	cout << "##INSIDE GET NSHE NUMBER##" << endl;
	return nsheNumber;
}

char* Student::getMajor()
{
//	cout << "##INSIDE GET MAJOR##" << endl;
	return major;
}

double Student::getGpa()
{
//	cout << "##INSIDE GET GPA##" << endl;
	return gpa;
}

void Student::print()
{
//	cout << "##INSIDE STUDENT PRINT##" << endl;
	Person::print();
	cout << "\t" << major << " #";
	for(int i = 0; i < 10; i++)
		cout << nsheNumber[i];
	cout << ", " << gpa << endl;
}
