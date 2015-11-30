#pragma once
#include "TreeNode.h"



template <class T>
class BinarySearchTree
{
public:
	BinarySearchTree();
	~BinarySearchTree();

	void Insert(T value);
	void Clear();
	bool Find(T value);
	int Size();
	void Traversal_pre_order();
	void Traversal_in_order();
	void Traversal_post_order();

private:
	enum Order
	{
		PREORDER,
		POSTORDER,
		INORDER
	};

	TreeNode<T>* rootNode;

	void Visit(TreeNode<T>* node, Order order);
	void SizeVisit(TreeNode<T>* node, int &number);
	void InsertVisit(TreeNode<T>* node, T &value);
	void ClearVisit(TreeNode<T>* node);
};

template <class T>
BinarySearchTree<T>::BinarySearchTree()
{

}

template <class T>
BinarySearchTree<T>::~BinarySearchTree()
{
}

template <class T>
void BinarySearchTree<T>::Insert(T value)
{
	if (rootNode == NULL)
	{
		rootNode = new TreeNode<T>(value);
		std::cout << "Rootnode set to: " << value << std::endl;
	}
	else
	{
		InsertVisit(rootNode, value);
	}

}

template <class T>
void BinarySearchTree<T>::Clear()
{
	ClearVisit(rootNode);
	rootNode = NULL;
	std::cout << "List is cleared!" << std::endl;
}

template <class T>
bool BinarySearchTree<T>::Find(T value)
{
	if (rootNode == NULL)		//If list is empty just return false.
		return false;

	TreeNode<T>* currentNode = rootNode;
	while (true)
	{
		if (value < currentNode->GetValue())		//If the value is lower than the node go deeper.
		{
			if (currentNode->GetLesserChild() == NULL)
			{
				return false;		//And return false if it's empty.
			}
			else
			{
				currentNode = currentNode->GetLesserChild();		//Here we go deeper.
			}
		}
		else if (value > currentNode->GetValue())		//Do the same for higher value
		{
			if (currentNode->GetBiggerChild() == NULL)
			{
				return false;
			}
			else
			{
				currentNode = currentNode->GetBiggerChild();
			}
		}
		else
		{
			return true;		//If everything else is false, then the number is equal and it is found.
		}
	}
}
template <class T>
int BinarySearchTree<T>::Size()
{
	int number = 0;
	SizeVisit(rootNode, number);		//Recursion function goes through all nodes.
	std::cout << "Size of the list is currently: " << number << std::endl;
	return number;
}

template <class T>
void BinarySearchTree<T>::Traversal_pre_order()
{
	std::cout << "Starting traversal Pre-Order! \n";		//Announcement then start traversing.
	Visit(rootNode, PREORDER);		//Recursion function.
}

template <class T>
void BinarySearchTree<T>::Traversal_post_order()
{
	std::cout << "Starting traversal Post-Order! \n";		//Announcement then start traversing.
	Visit(rootNode, POSTORDER);			//Recursion function.
}

template <class T>
void BinarySearchTree<T>::Traversal_in_order()
{
	std::cout << "Starting traversal In-Order! \n";			//Announcement then start traversing
	Visit(rootNode, INORDER);		//Recursion function.
}

template <class T>
void BinarySearchTree<T>::Visit(TreeNode<T>* node, Order order)
{
	if (node == NULL)		//If the node is empty, then we just skip the function.
		return;


	if (order == PREORDER)
	{
		std::cout << node->GetValue() << std::endl;		//Pre-Order will always output itself before going down the chain.
		Visit(node->GetLesserChild(), order);
		Visit(node->GetBiggerChild(), order);
	}
	else if (order == INORDER)
	{
		Visit(node->GetLesserChild(), order);
		std::cout << node->GetValue() << std::endl;
		Visit(node->GetBiggerChild(), order);		//In-Order will always go down to the lowest value before outputting.
	}
	else if(order == POSTORDER)
	{
		Visit(node->GetLesserChild(), order);
		Visit(node->GetBiggerChild(), order);		//Post-Order is super wierd but it fullfills the assignment.
		std::cout << node->GetValue() << std::endl;
	}
}

template <class T>
void BinarySearchTree<T>::SizeVisit(TreeNode<T>* node, int &number)
{
	if (node == NULL)
		return;

	number++;
	SizeVisit(node->GetLesserChild(), number);
	SizeVisit(node->GetBiggerChild(), number);
}

template <class T>
void BinarySearchTree<T>::InsertVisit(TreeNode<T>* node, T &value)
{
	if (value < node->GetValue())
	{
		if (node->GetLesserChild() == NULL)
		{
			node->SetLesserChild(new TreeNode<T>(value));
			std::cout << "New node succesfully added with value: " << value << std::endl;
		}
		else
		{
			InsertVisit(node->GetLesserChild(), value);
		}
	}
	else if (value > node->GetValue())
	{
		if (node->GetBiggerChild() == NULL)
		{
			node->SetBiggerChild(new TreeNode<T>(value));
			std::cout << "New node succesfully added with value: " << value << std::endl;
		}
		else
		{
			InsertVisit(node->GetBiggerChild(), value);
		}
	}
	else
	{
		std::cout << "Oops! Value already exist in list!" << std::endl;
	}
}

template <class T>
void BinarySearchTree<T>::ClearVisit(TreeNode<T>* node)
{
	if (node->GetLesserChild() != NULL)
	{
		ClearVisit(node->GetLesserChild());
		node->SetLesserChild(NULL);
	}
	if (node->GetBiggerChild() != NULL)
	{
		ClearVisit(node->GetBiggerChild());
		node->SetBiggerChild(NULL);
	}
	delete node;
}