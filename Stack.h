#pragma once
#include "Includes.h"
#include"Nodes.h"

template<typename T>
class Stack {
private:
	NodeSingle<T>* top;
	int size;

public:
	Stack();
	~Stack();
	void push(T data);
	void pop();
	void clear();
	void print();
	T getTop();
	inline void peek() { cout << this->top->data << '/n'; }
	inline bool isEmpty() { return this->top == NULL; }
	inline int getSize() { return this->size; }

};

template<typename T>
Stack<T>::Stack() {
	this->top = NULL;
	this->size = 0;
}

template<typename T>
Stack<T>::~Stack(){
	clear();
}

template<typename T>
void Stack<T>::push(T data) {
	if (isEmpty()) {
		this->top = new NodeSingle<T>(data, NULL);

		this->size++;
		return;
	}

	NodeSingle<T>* temp = new NodeSingle<T>(data, this->top);
	this->top = temp;
	this->size++;
}

template<typename T>
void Stack<T>::pop() {
	if (isEmpty()) {
		cout << "Stack is empty" << '\n';
		return;
	}

	NodeSingle<T>* temp = this->top;
	this->top = this->top->next;
	this->size--;
	delete temp;
}

template<typename T>
void Stack<T>::clear() {
	NodeSingle<T>* next;
	while (this->top != NULL) {
		next = this->top->next;
		delete this->top;
		this->top = next;
		this->size--;
	}
}

template<typename T>
void Stack<T>::print() {
	NodeSingle<T>* temp = this->top;
	while (temp != NULL) {
		cout << temp->data << ' ';
		temp = temp->next;
	}
	cout << '\n';
}

template<typename T>
T Stack<T>::getTop() {
	T topData = this->top->data;
	NodeSingle<T>* temp = this->top;


	this->top = this->top->next;
	delete temp;

	this->size--;

	return topData;
}