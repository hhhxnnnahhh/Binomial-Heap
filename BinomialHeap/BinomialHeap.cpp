#include "binomialheap.hpp"
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

template <typename B>
void BinomialHeap<B>::insert(B value) {
	BinomialNode<B>* newNode = new BinomialNode<B>(value);
	head = unionHeap(newNode, head);
}
template <typename B>
B BinomialHeap<B>::getMin() {
	if (head == nullptr) {
		throw std::runtime_error("Cannot get min from empty heap");
	}

	B min = head->value;
	BinomialNode<B>* currentPtr = head, * nextPtr = nullptr;
	while (currentPtr != nullptr) {
		if (currentPtr->value < min) {
			min = currentPtr->value;
		}
		nextPtr = currentPtr->sibling;
		currentPtr = nextPtr;
	}
	return min;
}
template <typename B>
B BinomialHeap<B>::extractMin() {
	if (head == nullptr) {
		throw std::runtime_error("Cannot extract min from empty heap");
	}
	BinomialNode<B>* minPtr = head, * currentPtr = head, * prevPtr = nullptr, * minPrev = nullptr;
	B minVal = head->value;
	while (currentPtr != nullptr) {
		if (currentPtr->value < minVal) {
			minVal = currentPtr->value;
			minPrev = prevPtr;
			minPtr = currentPtr;
		}
		prevPtr = currentPtr;
		currentPtr = currentPtr->sibling;
	}
	if (minPrev != nullptr) {
		minPrev->sibling = minPtr->sibling;
	}
	else {
		head = minPtr->sibling;
	}
	BinomialNode<B>* child = minPtr->child; // (akeno prevPtr belzabt) el leftmost child bta3 el heap (3ashan el heap lama bn delete el head bta3ha btb2a heaps soghayara bas ma3kosa)
	BinomialNode<B>* newHead = nullptr; //3ayez el child el awalany yb2a el sibling bta3o null
	while (child != nullptr) {
		BinomialNode<B>* next = child->sibling;
		child->sibling = newHead; //betkhaly el child yeshawer 3ala ely ablo (newHead)
		newHead = child; //prevPtr = currentPtr
		child = next; //currentPtr = nextPtr
	}
	head = unionHeap(head, newHead);
	return minVal;
}
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

template <typename B>
void BinomialHeap<B>::decreaseKey(B value, B newValue) {
	BinomialNode<B>* node = findKey(value);

	if (!node) {
		throw std::runtime_error("Key not found in heap");
	}

	if (newValue >= node->value) {
		throw std::runtime_error("New value must be smaller than current value");
	}

	node->value = newValue;

	BinomialNode<B>* current = node;
	BinomialNode<B>* parent = current->parent;

	while (parent && current->value < parent->value) {
		// Swap 
		B temp = current->value;
		current->value = parent->value;
		parent->value = temp;

		current = parent;
		parent = current->parent;
	}
}
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
template <typename B>
BinomialNode<B>* BinomialHeap<B>::unionHeap(BinomialNode<B>* heapA, BinomialNode<B>* heapB) {
	BinomialNode<B>* heapU = mergeHeap(heapA, heapB);
	if (heapU) {
		BinomialNode<B>* curr = heapU, * prev, * next;
		prev = nullptr;
		next = nullptr;
		while (curr && curr->sibling != nullptr) {
			next = curr->sibling;
			int orderA, orderB;
			orderA = curr->order;
			orderB = next->order;
			if (orderA == orderB && orderB != order(next->sibling)) {
				if (curr->value < next->value) {

					curr->sibling = next->sibling;
					curr->addChild(next);
					prev = curr;
					curr = curr->sibling;
				}
				else {

					if (prev) {
						prev->sibling = next;
					}
					else {
						heapU = next;
					}
					next->addChild(curr);
					prev = next;
					curr = next->sibling;
				}
			}
			else {

				if (!prev) {
					heapU = curr;
				}

				prev = curr;
				curr = next;
			}
		}
	}
	return heapU;
}
template <typename B>
BinomialNode<B>* BinomialHeap<B>::mergeHeap(BinomialNode<B>* heapA, BinomialNode<B>* heapB) {
	if (!heapA) return heapB;
	if (!heapB) return heapA;
	BinomialNode<B>* head = nullptr;
	BinomialNode<B>* tail = nullptr;
	if (heapA->order <= heapB->order) {
		head = heapA;
		tail = heapA;
		heapA = heapA->sibling;
	}
	else {
		head = heapB;
		tail = heapB;
		heapB = heapB->sibling;
	}
	while (heapA && heapB) {
		if (heapA->order <= heapB->order) {
			tail->sibling = heapA;
			tail = heapA;
			heapA = heapA->sibling;
		}
		else {
			tail->sibling = heapB;
			tail = heapB;
			heapB = heapB->sibling;
		}
	}
	if (heapA) {
		tail->sibling = heapA;
	}
	else if (heapB) {
		tail->sibling = heapB;
	}
	return head;

}
template <typename B>
BinomialNode<B>* BinomialHeap<B>::findKey(B value) {
	if (!head) {
		return nullptr;
	}
	BinomialNode<B>* currentRoot = head;

	while (currentRoot) {  
		BinomialNode<B>* foundNode = currentRoot->find(value);

		if (foundNode) {
			return foundNode;
		}
		currentRoot = currentRoot->sibling;
	}
	return nullptr;
}
template <typename B>
int BinomialHeap<B>::order(BinomialNode<B>* heap) {
	if (heap == nullptr) {
		return -1;
	}
	int degree = 0;
	BinomialNode<B>* child = heap->child;

	while (child != nullptr) {
		degree++;
		child = child->sibling;
	}

	return degree;
}

// Binomial Node
template <typename B>
BinomialNode<B>::BinomialNode(B v, BinomialNode<B>* p) {
	if (p != nullptr) {
		if (v < p->value) {
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
		if (c->value < value) {
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
template <typename T>
BinomialNode<T>* BinomialNode<T>::find(T v) {
	if (value == v) {
		return this;  
	}
	BinomialNode<T>* childPtr = child;  
	while (childPtr) {  
		// Recursively search this child's entire subtree
		BinomialNode<T>* found = childPtr->find(v);

		if (found) {
			return found; 
		}
		childPtr = childPtr->sibling;
	}
	return nullptr; 
}

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
