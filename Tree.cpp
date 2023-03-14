#include "Tree.h"

Tree::Tree(){
	this->root = NULL;
}

Tree::~Tree(){
    del(this->root);
}

void Tree::add(int data, Node* parent){
	if (this->root == NULL) {
		this->root = new Node(data);
		return;
	}

    if (parent == NULL)
        parent = this->root;

    if (parent->data > data){
        if (parent->left == NULL){
            parent->left = new Node(data);
            return;
        }
        else add(data, parent->left);
    }

    if (parent->data < data) {
        if (parent->right == NULL) {
            parent->right = new Node(data);
            return;
        }
        else add(data, parent->right);
    }
}

void Tree::print(Node* node, bool a){
    if (a == false)
         node = this->root;

    if (node == NULL) return;

    cout << node->data << ' ';
    print(node->left, true);
    print(node->right, true);
}

void Tree::del(Node*& node){
    if (node == NULL) return;

    if (node->left == NULL && node->right == NULL) {
        delete node;
        return;
    }

    if (node->left != NULL)
        del(node->left);

    if (node->right != NULL)
        del(node->right);

    delete node;
}

void Tree::delTree() {
    del(this->root);
    this->root = NULL;
}