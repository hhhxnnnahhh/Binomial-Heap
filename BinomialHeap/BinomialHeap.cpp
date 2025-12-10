#include "binomial_heap.hpp"
#include <iostream>
using namespace std;

template <typename B>
BinomialHeap<B>::BinomialHeap() {
	head = nullptr;
}
template <typename B>
BinomialHeap<B>::BinomialHeap(const BinomialHeap<B>& other) {
	*this = other;
}
//template <typename B>
//BinomialHeap<B>& BinomialHeap<B>::operator=(const BinomialHeap<B>& other) {
//	
//}
//template <typename B>
//BinomialHeap<B>::~BinomialHeap() {
//	clear();
//}
///*
// * insert
// * 		Creates a singleton heap node with value v and
// * 		 unions it with the head
// * 	value:
// * 		value to insert into heap
// *
// */
//template <typename B>
//void BinomialHeap<B>::insert(B value) {
//
//}
///*
// * getMin
// * 		Searches the heap list for the node with minimum value
// *
// * returns
// * 		minimum value in heap list
// */
//template <typename B>
//B BinomialHeap<B>::getMin() {
//
//}
///*
// * extractMin
// * 		Removes the heap list for node with minimum value
// * 		and unions minimum node's children with heap list
// *
// * returns
// * 		minimum value in heap list
// */
//template <typename B>
//B BinomialHeap<B>::extractMin() {
//
//}
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
//template <typename B>
//void BinomialHeap<B>::deleteKey(B value) {
//
//}
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
//template <typename B>
//void BinomialHeap<B>::decreaseKey(B value, B newValue) {
//
//}
///*
// * size
// * 		Number of nodes in heap.
// *
// * returns
// *		number of nodes in heap
// */
//template <typename B>
//int BinomialHeap<B>::size() {
//
//}
///*
// * size
// * 		Checks if empty
// *
// * returns
// *		if empty
// */
//template <typename B>
//bool BinomialHeap<B>::isEmpty() {
//	retuen(head == 0);
//}
///*
// * clear
// * 		Removes all elements
// *
// * returns
// *		none
// */
//template <typename B>
//void BinomialHeap<B>::clear() {
//	delete head;
//	head = nullptr;
//}
//
//template <typename B>
//BinomialNode<B>* BinomialHeap<B>::unionHeap(BinomialNode<B>* heapA, BinomialNode<B>* heapB) {
//
//}
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
//template <typename B>
//BinomialNode<B>* BinomialHeap<B>::mergeHeap(BinomialNode<B>* heapA, BinomialNode<B>* heapB) {
//
//}
///*
// * order
// * 		Number of children incident on heap
// * 	heap
// * 		pointer to root of Binomial heap
// * 	returns
// * 		order or heap
//*/
//template <typename B>
//int BinomialHeap<B>::order(BinomialNode<B>* heap) {
//
//}

// Binomial Node

template <typename B>
BinomialNode<B>::BinomialNode(B v, BinomialNode<B>* p) {
	if(p != nullptr){
		if(v < p->value){
			cout << "Error: child value less than parent value!(constructor)" << endl;
			return;
		}
	}
	parent = p;
	value = v;
	order = 0;
	child = nullptr;
	sibling = nullptr;

}


template <typename B>
void BinomialNode<B>::addChild(BinomialNode<B>* c) {
	if (c != nullptr) {
		if(c->value < value){
			cout << "Error: child value less than parent value!(addChild func)" << endl;
			return;
		}
		if (child == nullptr) {
			
			child = c;
		}
		else {
			BinomialNode<B>* temp;
			temp = child;
			while (temp->sibling != nullptr) {
				temp = temp->sibling;
			}
			temp->sibling = c;
		}
		c->sibling = nullptr;
		c->parent = this;
		order++;
	}
}
//template <typename B>
//BinomialNode<B>* BinomialNode<B>::find(B v) {
//
//}
//template <typename B>
//int BinomialNode<B>::size(int& i) {
//
//}
////used to append all nodes visited in this data structure into the other
//template <typename B>
//void BinomialNode<B>::addTo(BinomialHeap<B>* other) {

//}





template class BinomialNode<int>;
template class BinomialHeap<int>;

template class BinomialNode<float>;
template class BinomialHeap<float>;

template class BinomialNode<char>;
template class BinomialHeap<char>;
