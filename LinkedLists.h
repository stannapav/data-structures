#pragma once
#include"Includes.h"
#include"Nodes.h"

template<typename T>
class ListSingle {
private:
	NodeSingle<T>* head;
	int size;

public:
	ListSingle();

	void print();

	void addFront(T data);
	void addBack(T data);
	void addAtPosition(int index, T data);

	void delFront();
	void delBack();
	void delAll();

	const NodeSingle<T>& getAt(int index);
	inline int getSize() { return this->size; }
	void changeData(int index, T changeData);
	
};

template<typename T>
class ListDouble {
private:
	NodeDouble<T>* head;
	int size;

public:
	ListDouble();

	void print();
	void printRevers();

	void addFront(T data);
	void addBack(T data);
	void addAtPosition(int index, T data);

	void delFront();
	void delBack();
	void delAll();

	void changeData(int index, T changeData);
	inline int getSize() { return this->size; }
	const NodeDouble<T>& getAt(int index);
};

template<typename T>
ListSingle<T>::ListSingle(){
	this->head = NULL;
	this->size = 0;
}

template<typename T>
void ListSingle<T>::print(){
	NodeSingle<T>* last = this->head;
	while (last != NULL) {
		cout << last->data << ' ';
		last = last->next;
	}
	cout << '\n';
}

template<typename T>
void ListSingle<T>::addFront(T data){
	if (this->size == 0) {
		this->head = new NodeSingle<T>(data, NULL);
		this->size++;
		return;
	}

	NodeSingle<T>* temp = new NodeSingle<T>(data, this->head);

	this->head = temp;
	this->size++;
}

template<typename T>
void ListSingle<T>::addBack(T data){
	if (this->size == 0) {
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
void ListSingle<T>::addAtPosition(int index, T data){
	if (this->size <= index)
		throw("Bad index");

	NodeSingle<T>* last = this->head;
	for (int i = 0; last->next->next != NULL && i < index; i++)
		last = last->next;

	NodeSingle<T>* temp = new NodeSingle<T>(data, last->next);

	last->next = temp;
	last = temp;
	this->size++;
}

template<typename T>
void ListSingle<T>::delFront(){
	if (this->head != NULL) {
		NodeSingle<T>* temp = this->head->next;

		delete this->head;
		this->head = temp;
		this->size--;
	}
}

template<typename T>
void ListSingle<T>::delBack(){
	if (this->head == NULL)
		return;

	NodeSingle<T>* last = this->head;
	while (last->next->next != NULL)
		last = last->next;

	delete last->next;
	last->next = NULL;
	this->size--;
}

template<typename T>
void ListSingle<T>::delAll(){
	if (this->head == NULL)
		return;

	NodeSingle<T>* nextNode = NULL;
	while (this->head != NULL) {
		nextNode = this->head->next;
		delete this->head;
		this->head = nextNode;
		this->size--;
	}
}

template<typename T>
const NodeSingle<T>& ListSingle<T>::getAt(int index){
	if (this->size <= index)
		throw("Bad index");

	NodeSingle<T>* last = this->head;
	for (int i = 0; last->next != NULL && i < index; i++)
		last = last->next;

	return *last;
}

template<typename T>
void ListSingle<T>::changeData(int index, T changeData) {
	if (this->size <= index) {
		cout << "bad index";
		return;
	}

	NodeSingle<T>* temp = this->head;
	for (int i = 0; temp->next != NULL && i < index; i++) {
		temp = temp->next;
	}

	temp->data = changeData;
}


/// ////////////////////////////////////////////////


template<typename T>
ListDouble<T>::ListDouble(){
	this->head = NULL;
	this->size = 0;
}

template<typename T>
void ListDouble<T>::print(){
	NodeDouble<T>* last = this->head;
	while (last != NULL) {
			cout << last->data << ' ';
			last = last->next;
	}
	cout << '\n';

}

template<typename T>
void ListDouble<T>::printRevers(){
	NodeDouble<T>* last = this->head;
	while (last->next != NULL)
		last = last->next;

	while (last != NULL) {
		cout << last->data << ' ';
		last = last->prev;
	}
	cout << '\n';
}

template<typename T>
void ListDouble<T>::addFront(T data){
	if (this->size == 0) {
		this->head = new NodeDouble<T>(data, NULL, NULL);
		this->size++;
		return;
	}

	NodeDouble<T>* temp = new NodeDouble<T>(data, NULL, this->head);

	this->head->prev = temp;
	this->head = temp;
	this->size++;
}

template<typename T>
void ListDouble<T>::addBack(T data){
	if (this->size == 0) {
		this->head = new NodeDouble<T>(data, NULL, NULL);
		this->size++;
		return;
	}

	NodeDouble<T>* last = this->head;
	while (last->next != NULL)
		last = last->next;

	NodeDouble<T>* temp = new NodeDouble<T>(data, last, NULL);

	last->next = temp;
	this->size++;
}

template<typename T>
void ListDouble<T>::addAtPosition(int index, T data){
	if (this->size <= index)
		throw("Bad index");

	if (index == 0) {
		addFront(data);
		return;
	}

	NodeDouble<T>* last = this->head;
	for (int i = 0; last->next != NULL && i < index; i++)
		last = last->next;

	NodeDouble<T>* temp = new NodeDouble<T>(data, last->prev, last);

	last->prev->next = temp;
	last->prev = temp;
	this->size++;
}

template<typename T>
void ListDouble<T>::delFront(){
	if (this->head != NULL) {
		NodeDouble<T>* temp = this->head->next;

		delete this->head;
		this->head = temp;
		temp->prev = NULL;
		this->size--;
	}
}

template<typename T>
void ListDouble<T>::delBack(){
	if (this->head == NULL)
		return;

	NodeDouble<T>* last = this->head;
	while (last->next != NULL)
		last = last->next;

	last->prev->next = NULL;
	delete last;
	this->size--;
}

template<typename T>
void ListDouble<T>::delAll(){
	if (this->head == NULL)
		return;

	NodeDouble<T>* nextNode = NULL;
	while (this->head != NULL) {
		nextNode = this->head->next;
		delete this->head;
		this->head = nextNode;
		this->size--;
	}
}

template<typename T>
void ListDouble<T>::changeData(int index, T changeData){
	if (this->size <= index) {
		cout << "bad index";
		return;
	}

	NodeDouble<T>* temp = this->head;
	for (int i = 0; temp->next != NULL && i < index; i++) {
		temp = temp->next;
	}

	temp->data = changeData;
}

template<typename T>
const NodeDouble<T>& ListDouble<T>::getAt(int index){
	if (this->size <= index)
		throw("Bad index");

	NodeDouble<T>* last = this->head;
	for (int i = 0; last->next != NULL && i < index; i++)
		last = last->next;

	return *last;
}
