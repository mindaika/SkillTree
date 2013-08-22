#ifndef _TREE
#define _TREE

#include "BinaryTreeInterface.h"
#include "TriNode.h"
#include <algorithm>
template<class ItemType>
class Tree : public BinaryTreeInterface<ItemType>
{
private:
	TriNode<ItemType>* RootPointer;
	int CurrentTreeLevel;

protected:
	TriNode<ItemType>* CopyTree(const TriNode<ItemType>*) const;
	void DestroyTree(TriNode<ItemType>*);
	int GetHeightHelper(TriNode<ItemType>*) const;
	bool AddChildHelper(const ItemType&, std::string, TriNode<ItemType>*);
	
	// Recursive traversal helper methods:
	void PreOrder(void visit(ItemType&), TriNode<ItemType>* treePtr);
	void InOrder(void visit(ItemType&), TriNode<ItemType>* treePtr) const;
	void PostOrder(void visit(ItemType&), TriNode<ItemType>* treePtr) const;

public:
	// Constructors
	Tree();
	Tree(const ItemType&);
	Tree(const ItemType&, const Tree<ItemType>*,
		const Tree<ItemType>*, const Tree<ItemType>*);
	Tree(const Tree<ItemType>&);
	
	// Destructor
	virtual ~Tree();

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
	bool AddChild(const ItemType&, const std::string);
	bool Remove(const ItemType&);
	void Clear();
	ItemType GetEntry(const ItemType&) const;
	bool Contains(const ItemType&) const;
	
	// Traversals
	void PreorderTraverse(void Visit(ItemType&));
	void InorderTraverse(void Visit(ItemType&)) const;
	void PostorderTraverse(void Visit(ItemType&)) const;
};

// Default Constructor
template<class ItemType>
Tree<ItemType>::Tree(void) : RootPointer(nullptr)
{
	CurrentTreeLevel = 0;
}

// Constructor
template<class ItemType>
Tree<ItemType>::Tree(const ItemType& rootItem)
{
	std::auto_ptr<TriNode<ItemType>> RootPointer( new TriNode<ItemType>(rootItem, nullptr, nullptr, nullptr) );
	CurrentTreeLevel = 0;
	//RootPointer = new TriNode<ItemType>(rootItem, nullptr, nullptr, nullptr);
}

// Constructor
template<class ItemType>
Tree<ItemType>::Tree(const ItemType& rootItem, const Tree<ItemType>* leftTreePointer,
		const Tree<ItemType>* middleTreePointer, const Tree<ItemType>* rightTreePointer)
{
	/*
	RootPointer = new TriNode<ItemType>(rootItem, CopyTree(leftTreePointer->RootPointer), 
		CopyTree(middleTreePointer->RootPointer), CopyTree(rightTreePointer->RootPointer));
	*/
	CurrentTreeLevel = 0;
	std::auto_ptr<TriNode<ItemType>> RootPointer( new TriNode<ItemType>(rootItem, CopyTree(leftTreePointer->RootPointer), 
		CopyTree(middleTreePointer->RootPointer), CopyTree(rightTreePointer->RootPointer)) );
}

// Copy Constructor
template<class ItemType>
Tree<ItemType>::Tree(const Tree<ItemType>& treePointer)
{
	RootPointer = CopyTree(treePointer.RootPointer);
}

// Destructor!
template<class ItemType>
Tree<ItemType>::~Tree(void)
{
	DestroyTree(RootPointer);
}

// IsEmpty
template<class ItemType>
bool Tree<ItemType>::IsEmpty() const
{
	return RootPointer == nullptr;
}
	
template<class ItemType>
int Tree<ItemType>::GetHeight() const
{
	return GetHeightHelper(RootPointer);
}
	
template<class ItemType>
int Tree<ItemType>::GetNumberOfNodes() const
{
	return 0;
}
	
// GetRootData
template<class ItemType>
ItemType Tree<ItemType>::GetRootData() const
{
	return RootPointer->GetItem();
}

// SetRootData
template<class ItemType>
void Tree<ItemType>::SetRootData(const ItemType& rootData)
{
	//std::auto_ptr<TriNode<ItemType>> NewTriNodePtr( new TriNode<ItemType>(rootData) );
	TriNode<ItemType>* NewTriNodePtr = new TriNode<ItemType>(rootData);
	RootPointer = NewTriNodePtr;
}
	
