// intlist.cpp
// Implements class IntList
// YOUR NAME(S), AND DATE

#include "intlist.h"
#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
	first = 0;
	for (Node* a = source.first; a != NULL; a=a->next){
		append(a->info);
	}
	//IMPLEMENT THIS
}

// destructor deletes all nodes
IntList::~IntList() {
	Node* a = first;
	while (a){
		a = a->next;
		delete first;
		first = a;
	}
 	delete a;
 	delete first;   //IMPLEMENT THIS
}


// return sum of values in list
int IntList::sum() const {
	int sum = 0;
	Node* a = first;
	while (a){
		sum += a->info;
	a=a->next;
	}
	return sum; // REPLACE THIS NON-SOLUTION
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
	if (count()==0) return false;
	bool b = false;
	if (first->info == value) b = true;
	else {
		Node* a = first->next;
		while(a){
			if (a->info == value) b = true;
			a = a-> next;
		}
	}
	return b; // REPLACE THIS NON-SOLUTION
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
	if (count() == 0) return 0;
	int c = first->info;
	Node* a = first->next;
	while (a){
		if (a->info > c) c = a->info;
			a = a->next;
		}
	return c; // REPLACE THIS NON-SOLUTION
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
	if (count()==0) return 0.0;
	return (sum()/count());  // REPLACE THIS NON-SOLUTION
}

// inserts value as new node at beginning of list
void IntList::insertFirst(int value) {
	Node* z = new Node;
	z->info = value;
	z->next = first;
	first = z;// IMPLEMENT
}

//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    //IMPLEMENT
	for (Node* a = source.first; a!= NULL; a=a->next){
		append(a->info);
	}
	cout << "flag\n";
	return *this;
}



// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// constructor sets up empty list
IntList::IntList() : first(0) { }


// append value at end of list
void IntList::append(int value) {
    if (first == 0) { // empty list
        first = new Node;
        first->info = value;
        first->next = 0;
    }
    else {
        Node *n = first;
        while (n->next) // not last node yet
            n = n->next;
        n->next = new Node;
        n->next->info = value;
        n->next->next = 0;
    }
}

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = first;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

// return count of values
int IntList::count() const {
    int result = 0;
    Node *n = first;
    while (n) {
        ++result;
        n = n->next;
    }
    return result;
}
