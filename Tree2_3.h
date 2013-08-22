#ifndef _TREE_2_3
#define _TREE_2_3

#include "BinaryTreeInterface.h"
#include "TriNode.h"
#include <algorithm>
template<class ItemType>
class Tree2_3 :	public BinaryTreeInterface<ItemType>
{
private:
	TriNode<ItemType>* RootPointer;
	ItemType *dummy;
	ItemType dummy2;
protected:
	TriNode<ItemType>* CopyTree(const TriNode<ItemType>*) const;
	void DestroyTree(TriNode<ItemType>*);
	int GetHeightHelper(TriNode<ItemType>*) const;
	// Recursive traversal helper methods:
	void PreOrder(void visit(ItemType&), TriNode<ItemType>* treePtr) const;
	void InOrder(void visit(ItemType&), TriNode<ItemType>* treePtr) const;
	void PostOrder(void visit(ItemType&), TriNode<ItemType>* treePtr) const;
public:
	Tree2_3();
	Tree2_3(const ItemType&);
	Tree2_3(const ItemType&, const Tree2_3<ItemType>*,
		const Tree2_3<ItemType>*, const Tree2_3<ItemType>*);
	Tree2_3(const Tree2_3<ItemType>&);
	virtual ~Tree2_3();

	// Checks to see if tree is Empty
	// @Returns: True if empty; false otherwise
	bool IsEmpty() const;
	int GetHeight() const;
	int GetNumberOfNodes() const;

	// @Returns: Data item at root of the tree
	ItemType GetRootData() const;

	// Sets data of root 
	void SetRootData(const ItemType&);
	bool Add(const ItemType&);
	bool Remove(const ItemType&);
	void Clear();
	ItemType GetEntry(const ItemType&) const;
	bool Contains(const ItemType&) const;


	// Traversals
	void PreorderTraverse(void Visit(ItemType&)) const;
	void InorderTraverse(void Visit(ItemType&)) const;
	void PostorderTraverse(void Visit(ItemType&)) const;
};

// Default Constructor
template<class ItemType>
Tree2_3<ItemType>::Tree2_3(void) : RootPointer(nullptr)
{
}

// Constructor
template<class ItemType>
Tree2_3<ItemType>::Tree2_3(const ItemType& rootItem)
{
	RootPointer = new TriNode<ItemType>(rootItem, nullptr, nullptr, nullptr);
}

// Constructor
template<class ItemType>
Tree2_3<ItemType>::Tree2_3(const ItemType& rootItem, const Tree2_3<ItemType>* leftTreePointer,
		const Tree2_3<ItemType>* middleTreePointer, const Tree2_3<ItemType>* rightTreePointer)
{
	RootPointer = new TriNode<ItemType>(rootItem, CopyTree(leftTreePointer->RootPointer), 
		CopyTree(middleTreePointer->RootPointer), CopyTree(rightTreePointer->RootPointer));
}

// Copy Constructor
template<class ItemType>
Tree2_3<ItemType>::Tree2_3(const Tree2_3<ItemType>& treePointer)
{
	RootPointer = CopyTree(treePointer.RootPointer);
}

// Destructor!
template<class ItemType>
Tree2_3<ItemType>::~Tree2_3(void)
{
	DestroyTree(RootPointer);
}

// IsEmpty
template<class ItemType>
bool Tree2_3<ItemType>::IsEmpty() const
{
	return RootPointer == nullptr;
}
	
template<class ItemType>
int Tree2_3<ItemType>::GetHeight() const
{
	return GetHeightHelper(RootPointer);
}
	
template<class ItemType>
int Tree2_3<ItemType>::GetNumberOfNodes() const
{
	return 0;
}
	
// GetRootData
template<class ItemType>
ItemType Tree2_3<ItemType>::GetRootData() const
{
	return RootPointer->GetItem();
}

// SetRootData
template<class ItemType>
void Tree2_3<ItemType>::SetRootData(const ItemType& rootData)
{
	TriNode<ItemType>* NewTriNodePtr = new TriNode<ItemType>(rootData);
	RootPointer = NewTriNodePtr;
	NewTriNodePtr = nullptr; // Not sure this is necessary
}
	
// Add Item to Tree
template<class ItemType>
bool Tree2_3<ItemType>::Add(const ItemType& inputItem)
{
	if (RootPointer == nullptr)
		SetRootData(inputItem);
	else
		std::cout << "Nope" << std::endl; // Yeah, I know
	return false;	
}
	