// Add Item to Tree
template<class ItemType>
bool Tree<ItemType>::Add(const ItemType& inputItem)
{
	if (RootPointer == nullptr) {
		SetRootData(inputItem);
	} else {
		TriNode<ItemType>* OldRoot = RootPointer;
		OldRoot = RootPointer; // Save old Root
		SetRootData(inputItem); // Create New Root
		RootPointer->SetRightChildPtr(OldRoot); // Set old Root as RtChild
	}
	return true;	
}

// Add Item to Tree as child of specified node
template<class ItemType>
bool Tree<ItemType>::AddChild(const ItemType& inputItem, std::string parent)
{
	return AddChildHelper(inputItem, parent, RootPointer);
}

template<class ItemType>
bool Tree<ItemType>::AddChildHelper(const ItemType& inputItem, std::string parent, TriNode<ItemType>* treePtr)
{
	if ( !(treePtr == nullptr) ) {	
		// Compare parent to name of parent to see if it's the right place to add this item
		if ( !(((treePtr->GetItem()).GetName()).compare(parent)) ) {			
			// Dig about looking for empty child to add
			TriNode<ItemType>* NewChildPointer = new TriNode<ItemType>(inputItem);
			if (treePtr->GetLeftChildPtr() == nullptr) {
				treePtr->SetLeftChildPtr(NewChildPointer);
			} else if (treePtr->GetMidChildPtr() == nullptr) {
				treePtr->SetMidChildPtr(NewChildPointer);
			} else if (treePtr->GetRightChildPtr() == nullptr) {
				treePtr->SetRightChildPtr(NewChildPointer);
			} else {
				delete NewChildPointer;
				NewChildPointer = nullptr;
				// Item not added; too many children
			}
		} else {
			AddChildHelper(inputItem, parent, treePtr->GetLeftChildPtr());
			AddChildHelper(inputItem, parent, treePtr->GetMidChildPtr());
			AddChildHelper(inputItem, parent, treePtr->GetRightChildPtr());
		}
	}
	return true;
}
	
template<class ItemType>
bool Tree<ItemType>::Remove(const ItemType&)
{
	return false;
}
	
template<class ItemType>
void Tree<ItemType>::Clear()
{

}

template<class ItemType>
ItemType Tree<ItemType>::GetEntry(const ItemType& anEntry) const
{
	return anEntry;	
}

template<class ItemType>
bool Tree<ItemType>::Contains(const ItemType& item) const
{
	return false;
}

// Copy Tree
template<class ItemType>
TriNode<ItemType>* Tree<ItemType>::CopyTree(const TriNode<ItemType>* treePointer) const
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
void Tree<ItemType>::DestroyTree(TriNode<ItemType>* subTreePointer)
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
int Tree<ItemType>::GetHeightHelper(TriNode<ItemType>* subTreePointer) const
{
	if (subTreePointer == nullptr) 
		return 0;
	else
		return 1 + std::max(std::max(GetHeightHelper(subTreePointer->GetLeftChildPtr()), GetHeightHelper(subTreePointer->GetMidChildPtr())),
		GetHeightHelper(subTreePointer->GetRightChildPtr()));
}

//Traversal helper: InOrder
template<class ItemType>
void Tree<ItemType>::InOrder(void Visit(ItemType&), TriNode<ItemType>* treePtr) const
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
void Tree<ItemType>::PreOrder(void Visit(ItemType&), TriNode<ItemType>* treePtr)
{
	static int RecursionDepth = 0;
	RecursionDepth++;
	if (treePtr != nullptr) {
		ItemType theItem = treePtr->GetItem();
		for ( int i = 0; i < RecursionDepth; i++ )
			std::cout << "  ";
		std::cout << "- ";
		Visit(theItem);
		PreOrder(Visit, treePtr->GetLeftChildPtr());
		PreOrder(Visit, treePtr->GetMidChildPtr());
		PreOrder(Visit, treePtr->GetRightChildPtr());
	}
	RecursionDepth--;
}

//Traversal helper: PostOrder
template<class ItemType>
void Tree<ItemType>::PostOrder(void Visit(ItemType&), TriNode<ItemType>* treePtr) const
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
void Tree<ItemType>::PreorderTraverse(void Visit(ItemType&))
{
	PreOrder(Visit, RootPointer);
}
	
template<class ItemType>
void Tree<ItemType>::InorderTraverse(void Visit(ItemType&)) const
{
	InOrder(Visit, RootPointer);
}
	
template<class ItemType>
void Tree<ItemType>::PostorderTraverse(void Visit(ItemType&)) const
{
	PostOrder(Visit, RootPointer);
}
#endif