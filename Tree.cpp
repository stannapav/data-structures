#include "Tree.h"

Tree::Tree(){
    this->size = 0;
	this->root = NULL;
}

Tree::~Tree(){
    del(this->root);
}

void Tree::add(int data, Node* parent){
	if (this->root == NULL) {
		this->root = new Node(data);
        this->size++;
		return;
	}

    if (parent == NULL)
        parent = this->root;

    if (parent->data > data){
        if (parent->left == NULL){
            parent->left = new Node(data);
            this->size++;
            return;
        }
        else add(data, parent->left);
    }

    if (parent->data < data) {
        if (parent->right == NULL) {
            parent->right = new Node(data);
            this->size++;
            return;
        }
        else add(data, parent->right);
    }
}

void Tree::print(Node* node, long n, bool notRoot) {
    if (notRoot == false) {
        node = this->root;
        n = this->size;
    }

    if (node != NULL) {
        print(node->right, n + 5, true);
        for (long i = 0; i < n; i++)
            cout << ' ';
        cout << node->data << '\n';
        print(node->left, n + 5, true);
    }
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