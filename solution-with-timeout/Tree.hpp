class Tree;

#include <iostream>
using std::ostream;

namespace ariel {

class Tree {
	
private:
	int myData;
	int mySize;
	Tree* myLeft;
	Tree* myRight;
	Tree* myParent;
	
	static Tree None;

public:
	// Init an empty tree:
	Tree() {
		mySize = 0;
		myLeft = myRight = &Tree::None;
		myParent = &Tree::None;
	}
	
	// Init a tree with one element:
	Tree(int newData, Tree* newParent=&Tree::None) {
		mySize = 1;
		myData = newData;
		myLeft = myRight = &Tree::None;
		myParent = newParent;
	}
	
	int size() { 
		return mySize; 
	}
	

	// insert the given int into the tree;
	// throws an exception if it is found.
	Tree& insert(int);

	// remove the given int from the tree;
	// throws an exception if it is not found.
	Tree& remove(int);

	// find the given int in the tree;
	// throws an exception if it is not found.
	const Tree* find(int) const;
	
	bool contains(int) const { return false; }
	
	int root() const;
	int parent(int i) const;
	int left(int i) const;
	int right(int i) const;
	
	static int treeCount() {
		// TODO: return the total number of trees in the system
		return 0;
	}
	
	ostream&  print() const;
	friend ostream& operator<<(ostream& out, const Tree& tree);
};

}
