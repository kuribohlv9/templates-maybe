// templates maybe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include "LinkedList.h"
#include "BinarySearchTree.h"
#include "Unit.h"

void LinkedListUnitTest()
{
	LinkedList<int> myList;

	//everything is an Find test

	myList.Push_Front(3);
	myList.Push_Front(6);
	myList.Push_Back(5);
	myList.Push_Back(7);

	verify(myList.At(0), 6, "Pushfront test");
	verify(myList.At(3), 7, "Pushback test");
	verify(myList.Size(), 4, "Size test");

	myList.Pop_Front();
	myList.Pop_Back();

	verify(myList.At(0), 3, "Popfront test");
	verify(myList.At(1), 5, "Popback test");

	myList.Clear();

	verify(myList.At(0), 0, "Clear test");
}
void BinarySearchTreeUnitTest()
{
	BinarySearchTree<int> myTree;

	myTree.Insert(5);
	myTree.Insert(2);
	myTree.Insert(6);
	myTree.Insert(3);
	myTree.Insert(3);

	verify(myTree.Find(5), true, "Insert and Find Test");
	verify(myTree.Find(6), true, "Insert and Find Test");
	verify(myTree.Find(3), true, "Insert and Find Test");

	myTree.Traversal_pre_order();		//Each traversal outputs its own vertification.
	myTree.Traversal_in_order();
	myTree.Traversal_post_order();

	verify(myTree.Size(), 4, "Size Test");

	myTree.Clear();

	verify(myTree.Find(5), false, "Clear Test");
}

int _tmain(int argc, _TCHAR* argv[])
{
	//Comment out the appropriate function for unit testing
	
	std::cout << "LinkedList test begin!" << std::endl;
	LinkedListUnitTest();
	
	std::cout << std::endl << "Binarysearchtree test begin!" << std::endl;
	BinarySearchTreeUnitTest();

	return 0;
}

