#include "Tree.hpp"
#include <iostream>
using std::string, std::to_string;

namespace ariel {

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

Tree& Tree::remove(int i) {
	--mySize;
	// TODO: find i and remove it
	return *this; 
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


ostream& operator<<(ostream& out, const Tree& tree) {
  	return (&tree==&Tree::None?
	     out << tree.myData
           << "(" << *(tree.myLeft)  << ")"
		       << "[" << *(tree.myRight) << "]":
       out);
}


Tree Tree::None;

}
