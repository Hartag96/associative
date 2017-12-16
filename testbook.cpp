#include <iostream>
using namespace std;


#include "map_template.h"		//defines template map_template<Key,Value>
#include "book.h"

int main(void)
{
	typedef const char* TITLE; 						

	map_template<TITLE,book> Biblioteka;

	Biblioteka.Add("Werter", book("Stefan", "Zeromski", "powiesc", 267, na_polce)); 
	Biblioteka.Add("Przedwiosnie", book("Johann Wolfgang", "von Goethe", "powiesc", 317, na_polce));
	Biblioteka.Add("The Lord of the Rings", book("John Ronald Reuel", "Tolkien", "przygodowa", 412, wyporzyczona));
	Biblioteka.Add("W pustyni i w puszczy", book("Henryk", "Sienkiewicz", "baja", 254, na_polce));
	Biblioteka.Add("Treny", book("Jan", "Kochanowski", "wiersze", 38, wyporzyczona));

	cout << Biblioteka <<endl;
}
