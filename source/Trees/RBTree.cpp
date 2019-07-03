#include "RBTree.hpp"

RBTree::~RBTree() {
    clear();
}

Node* RBTree::insert(int data, Node* n) {
    if (is_empty()) return new Node(data, false);
    if (!n) return new Node(data);
    else if (data < n->data) 
        n->left = insert(data, n->left);
    else if (data > n->data) 
        n->right = insert(data, n->right);
    
    n = fix(n);
    return n;

}

void RBTree::insert(int data) {
    root = insert(data, root);
}

Node* RBTree::rotateRight(Node* node) {
    Node* nLeft = node->left;
    node->left = nLeft->right;
    nLeft->right = node;
    nLeft->color = node->color;
    node->color = true;
    return nLeft;
}

Node* RBTree::rotateLeft(Node* node) {
    Node* nRight = node->right;
    node->right = nRight->left;
    nRight->left = node;
    nRight->color = node->color;
    node->color = true;
    return nRight;
}

void RBTree::flipColors(Node* node) {
    node->color = true;
    node->left->color = false;
    node->right->color = false;
}

Node* RBTree::fix(Node* temp) {
    if (!temp->left || !temp->right) return temp;
    if (temp->right->color && !temp->left->color) temp = rotateLeft(temp);
    if (temp->left->color && !temp->right->color) temp = rotateRight(temp);
    if (temp->left->color && temp->right->color) flipColors(temp);
    preorder();
    return temp;
}

// Node* RBTree::moveRedLeft(Node* temp) {

// } 

// Node* RBTree::moveRedRight(Node* temp) {

// }

bool RBTree::search(int data, Node* n) {
  if (!n)
    return false;
  else if (data == n->data)
    return true;
  else if (data < n->data)
    return search(data, n->left);
  else
    return search(data, n->right);
}

Node* RBTree::remove(int data, Node* n) {
  return n;
}

inline int max(int a, int b) {
  return (a > b) ? a : b;
}

int RBTree::height(Node* n) {
    return (!n) ? -1 : 1 + max(height(n->left), height(n->right));
  if (!n)
    return -1;
  return 1 + max(height(n->left), height(n->right));
}

int RBTree::height() {
    return height(root);
}

void RBTree::clear(Node* n) {
    if (!n)
        return;
    clear(n->left);
    clear(n->right);
    delete n;
}

void RBTree::clear() {
    clear(root);
    root = nullptr;
}

void RBTree::preorder(Node* n, std::ostream& oss) {
  if (!n)
    return;

  oss << n->data << ", ";

  preorder(n->left, oss);
  preorder(n->right, oss);
}

void RBTree::preorder(std::ostream& oss) {
    preorder(root, oss);
    oss << std::endl;
}

void RBTree::inorder(Node* n, std::ostream& oss) {
    if (!n) return;
    inorder(n->left, oss);
    oss << n->data << ", ";
    inorder(n->right, oss);
}

void RBTree::inorder(std::ostream& oss) {
    inorder(root, oss);
    oss << std::endl;
}

void RBTree::postorder(Node* n, std::ostream& oss) {
    if (!n) return;
    postorder(n->left, oss);
    postorder(n->right, oss);
    oss << n->data << ", ";
}

void RBTree::postorder(std::ostream& oss) {
    postorder(root, oss);
    oss << std::endl;
}

Node* RBTree::deleteMax(Node* temp) {
    return temp;
}

void RBTree::deleteMax() {

}

Node* RBTree::deleteMin(Node* temp) {
    return temp;
}

void RBTree::deleteMin() {

}

int RBTree::min(Node* subtree, bool first) {
    return 1;
}