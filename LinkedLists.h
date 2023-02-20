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
	void changeData(int index, T data);
	void delFront();
	void delBack();
	void delAll();
	NodeSingle<T>& getAt(int index);
	inline int getSize() { return this->size; }
	
};

template<typename T>
class ListDouble {

};

template<typename T>
ListSingle<T>::ListSingle(){
	this->head = NULL;
	this->size = 0;
}

template<typename T>
void ListSingle<T>::print(){
	NodeSingle<T>* last = head;
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

	NodeSingle<T>* last = head;
	while (last->next != NULL) {
		last = last->next;
	}

	NodeSingle<T>* temp = new NodeSingle<T>(data, NULL);

	last->next = temp;
	this->size++;
}

template<typename T>
void ListSingle<T>::addAtPosition(int index, T data){
	if (this->size <= index) {
		cout << "bad index";
		return;
	}

	NodeSingle<T>* last = this->head;
	for (int i = 0; last->next->next != NULL && i < index; i++) {
		last = last->next;
	}

	NodeSingle<T>* temp = new NodeSingle<T>(data, last->next);

	last->next = temp;
	last = temp;
	this->size++;
}

template<typename T>
void ListSingle<T>::changeData(int index, T changeData){
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

template<typename T>
void ListSingle<T>::delFront(){
	if (this->head != NULL) {
		NodeSingle<T>* temp = this->head->next;

		delete this->head;

		this->head = temp;
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
	}
}

template<typename T>
NodeSingle<T>& ListSingle<T>::getAt(int index){
	if (this->size <= index) {
		throw("Bad index");
	}

	NodeSingle<T>* last = this->head;
	for (int i = 0; last->next != NULL && i < index; i++) {
		last = last->next;
	}

	return *last;
}
