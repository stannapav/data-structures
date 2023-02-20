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
};

template<typename T>
struct NodeDouble{
	T data;
	NodeDouble<T>* prev;
	NodeDouble<T>* next;

	NodeDouble() {
	}

	NodeDouble(T data, NodeDouble<T>* prev, NodeDouble<T>* next) {
		this->data = data;
		this->prev = prev;
		this->next = next;
	}
};