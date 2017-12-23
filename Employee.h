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
	string Name;
	string Position;
	int Age;
	Employee (const char *_name, const char *_position, int _age)
	{

		Name = _name;
		Position = _position;
		Age = _age;
	};
	
};


















#endif /* __EMPLOYEE_H__ */
