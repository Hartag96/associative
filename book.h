#ifndef __BOOK_H__
#define __BOOK_H__
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <malloc.h>
#include <iostream>
using namespace std;
		enum dostepnosc 
		{
			na_polce = true,
			wyporzyczona = false
		};
class book
{

	public:

		char* imie;
		char* nazwisko;
		char* kategoria;
		int liczba;
		dostepnosc status;
	book (const char *i, const char *n, const char *k, int l, dostepnosc s)
	{
		imie = new char[strlen (i) + 1];	
		strcpy(imie, i);
		nazwisko = new char[strlen (n) + 1];
		strcpy(nazwisko, n);
		kategoria = new char[strlen (k) + 1];
		strcpy(kategoria, n);
		liczba = l;
		status = s;
	};

	book (const book & temp)
	{
		imie = new char[strlen (temp.imie) + 1];	
		strcpy(imie, temp.imie);
		nazwisko = new char[strlen (temp.nazwisko) + 1];
		strcpy(nazwisko, temp.nazwisko);
		kategoria = new char[strlen (temp.kategoria) + 1];
		strcpy(kategoria, temp.kategoria);
		liczba = temp.liczba;
		status = temp.status;
	};

	~book()
	{
		delete [] imie;
		delete [] nazwisko;
		delete [] kategoria;
	}	

					

};

#endif /* __BOOK_H__ */
