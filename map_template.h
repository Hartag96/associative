#ifndef __MAP_TEMPLATE_H__
#define __MAP_TEMPLATE_H__
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <malloc.h>
#include <iostream>
using namespace std;


template<class INDEX, class DATA> class map_template
{	
	class KeyNoExist{};
	struct node
	{
		node *next = NULL;
		INDEX ID;
		DATA *data;
	};
	
	node *head = NULL;

	
  public:
	
	map_template()
	{
		head = NULL;
	}
	
	map_template(const map_template &v)
	{
		
		node *temp_copy = v.head;	
		node *temp_new = NULL;
		node *temp_prev = NULL;
		try
		{	
			while(temp_copy != NULL)
			{
				temp_new = new node;
				temp_new->ID = temp_copy->ID;
				temp_new->data = temp_copy->data;
				
				if(head == NULL)
				{
					head = temp_new;                      	// inicjacja poczateku listy 
					temp_prev = temp_new;
					
				}
				else
				{	
					temp_prev->next = temp_new;
					temp_prev = temp_new;			
				}

				temp_new = temp_new->next;
				temp_copy = temp_copy->next;	
			}
		}catch(bad_alloc&)
		{
			while(head)
			{
				node *temp_delete = head->next;
				delete head;
				head = temp_delete;
			}
		}
		
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
	
		map_template temp(v);
		
		node *k = head;
		head = temp.head;
		temp.head = k;
		return *this;
	}

	void Add(INDEX _index, DATA  _data)
	{	
		node *new_node = NULL;
		try
		{
			new_node = new node;
			new_node->next = head;
			new_node->ID = _index;
			new_node->data = &(_data);
			head = new_node;
		}
		catch(bad_alloc&)
		{
			cout << "Nie udalo sie dodac nowego elementu" << endl;
			delete new_node;
			throw;
		}	
	}

	DATA* Find(INDEX index)
	{
		node *temp = head;
		DATA *temp_data = NULL;
		while(temp != NULL)
		{
			if(temp->ID == index)
			{			
				temp_data = temp->data;
			}			
			temp = temp->next;
		}
		if(temp_data == NULL){
			cout << "Nie znaleziono takiego klucza" <<endl;
			throw KeyNoExist();
		}
		return temp_data;
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
