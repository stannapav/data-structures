#pragma once

template<typename T>
struct NodeSingle {
	T data;
	NodeSingle<T>* next;

	NodeSingle() {
	}

	NodeSingle(T data, NodeSingle<T>* next) {
		this->data = data;
		this->next = next;
	}

	/*NodeSingle<T> operator=(T* obj) {
		NodeSingle<T>* temp = NULL;

		temp->data = *obj.data;
		temp->next = *obj.next;

		return temp;
	}*/
};

template<typename T>
struct NodeDouble{
	T data;
	T* prev, next;

	NodeDouble(T data, T* prev, T* next) {
		this->data = data;
		this->prev = prev;
		this->next = next;
	}
};