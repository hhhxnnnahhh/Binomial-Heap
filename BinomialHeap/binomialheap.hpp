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
	//~BinomialHeap();

	void insert(B value);
	B getMin();
	B extractMin();
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
	void decreaseKey(B value, B newValue);
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
	static BinomialNode<B>* unionHeap(BinomialNode<B>* heapA, BinomialNode<B>* heapB);
	static BinomialNode<B>* mergeHeap(BinomialNode<B>* heapA, BinomialNode<B>* heapB);
	BinomialNode<B>* findKey(B value);
	static int order(BinomialNode<B>* heap);

private:
	BinomialNode<B>* head;
};

template <typename B>
class BinomialNode
{
public:
	friend class BinomialHeap<B>;
	BinomialNode(B v, BinomialNode<B>* p = nullptr);

	void addChild(BinomialNode<B>* child);
	BinomialNode<B>* find(B v);
	//int size(int& i);
	////used to append all nodes visited in this data structure into the other
	//void addTo(BinomialHeap<B>* other);
private:
	B value;
	BinomialNode<B>* sibling, * child, * parent;
	int order;
};
#endif /* BINOMIALHEAP_H_ */