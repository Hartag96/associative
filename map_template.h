#ifndef __MAP_TEMPLATE_H__
#define __MAP_TEMPLATE_H__
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <malloc.h>
#include <iostream>
using namespace std;


template<class INDEX, class PERSON> class map_template
{
	struct node
	{
		node *next;
		INDEX ID;
		PERSON sub_person;

		node(INDEX index, PERSON pperson): sub_person(pperson)
		{
			next = NULL;
			ID = index;
		}
	};
	
	node *head = NULL;

	
  public:
	
	map_template()
	{
		head = NULL;
	}

	~map_template()
	{
  		while (head)
    		{
      			node *t = head->next;
      			delete head;
      			head = t;
    		};	
	}

	map_template &operator= (const map_template & v)
	{
		if (&v == this)
			return *this;
		node *temp = v.head;	
		node *temp_local = NULL;	
		
		while(temp != NULL)
		{
		if(head == NULL)
		{ 
			head = temp;
			temp_local = head;
		}		
		else
		{
			temp_local->next = temp;
			temp_local = temp_local->next;
		}
				temp = temp->next; 		
		}
		return *this;
	}

	void Add(INDEX index, PERSON  person)
	{	
		node *nowy = new node(index, person);
		nowy->next = head;
		head = nowy;	
	}

	PERSON* Find(INDEX index)
	{
		node *temp = head;
		PERSON *tempp;
		while(temp != NULL)
		{
			if(temp->ID == index)
			{			
				tempp = &(temp->sub_person);
			}			
			temp = temp->next;
		}
	
		return tempp;
	}

	friend ostream & operator<< (ostream & s, const  map_template &v)
	{
	
		node *temp = v.head;
		while(temp != NULL)
		{
			s << temp->ID;
			temp = temp->next;
			s << "\n";  	
		}
		return s;
	}
};



#endif /* __MAP_TEMPLATE_H__ */
