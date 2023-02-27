#pragma once
#include "Includes.h"
#include"Nodes.h"

template<typename T>
class Queue {
private:
	NodeSingle<T>* head;
	int size;

public:
	Queue();
	void pop();
	void push(T data);
	void clear();
	void print();
	T getData();
	inline int getSize() { return this->size; }
	inline bool isEmpty() { return this->head == NULL; }

};

template<typename T>
Queue<T>::Queue() {
	this->head = NULL;
	this->size = 0;
}

template<typename T>
void Queue<T>::pop() {
	if (isEmpty()) {
		cout << "Queue is empty" << '\n';
		return;
	}

	NodeSingle<T>* temp = this->head;
	this->head = this->head->next;
	this->size--;
	delete temp;
}

template<typename T>
void Queue<T>::push(T data) {
	if (isEmpty()) {
		this->head = new NodeSingle<T>(data, NULL);
		this->size++;
		return;
	}

	NodeSingle<T>* last = this->head;
	while (last->next != NULL)
		last = last->next;

	NodeSingle<T>* temp = new NodeSingle<T>(data, NULL);

	last->next = temp;
	this->size++;
}

template<typename T>
void Queue<T>::clear() {
	if (isEmpty())
		return;

	NodeSingle<T>* next = NULL;
	while (this->head != NULL) {
		next = this->head->next;
		delete this->head;
		this->head = next;
		this->size--;
	}
}

template<typename T>
void Queue<T>::print() {
	NodeSingle<T>* last = this->head;
	while (last != NULL) {
		cout << last->data << ' ';
		last = last->next;
	}
	cout << '\n';
}

template<typename T>
T Queue<T>::getData() {
	T data = this->head->data;
	NodeSingle<T>* temp = this->head;

	this->head = this->head->next;
	delete temp;

	this->size--;

	return data;
}
