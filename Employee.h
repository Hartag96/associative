#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <malloc.h>
#include <iostream>
using namespace std;

class Employee
{
  public:
	char* Name;
	char* Position;
	int Age;
	Employee (const char *n, const char *p, int a)
	{
		Name = new char[strlen (n) + 1];	
		strcpy(Name, n);
		Position = new char[strlen (p) + 1];
		strcpy(Position, p);
		Age = a;
	};
	Employee (const Employee & temp)
	{
		Name = new char[strlen (temp.Name) + 1];	
		strcpy(Name, temp.Name);
		Position = new char[strlen (temp.Position) + 1];
		strcpy(Position, temp.Position);
		Age = temp.Age;	
	}
	
	Employee()
	{

	};
	
	~Employee ()
	{
		delete [] Name;
		delete [] Position;	
	};
	
	Employee &operator[] (const char *key)
	{
		return *this;
	};


	
};


















#endif /* __EMPLOYEE_H__ */
