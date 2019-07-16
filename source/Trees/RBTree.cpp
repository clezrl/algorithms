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
    
    return fix(n);

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
  
    if (temp->right && temp->right->color) temp = rotateLeft(temp);
    if (temp->left && temp->left->left && temp->left->color && temp->left->left->color) temp = rotateRight(temp);
    if (temp->left && temp->right && temp->left->color && temp->right->color) flipColors(temp);
    
    return temp;
}

Node* RBTree::moveRedLeft(Node* temp) {
  flipColors(temp);
  if (temp->right->left && temp->right->left->color) {
    rotateLeft(temp);
    flipColors(temp);
  }
  return temp;

} 

Node* RBTree::moveRedRight(Node* temp) {
  flipColors(temp);
  if (temp->left->left && temp->left->left->color) {
    rotateRight(temp);
    flipColors(temp);
  }
  return temp;
}

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
  if (n->right->left) { 
    n->data = n->right->left->data;
    n = deleteMin(n->right);
  }

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
    if (temp->left && temp->left->color) rotateRight(temp);
    if (!temp->right) {
      delete temp;
      return nullptr;
    }
    if (temp->right && !temp->right->color && temp->right->left && !temp->right->left->color)
      temp = moveRedRight(temp);
    temp = deleteMax(temp->left);
    return fix(temp);
}

void RBTree::deleteMax() {
  root = deleteMax(root);
  root->color = false;
}

Node* RBTree::deleteMin(Node* temp) {
    if (temp->left == nullptr) {
      delete temp;
      return nullptr;
    }

    if (temp->left && temp->left->color && temp->left->left && temp->left->left->color) 
      temp = moveRedLeft(temp->left);
    
    temp = deleteMin(temp->left);
    return fix(temp);
}

void RBTree::deleteMin() {
  root = deleteMin(root);
  root->color = false;
}

int RBTree::min(Node* subtree, bool first) {
    return 1;
}