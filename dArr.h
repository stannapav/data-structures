#pragma once
#include<iostream>

template<typename T>
class dArr
{
private:
	int cap;
	int numOfEl;
	T** arr;

public:
	dArr();
	~dArr();
	T& operator[](int index);
	void initialize();
	void expend();
	void addEl(T el);
	inline T& getEl(int index) { return *this->arr[index]; }
	void print();

};

template<typename T>
dArr<T>::dArr()
{
	this->cap = 3;
	this->numOfEl = 0;
	this->arr = new T * [this->cap];
	initialize();
}

template<typename T>
dArr<T>::~dArr()
{
	for (int i = 0; i < this->cap; i++)
		delete this->arr[i];
	delete[] this->arr;
}

template<typename T>
T& dArr<T>::operator[](int index)
{
	if (index < 0 || index >= this->nOfEl)
		throw "Bad index";

	return *this->arr[index];
}

template<typename T>
void dArr<T>::initialize()
{
	for (int i = this->numOfEl; i < this->cap; i++)
		this->arr[i] = nullptr;
}

template<typename T>
void dArr<T>::expend()
{
	this->cap *= 2;

	T** temp = new T * [this->cap];
	for (int i = 0; i < this->numOfEl; i++)
		temp[i] = new T(*this->arr[i]);

	delete[] arr;
	this->arr = temp;
	initialize();
}

template<typename T>
void dArr<T>::addEl(T el)
{
	if (this->numOfEl >= this->cap)
		expend();

	this->arr[this->numOfEl++] = new T(el);
}

template<typename T>
void dArr<T>::print()
{
	for (int i = 0; i < this->numOfEl; i++)
		std::cout << *this->arr[i] << ' ';
	std::cout << '\n';
}