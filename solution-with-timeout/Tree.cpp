/**
 * This solution has a long "sleep" in remove.
 * It should get a timeout signal in "remove" and the grade should be
 * determined according to the tests run so far.
 */

#include "Tree.hpp"
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

namespace ariel {

Tree& Tree::remove(int i) {
	for (int j=0; j<1000000000; ++j);
	// this_thread::sleep_for(chrono::seconds(3));
	--mySize;
	return *this; 
}

Tree& Tree::insert(int i) {
	if (mySize==0) {
		myData = i;
	} else {
		if (i == myData)   // do not insert the same number twice
			throw string("The number "+to_string(i)+" already exists!");
		else if (i < myData) {
			if (myLeft==&Tree::None)
				myLeft = new Tree(i, this);
			else
				myLeft->insert(i);
		} else {  // i > myData
			if (myRight==&Tree::None)
				myRight = new Tree(i, this);
			else
				myRight->insert(i);
		}
	}
	mySize++;
	return *this; 
}

const Tree* Tree::find(int i) const {
	if (mySize==0)
		throw string("The number "+to_string(i)+" does not exist - the tree is empty!");
	if (i == myData)   // do not insert the same number twice
		return this;
	else if (i < myData) {
		if (myLeft==&Tree::None)
			throw string("The number "+to_string(i)+" does not exist!");
		else
			return myLeft->find(i);
	} else {  // i > myData
		if (myRight==&Tree::None)
			throw string("The number "+to_string(i)+" does not exist!!");
		else
			return myRight->find(i);
	}
}

int Tree::parent(int i) const {
	Tree* p = find(i)->myParent;
	if (p==&Tree::None) throw string("no parent!");
	return p->myData;
}

int Tree::left(int i) const {
	Tree* p = find(i)->myLeft;
	if (p==&Tree::None) throw string("no left!");
	return p->myData;
}

int Tree::right(int i) const {
	Tree* p = find(i)->myRight;
	if (p==&Tree::None) throw string("no right!");
	return p->myData;
}

int Tree::root() const {
	return myData;
}


/**
 * @credit Konrad Rudolph https://stackoverflow.com/a/54750214/827927
 */
ostream& Tree::print() const {
  	return (this==&Tree::None?
			cout:
	    cout << myData
           << "(" << *(myLeft)  << ")"
		       << "[" << *(myRight) << "]");
}



/**
 * @credit Konrad Rudolph https://stackoverflow.com/a/54750214/827927
 */
ostream& operator<<(ostream& out, const Tree& tree) {
  	return tree.print();
}


Tree Tree::None;
}
