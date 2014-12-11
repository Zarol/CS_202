#include "Project12Classes.h"

int main()
{
	Student tempStudent;
	Employee tempEmployee;
	ifstream ifs;
	ifs.open("persons");
	char tempChar;
	char* tempWord = new char[50];
	int tempInt = -1;
	int* tempArrInt = new int[10];
	double tempDbl = -1.0;
	for(int i = 0; i < 18; i++)
	{
		ifs >> tempChar;
		switch (tempChar)
		{
			case 's':
				ifs.get();
				ifs.getline(tempWord, 51, ':');
				tempStudent.setFirstName(tempWord);
				ifs.getline(tempWord, 51, ':');
				tempStudent.setLastName(tempWord);
				ifs >> tempInt;
				tempStudent.setAge(tempInt);
				ifs.get();
				for(int j = 0; j < 9; j++)
				{
					ifs >> tempChar;
					tempArrInt[j] = tempChar - '0';
				}
				tempStudent.setSSN(tempArrInt);
				ifs.get();
				for(int j = 0; j < 10; j++)
				{
					ifs >> tempChar;
					tempArrInt[j] = tempChar - '0';
				}
				tempStudent.setNsheNumber(tempArrInt);
				ifs.get();
				ifs.get(tempWord, 51, ':');
				tempStudent.setMajor(tempWord);
				ifs.get();
				ifs >> tempDbl;
				tempStudent.setGpa(tempDbl);
				tempStudent.print();
				break;
			case 'e':
				ifs.get();
				ifs.getline(tempWord, 51, ':');
				tempEmployee.setFirstName(tempWord);
				ifs.getline(tempWord, 51, ':');
				tempEmployee.setLastName(tempWord);
				ifs >> tempInt;
				tempEmployee.setAge(tempInt);
				ifs.get();
				for(int j = 0; j < 9; j++)
				{
					ifs >> tempChar;
					tempArrInt[j] = tempChar - '0';
				}
				tempEmployee.setSSN(tempArrInt);
				ifs.get();
				for(int j = 0; j < 5; j++)
				{
					ifs >> tempChar;
					tempArrInt[j] = tempChar - '0';
				}
				tempEmployee.setEmployeeNumber(tempArrInt);
				ifs.get();
				ifs.get(tempWord, 51, ':');
				tempEmployee.setTitle(tempWord);
				ifs.get();
				ifs >> tempInt;
				tempEmployee.setSalary(tempInt);
				tempEmployee.print();
				break;
		}
		cout << endl;
	}
	return 1;
}

void extractPerson(ifstream ifs, Person& person)
{
	
}

void extractEmployee(ifstream ifs, Employee& employee)
{

}

void extractStudent(ifstream ifs, Student& student)
{

}
