#pragma once
#include"Includes.h"

struct Node{
	int data;
	Node* left;
	Node* right;

	Node(int data = 0, Node* left = NULL, Node* right = NULL) {
		this->data = data;
		this->left = left;
		this->right = right;
	}
};

class Tree{
private:
	Node* root;

	void del(Node*& node);
public:
	Tree();
	~Tree();
	void add(int data, Node* parent = NULL);
	void print(Node* node = NULL, bool a = false);
	void delTree();
	
};