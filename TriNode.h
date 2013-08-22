#ifndef _TRI_NODE
#define _TRI_NODE

template<class ItemType>
class TriNode
{
private:
   ItemType Item;    // Data portion
   TriNode<ItemType>* LeftChildPtr;  // Left-child pointer
   TriNode<ItemType>* MidChildPtr;   // Middle-child pointer
   TriNode<ItemType>* RightChildPtr; // Right-child pointer
   
public:
   TriNode();
   TriNode(const ItemType&);
   TriNode(const ItemType&, TriNode<ItemType>*,
           TriNode<ItemType>*, TriNode<ItemType>*);
   virtual ~TriNode();
   
   bool IsLeaf() const;
   
   ItemType GetItem() const;
   
   void SetItem(const ItemType&);
   
   TriNode<ItemType>* GetLeftChildPtr() const;
   TriNode<ItemType>* GetMidChildPtr() const;
   TriNode<ItemType>* GetRightChildPtr() const;
   
   void SetLeftChildPtr(TriNode<ItemType>*);
   void SetMidChildPtr(TriNode<ItemType>*);
   void SetRightChildPtr(TriNode<ItemType>*);
}; 

// Default Constructor
template<class ItemType>
TriNode<ItemType>::TriNode() : LeftChildPtr(nullptr), MidChildPtr(nullptr), RightChildPtr(nullptr)
{
}

// Constructor
template<class ItemType>
TriNode<ItemType>::TriNode(const ItemType& anItem) : LeftChildPtr(nullptr), MidChildPtr(nullptr), RightChildPtr(nullptr), Item(anItem)
{
}

// Constructor
template<class ItemType>
TriNode<ItemType>::TriNode(const ItemType& anItem, TriNode<ItemType>* left, 
						   TriNode<ItemType>* middle, TriNode<ItemType>* right) 
						   : LeftChildPtr(left), MidChildPtr(middle), RightChildPtr(right), Item(anItem)
{
}

// Destructor!
template<class ItemType>
TriNode<ItemType>::~TriNode()
{

}
// Checks for leafy-ness
template<class ItemType>
bool TriNode<ItemType>::IsLeaf() const
{
	bool Leaf = false;
	if(LeftChildPtr == nullptr &&
		MidChildPtr == nullptr &&
		RightChildPtr == nullptr)
		Leaf = true;
	return Leaf;
}

// Get data item for TriNode
template<class ItemType>
ItemType TriNode<ItemType>::GetItem() const
{
	return Item;
}

// Set data item for TriNode
template<class ItemType>
void TriNode<ItemType>::SetItem(const ItemType& anItem)
{
	Item = anItem;
}

// Get Pointer for left child
template<class ItemType>
TriNode<ItemType>* TriNode<ItemType>::GetLeftChildPtr() const
{
	return LeftChildPtr;
}

// Get Pointer for middle child
template<class ItemType>
TriNode<ItemType>* TriNode<ItemType>::GetMidChildPtr() const
{
	return MidChildPtr;
}

// Get Pointer for right child
template<class ItemType>
TriNode<ItemType>* TriNode<ItemType>::GetRightChildPtr() const
{
	return RightChildPtr;
}

// Sets Left Child Pointer
template<class ItemType>
void TriNode<ItemType>::SetLeftChildPtr(TriNode<ItemType>* leftChild)
{
	LeftChildPtr = leftChild;
}

// Sets Middle Child Pointer
template<class ItemType>
void TriNode<ItemType>::SetMidChildPtr(TriNode<ItemType>* middleChild)
{
	MidChildPtr = middleChild;
}

// Sets Right Child Pointer
template<class ItemType>
void TriNode<ItemType>::SetRightChildPtr(TriNode<ItemType>* rightChild)
{
	RightChildPtr = rightChild;
}
#endif