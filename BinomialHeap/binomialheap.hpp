#ifndef BINOMIALHEAP_H_
#define BINOMIALHEAP_H_


#define DEBUG false
#include <iostream>

template <typename B>
class BinomialNode;

template <typename B>
class BinomialHeap
{

public:
	
	friend class BinomialNode<B>;

	BinomialHeap();
	BinomialHeap(const BinomialHeap& other);
	//BinomialHeap& operator=(const BinomialHeap& other);
	~BinomialHeap();
	/*
	 * insert
	 * 		Creates a singleton heap node with value v and
	 * 		 unions it with the head
	 * 	value:
	 * 		value to insert into heap
	 *
	 */
	//void insert(B value);
	///*
	// * getMin
	// * 		Searches the heap list for the node with minimum value
	// *
	// * returns
	// * 		minimum value in heap list
	// */
	//B getMin();
	///*
	// * extractMin
	// * 		Removes the heap list for node with minimum value
	// * 		and unions minimum node's children with heap list
	// *
	// * returns
	// * 		minimum value in heap list
	// */
	//B extractMin();
	///*
	// * deleteKey
	// * 		Removes the node with the value v by decreasing
	// * 		node value to one less than current min and then
	// * 		extracts the min.
	// * value:
	// * 		value to delete from heap
	// *
	// * returns
	// * 		if key not found throws exception
	// */
	//void deleteKey(B value);
	///*
	// * decreaseKey
	// * 		Searches for node with value v a
	// *
	// * 	value:
	// * 		value to find and decrease
	// * 	newValue:
	// * 		value to decrease value to
	// * returns
	// * 		if key not found throws exception
	// */
	//void decreaseKey(B value, B newValue);
	///*
	// * size
	// * 		Number of nodes in heap.
	// *
	// * returns
	// *		number of nodes in heap
	// */
	//int size();
	///*
	// * size
	// * 		Checks if empty
	// *
	// * returns
	// *		if empty
	// */
	//bool isEmpty();
	/*
	 * clear
	 * 		Removes all elements
	 *
	 * returns
	 *		none
	 */
	//void clear();
protected:
	/*Utility heap functions*/
	/*
	 * findKey
	 * 		Searches heap for node with value equal to key.
	 * 		v : value in heap to find
	 * 	returns
	 * 	 a pointer to node with value key
	 */
	//static BinomialNode<B>* unionHeap(BinomialNode<B>* heapA, BinomialNode<B>* heapB);
	///* mergeHeap
	// * 		Merges two heaps into a single Binomial heap by adding
	// * 		all siblings of heapA and heapB into a single heap containing
	// * 		all nodes in heapA and heapB.
	// * 		Assumes heapA and heapB siblings are ordered by root order(sibling count)
	// * 		Consolidating two heaps maintains merged ordering
	// *
	// * 	HeapA - root of heap to union with heapB
	// * 	HeapB - root of heap to union with heapA
	// *
	// * 	returns
	// * 		the root of the new heap that contains all heapA and heapB nodes
	// *
	// */
	//static BinomialNode<B>* mergeHeap(BinomialNode<B>* heapA, BinomialNode<B>* heapB);
	///*
	// * order
	// * 		Number of children incident on heap
	// * 	heap
	// * 		pointer to root of Binomial heap
	// * 	returns
	// * 		order or heap
	//*/
	//static int order(BinomialNode<B>* heap);

private:
	/*
	 * head
	 * 		pointer to the head of the heap list where every
	 * 		node is the root node of a heap
	 */
	BinomialNode<B>* head;
};

template <typename B>
class BinomialNode
{
public:
	friend class BinomialHeap<B>;
	BinomialNode(B v, BinomialNode<B>* p = nullptr);

	void addChild(BinomialNode<B>* child);
	//BinomialNode<B>* find(B v);
	//int size(int& i);
	////used to append all nodes visited in this data structure into the other
	//void addTo(BinomialHeap<B>* other);
private:
	B value;
	BinomialNode<B>* sibling, * child, * parent;
	int order;
};
#endif /* BINOMIALHEAP_H_ */
