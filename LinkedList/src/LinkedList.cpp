#include "LinkedList.h"
#include <iostream>

using namespace std;
LinkedList::LinkedList()
{
    head = NULL;
}

LinkedList::~LinkedList()
{

}
void LinkedList::insert_at_beginning(int a){
	Node *temp = new Node();
	temp->v = a;
	temp->next = head;
	head = temp;
}

void LinkedList::insert_at_end(int a){
	Node *temp = new Node();
	temp->v = a;
	if (head == NULL){
		// if linked list is empty, that is head == NULL
		// Make temp the new head
		head = temp;
	}
	else{
		// if linked list is not empty
		// go to the last node of the linked list
		Node *ptr = head;
		// the loop sets ptr to last node of the linked list
		while (ptr->next != NULL){
			ptr = ptr->next;
		}
		// ptr now points to the last node
		// store temp address in the next of ptr
		ptr->next = temp;
	}
}

void LinkedList::insert_at_given_position(int a, int p){
	Node *temp = new Node();
	temp->v = a;
	if (p == 0){
		// if p==0 then insert temp at beginning
		temp->next = head;
		head = temp;
	}
	else{
		Node *ptr = head;
		// the loop sets ptr to (p-1)th node
		while(p>1) {
			ptr = ptr->next;
			--p;
		}
		// ptr now points to (p-1)th node
		// insert temp between (p-1)th and pth node
		temp->next = ptr->next;
		ptr->next = temp;
	}
}

void LinkedList::delete_at_beginning(){
	if (head == NULL){
		cout<<"Lista jest pusta"<<endl;
	}
	else{
		cout<<"element jest usuniety: "<<head->v<<endl;
		// if linked list is not empty
		// store address of first node in temp
		Node *temp = head;
		// set second node as the new head of the linked list
		head = head->next;
		// free the old head
		delete(temp);
	}
}

void LinkedList::delete_at_end(){
	if (head == NULL){
		cout<<"Lista jest pusta"<<endl;
	}
	else if (head->next == NULL){
		// if there's only 1 element in the linked list
		// free head and set it to NULL
		cout<<"element usuniety: "<<head->v<<endl;
		delete(head);
		head = NULL;
	}
	else{
		// if there's more than 1 element in the linked
		// traverse to 2nd last element of the linked list
		Node *temp = head;
		while (temp->next->next != NULL) {
			temp = temp->next;
		}
		// temp now points to the 2nd last element of the linked list
		cout<<"element usuniety: "<<temp->next->v<<endl;
		// delete last node
		delete(temp->next);
		// set the next of 2nd last element to NULL
		temp->next = NULL;
	}

}
void LinkedList::delete_at_given_position(int p){
			if (head == NULL){
				// if list is empty do nothing
				cout<<"Lista jest pusta"<<endl;
			}
			else{
				Node *temp, *ptr;
				if (p == 0) {
					// if p==0, perform delete at beginning
					cout<<"element usuniety: "<<head->v<<endl;
					ptr = head;
					head = head->next;
					delete(ptr);
				}
				else{
					// if p > 0

					temp = ptr = head;
					while(p>0){
						--p;
						temp = ptr;
						ptr = ptr->next;
					}
					cout<<"element usuniety: "<<ptr->v<<endl;

					temp->next = ptr->next;
					delete ptr;
				}
			}

		}
void LinkedList::print(){
	if (head == NULL){
		cout<<"Lista jest pusta"<<endl;
	}
	else{
		Node *temp = head;
		cout<<"Linekd List: ";
		while (temp != NULL){
			cout<<temp->v<<"->";
			temp = temp->next;
		}
		cout<<"NULL"<<endl;
	}
}

int LinkedList::getCount()
{
    if (head == NULL){
		return 0;
	}
    int count = 0; // Initialize count
    Node* temp = head; // Initialize current
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}


int LinkedList::searchElement(int elem)
{
    if (head == NULL){
		return -1;
	}
    int i=0, pos = -1; // Initialize count
    Node* temp = head; // Initialize current
    while (temp != NULL)
    {
        if (temp->v==elem)
            pos=i;
        temp = temp->next;
        i++;
    }
    return pos;
}
