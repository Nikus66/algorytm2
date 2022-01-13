#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
#include <cstddef>
class LinkedList
{
    Node * head;
	public:
		/* Member functions to perform
                   different operations on Linked List */
                void insert_at_beginning(int v);
                void insert_at_end(int v);
                void insert_at_given_position(int v, int p);
                void delete_at_beginning();
                void delete_at_end();
                void delete_at_given_position(int p);
                void print();
                int getCount();
                int searchElement(int elem);
         LinkedList();
        ~LinkedList();

};

#endif // LINKEDLIST_H