template<class ItemType>
bool Tree2_3<ItemType>::Remove(const ItemType&)
{
	return false;
}
	
template<class ItemType>
void Tree2_3<ItemType>::Clear()
{

}

template<class ItemType>
ItemType Tree2_3<ItemType>::GetEntry(const ItemType& anEntry) const
{
	return *dummy;	
}

template<class ItemType>
bool Tree2_3<ItemType>::Contains(const ItemType& item) const
{
	return false;
}

// Copy Tree
template<class ItemType>
TriNode<ItemType>* Tree2_3<ItemType>::CopyTree(const TriNode<ItemType>* treePointer) const
{
	
	TriNode<ItemType>* NewTreePointer = nullptr;

	// Copy nodes during PreOrder traversal
	if (treePointer != nullptr)
	{
		NewTreePointer = new TriNode<ItemType>(treePointer->GetItem(), nullptr, nullptr, nullptr);
		NewTreePointer->SetLeftChildPtr(CopyTree(treePointer->GetLeftChildPtr()));
		NewTreePointer->SetMidChildPtr(CopyTree(treePointer->GetMidChildPtr()));
		NewTreePointer->SetRightChildPtr(CopyTree(treePointer->GetRightChildPtr()));
	}
	return NewTreePointer;
}

// Tree destroyer
template<class ItemType>
void Tree2_3<ItemType>::DestroyTree(TriNode<ItemType>* subTreePointer)
{
	if (subTreePointer != nullptr)
	{
		DestroyTree(subTreePointer->GetLeftChildPtr());
		DestroyTree(subTreePointer->GetMidChildPtr());
		DestroyTree(subTreePointer->GetRightChildPtr());
		delete subTreePointer;
	}
}

// Height counter assistant
template<class ItemType>
int Tree2_3<ItemType>::GetHeightHelper(TriNode<ItemType>* subTreePointer) const
{
	if (subTreePointer == nullptr) 
		return 0;
	else
		return 1 + std::max(std::max(GetHeightHelper(subTreePointer->GetLeftChildPtr()), GetHeightHelper(subTreePointer->GetMidChildPtr())),
		GetHeightHelper(subTreePointer->GetRightChildPtr()));
}

//Traversal helper: InOrder
template<class ItemType>
void Tree2_3<ItemType>::InOrder(void Visit(ItemType&), TriNode<ItemType>* treePtr) const
{
	if (treePtr != nullptr) {
		InOrder(Visit, treePtr->GetLeftChildPtr());
		ItemType theItem = treePtr->GetItem();
		Visit(theItem);
		InOrder(Visit, treePtr->GetMidChildPtr());
		InOrder(Visit, treePtr->GetRightChildPtr());
	}
}

//Traversal helper: PreOrder
template<class ItemType>
void Tree2_3<ItemType>::PreOrder(void Visit(ItemType&), TriNode<ItemType>* treePtr) const
{
	if (treePtr != nullptr) {
		ItemType theItem = treePtr->GetItem();
		Visit(theItem);	
		PreOrder(Visit, treePtr->GetLeftChildPtr());
		PreOrder(Visit, treePtr->GetMidChildPtr());
		PreOrder(Visit, treePtr->GetRightChildPtr());
	}
}

//Traversal helper: PostOrder
template<class ItemType>
void Tree2_3<ItemType>::PostOrder(void Visit(ItemType&), TriNode<ItemType>* treePtr) const
{
	if (treePtr != nullptr) {
		PostOrder(Visit, treePtr->GetLeftChildPtr());
		PostOrder(Visit, treePtr->GetMidChildPtr());
		PostOrder(Visit, treePtr->GetRightChildPtr());
		ItemType theItem = treePtr->GetItem();
		Visit(theItem);
	}
}

template<class ItemType>
void Tree2_3<ItemType>::PreorderTraverse(void Visit(ItemType&)) const
{
	PreOrder(Visit, RootPointer);
}
	
template<class ItemType>
void Tree2_3<ItemType>::InorderTraverse(void Visit(ItemType&)) const
{
	InOrder(Visit, RootPointer);
}
	
template<class ItemType>
void Tree2_3<ItemType>::PostorderTraverse(void Visit(ItemType&)) const
{
	PostOrder(Visit, RootPointer);
}
#endif