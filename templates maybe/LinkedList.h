#pragma once
#include "Node.h"
#include <iostream>

template <class T>
class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	void Push_Front(T data);
	void Push_Back(T data);
	void Pop_Front();
	void Pop_Back();
	void Clear();
	T At(int position);
	int Size();


private:
	Node<T>* rootNode;
};

template <class T>
LinkedList<T>::LinkedList()
{

}

template <class T>
LinkedList<T>::~LinkedList()
{
}

template <class T>
void LinkedList<T>::Push_Front(T data)
{
	if (rootNode != NULL)
	{
		Node<T>* temp = rootNode;
		rootNode = new Node<T>(data);
		rootNode->SetNextNode(temp);
	}
	else
	{
		rootNode = new Node<T>(data);
	}

}

template <class T>
void LinkedList<T>::Push_Back(T data)
{
	if (rootNode != NULL)
	{
		Node<T>* tempNode = rootNode;
		while (true)
		{
			if (tempNode->GetNextNode() == NULL)
			{
				tempNode->SetNextNode(new Node<T>(data));
				break;
			}
			else
			{
				tempNode = tempNode->GetNextNode();
			}
		}
	}
	else
	{
		rootNode = new Node<T>(data);
	}
}

template <class T>
void LinkedList<T>::Pop_Front()
{
	if (rootNode == NULL)
		return;

	Node<T>* temp = rootNode->GetNextNode();
	delete rootNode;
	rootNode = temp;
}

template <class T>
void LinkedList<T>::Pop_Back()
{
	if (rootNode == NULL)
		return;

	if (rootNode->GetNextNode() != NULL)
	{
		Node<T>* nextNode = rootNode;
		for (int i = 0; i < Size() - 2; i++)
		{
			nextNode = nextNode->GetNextNode();
		}
		delete nextNode->GetNextNode();
		nextNode->SetNextNode(NULL);
	}
	else if (rootNode->GetNextNode() == NULL)
	{
		delete rootNode;
		rootNode = NULL;
	}
}

template <class T>
void LinkedList<T>::Clear()
{
	if (rootNode == NULL)
		return;

	Node<T>* nextNode;
	while (true)
	{
		if (rootNode->GetNextNode() == NULL)
		{
			delete rootNode;
			rootNode = NULL;
			break;
		}
		else
		{
			nextNode = rootNode->GetNextNode();
			delete rootNode;
			rootNode = nextNode;
		}
	}
	std::cout << "List is now cleared!" << std::endl;
}

template <class T>
T LinkedList<T>::At(int position)
{
	if (position > Size()-1)
	{
		std::cout << "Position is out of range! \n";
		return NULL;
	}
	Node<T>* tempNode = rootNode;
	for (int i = 0; i < position; i++)
	{
		tempNode = tempNode->GetNextNode();
	}
	return tempNode->GetValue();
}

template <class T>
int LinkedList<T>::Size()
{
	int number = 0;
	Node<T>* nextNode = rootNode;
	while (true)
	{
		if (nextNode == NULL)
		{
			break;
		}
		else
		{
			nextNode = nextNode->GetNextNode();
			number++;
		}
	}
	return number;
}