#pragma once

template <class T>
class Node
{
public:
	Node(T data);
	~Node();

	void SetNextNode(Node* node);
	void SetValue(T data);
	Node* GetNextNode();
	T GetValue();

private:
	T value;
	Node* nextNode;
};

template <class T>
Node<T>::Node(T data)
{
	SetValue(data);
}

template <class T>
Node<T>::~Node()
{
}

template <class T>
void Node<T>::SetNextNode(Node* node)
{
	nextNode = node;
}

template <class T>
void Node<T>::SetValue(T data)
{
	value = data;
}

template <class T>
Node<T>* Node<T>::GetNextNode()
{
	return nextNode;
}

template <class T>
T Node<T>::GetValue()
{
	return value;
}