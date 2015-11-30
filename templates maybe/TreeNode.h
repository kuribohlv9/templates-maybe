#pragma once

template <class T>
class TreeNode
{
public:
	TreeNode(T value);

	void SetLesserChild(TreeNode* node);
	void SetBiggerChild(TreeNode* node);
	void SetValue(T value);

	TreeNode* GetLesserChild();
	TreeNode* GetBiggerChild();
	T GetValue();

private:
	TreeNode* lesserChild;
	TreeNode* biggerChild;

	T Value;
};

template <class T>
TreeNode<T>::TreeNode(T value)
{
	SetValue(value);
}

template <class T>
void TreeNode<T>::SetLesserChild(TreeNode* node)
{
	lesserChild = node;
}
template <class T>
void TreeNode<T>::SetBiggerChild(TreeNode* node)
{
	biggerChild = node;
}
template <class T>
void TreeNode<T>::SetValue(T value)
{
	Value = value;
}

template <class T>
TreeNode<T>* TreeNode<T>::GetLesserChild()
{
	return lesserChild;
}
template <class T>
TreeNode<T>* TreeNode<T>::GetBiggerChild()
{
	return biggerChild;
}
template <class T>
T TreeNode<T>::GetValue()
{
	return Value;
}