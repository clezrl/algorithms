#include "BST.hpp"

BST::BST() {
    root = nullptr;
}

BST::~BST() {
    
}

void BST::insert(int data) {
    root = insert(data, root);
}

Node* BST::insert(int data, Node* n) {
    if (!n) return new Node(data);
    if (data > n->data) n->right = insert(data, n->right);
    else if (data < n->data) n->left = insert(data, n->left);
    return n;
}

bool BST::search(int data) {
    return search(data, root);
}

bool BST::search(int data, Node* n) {
    if (!n) return false;
    if (data == n->data) return true;
    if (data > n->data) return search(data, n->right);
    return search(data, n->left);
}

bool BST::is_empty() {
    return (!root);
}

int BST::height() {
    return height(root);
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int BST::height(Node* n) {
    return (!n) ? -1 : max(height(n->left), height(n->right)) + 1;
}

void BST::remove(int data) {

}

Node* BST::remove(int data, Node* n) {
    return n;
}

void BST::clear() {

}

void BST::clear(Node* n) {

}

void BST::preorder(std::ostream& oss) {

}


void BST::inorder(std::ostream& oss) {

}


void BST::postorder(std::ostream& oss) {

}


void BST::preorder(Node* n, std::ostream& oss) {

}

void BST::inorder(Node* n, std::ostream& oss) {

}


void BST::postorder(Node* n, std::ostream& oss) {

}