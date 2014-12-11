#ifndef PROJECT_12_CLASSES_H_
#define PROJECT_12_CLASSES_H_
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

class Person
{
	public:
		Person(const char* = "", const char* = "", int = -1, int* = NULL);
		~Person();
		bool setFirstName(char*);
		bool setLastName(char*);
		bool setAge(int);
		bool setSSN(int*);
		char* getFirstName();
		char* getLastName();
		int getAge();
		int* getSSN();
		void print();
	protected:
		char* firstName;
		char* lastName;
		int age;
	private:
		int* ssn;
};

class Employee : public Person
{
	public:
		Employee(const char* = "", const char* = "", int = -1, int* = NULL, int* = NULL, const char* = "", int = -1);
		~Employee();
		bool setEmployeeNumber(int*);
		bool setTitle(char*);
		bool setSalary(int);
		int* getEmployeeNumber();
		char* getTitle();
		int getSalary();
		void print();
	private:
		int* employeeNumber;
		char* title;
		int salary;
};

class Student : public Person
{
	public:
		Student(const char* = "RAWR", const char* = "", int = -1, int* = NULL, int* = NULL, const char* = "", double = -1.0);
		~Student();
		bool setNsheNumber(int*);
		bool setMajor(char*);
		bool setGpa(double);
		int* getNsheNumber();
		char* getMajor();
		double getGpa();
		void print();
	private:
		int* nsheNumber;
		char* major;
		double gpa;
};
#endif
