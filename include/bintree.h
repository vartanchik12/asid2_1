#pragma once
#include<iostream>
#include<set>

using namespace std;

int tab = 0;

template<typename T>
struct Node {
	T data;
	Node* left;
	Node* right;
	Node(T value): data(value),left(nullptr),right(nullptr){}
};

template<typename T>
class BinSearchTree {
private:
	Node<T>* _root;
public:
	BinSearchTree() {
		_root = nullptr;
	}

	BinSearchTree(T value) {
		_root = new Node<T>(value);
	}

	BinSearchTree(const BinSearchTree& other) {
		_root = copyTree(other._root); 
	}
	~BinSearchTree() {
		deleteTree(_root);
		_root = nullptr;
	}

	BinSearchTree& operator=(const BinSearchTree& other) {
		if (this != &other) {
			deleteTree(_root);
			_root = copyTree(other._root);
		}
		return *this;
	}

	void print() {
		printTree(_root);
	}

	
	void insert(T val) {
		if (_root == nullptr) {
			this->_root= new Node<T>(val);
		}
		else {
			this->insert(val, this->_root);
		}
	}

	

	
	void insert(T val, Node<T>* node) {

		if (val == node->data) {
			return;
		}

		if (val < node->data) {
			if (node->left == nullptr) {
				node->left = new Node<T>(val);
			}
			else {
				this->insert(val, node->left);
			}
		}
		else {
			if (node->right == nullptr) {
				node->right = new Node<T>(val);
			}
			else {
				this->insert(val, node->right);
			}
		}
	}

	bool contains(int val) {
		return contains(val, this->_root);
	}

	bool contains(T val, Node<T>* node) {
		if (node == nullptr) {
			return false;
		}
		else if (val == node->data) {
			return true;
		}
		else if (val < node->data) {
			return this->contains(val, node->left);
		}
		else {
			return this->contains(val, node->right);
		}
	}

	Node<T>* getMin(Node<T>* current) {
		if (current == nullptr) return nullptr;
		if (node->left == nullptr) return current;
		return getMin(node->left);
	}

	Node<T>* getMax(Node<T>* current) {
		if (current == nullptr) return nullptr;
		if (current->right == nullptr) return current;
		return getMax(current->right);
	}
	void erase(T value) {
		_root = eraseNode(_root, value);
	}

	void deleteTree(Node<T>* current) {
		if (current) {
			deleteTree(current->left);
			deleteTree(current->right);
			delete current;
		}
	}

	void printTree(Node<T>* current)
	{
		if (current)
		{
			tab += 5;
			printTree(current->right);
			for (int i = 0; i < tab; i++) {
				cout << " ";
			}
			cout << current->data << endl;
			printTree(current->left);
			tab -= 5;
			return;
		}
	}

	Node<T>* copyTree() {
		this->copyTree(this->getRoot);
	}
	Node<T>* copyTree(Node<T>* other) {
		if (other) {
			Node<T>* current = new Node<T>(other->data);
			current->left = copyTree(other->left);
			current->right = copyTree(other->right);
			return current;
		}
		else {
			return nullptr;
		}
	}

	Node<T>* eraseNode(Node<T>* current, T key) {
		if (current == nullptr) {
			return nullptr;
		}
		else if (current->data > key) {
			current->left = eraseNode(current->left, key);
		}
		else if (current->data < key) {
			current->right = eraseNode(current->right, key);
		}
		else {
			if (current->left == nullptr || current->right == nullptr) {
				if (current->left == nullptr) { 
					current = current->right;
				}
				else {
					current = current->left;
				}
			}
			else {
				Node<T>* maxinL = getMax(current->left);
				current->data = maxinL->data;
				current->right=eraseNode(current->right,key)
			}
		}
		return current;
	}

	Node<T>* getRoot() const {
		return _root;
	}
};


template<typename T>
set<T> unification(BinSearchTree<T>& first, BinSearchTree<T>& second, set<T>& elements) {
	insertl(first.getRoot(), elements);
	insertl(second.getRoot(), elements);
	return elements;
}
template<typename T>
void insertl(Node<T>* current, set<T>& elements) {
	if (current) {
		elements.insert(current->data);
		insertl(current->left, elements);
		insertl(current->right, elements);
	}
}
template <typename T>
void unificationTrees(BinSearchTree<T>& first, BinSearchTree<T>& second) {
	set<T> elements;
	unification(first, second, elements);
	cout << "Unification: ";
	for (int i : elements) {
		cout << i << " ";
	}
}

template<typename T>
set<T> BinDiffernce(BinSearchTree<T>& first, BinSearchTree<T>& second,set<T>& elements) {
	insertdif(first.getRoot(), second, elements);
	insertdif(second.getRoot(), first, elements);
	return elements;
}

template<typename T>
void insertdif( Node<T>* current, BinSearchTree<T>& other, set<T>& result) {
	if (current) {
		if (!(other.contains(current->data))) {
			result.insert(current->data);
		}
		insertdif(current->left, other, result);
		insertdif(current->right, other, result);
	}
}
template<typename T>
void BinDifferenceTrees(BinSearchTree<T>& first, BinSearchTree<T>& second) {
	set<T> elements;
	BinDiffernce(first, second, elements);
	cout << "BinDifference:";
	for (int i : elements) {
		cout << i << " ";
	}
}