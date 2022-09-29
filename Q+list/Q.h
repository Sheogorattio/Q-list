#pragma once
#include <iostream>
using namespace std;
template<class T>
struct elem {
	T data;
	elem* next;
	elem* prev;
};

template <class T>
class Q
{
	elem<T>* head;
	elem<T>* tail;
	int count;
public:
	Q();
	~Q();
	elem<T> extract();
	void add(T c);
	bool isEmpty();
	void clone(Q<T>& obj);
	void print();
	int getCount();
	T getFirst();
};

template<class T>
Q<T>::Q() {
	head = tail = NULL;
	count = 0;
}
template<class T>
Q<T>::~Q() {
	for (int i = 0; i < count;) {
		extract();
	}
}
template<class T>
elem<T> Q<T>::extract() {
	if (isEmpty()) {
		return *head;
	}
	elem<T> _temp = *head;
	elem<T>* temp = head;
	if (count == 1) {
		delete head;
		head = tail = nullptr;
		count--;
		return _temp;
	}
	head = head->next;
	delete temp;
	count--;
	return _temp;
}
template<class T>
void Q<T>::add(T c) {
	elem<T>* tmp = new elem<T>;
	tmp->data = c;
	tmp->next = nullptr;
	tmp->prev = nullptr;
	if (count == 0) {
		head = tail = tmp;
	}
	else {
		elem<T>* last = tail;
		tail = tmp;
		last->next = tmp;
		tmp->prev = last;
	}
	count++;
}
template<class T>
bool Q<T>::isEmpty() {
	return count == 0;
}
template<class T>
void Q<T>::print() {
	elem<T> tmp = *head;
	for (int i = 0; i < count; i++) {
		if (tmp.next != 0) {
			cout << tmp.data << " ";
			tmp = *tmp.next;
		}
	}
	cout << tmp.data;
}
template<class T>
int Q<T>::getCount() {
	return count;
}
template<class T>
T Q<T>::getFirst() {
	return head->data;
}
template<class T>
void Q<T>::clone(Q<T>& obj) {
	elem<T> tmp = *head;
	for (int i = 0; i < count; i++) {
		if (tmp.next != 0) {
			obj.add(tmp.data);
			tmp = *tmp.next;
		}
	}
	obj.add(tmp.data);
}