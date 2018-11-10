#include "stdafx.h"
#include "Tree.h"

bool Tree::insert(int newVal)
{
	Node* it;
	it = root;
	cout << "Inserting " << newVal << endl;
	while (it != nullptr) {
		// check same
		if (it->data == newVal) {
			cout << "Insert False" << endl;
			return false;
		}
		// check larger or smaller
		if (it->data > newVal) {
			cout << "Check left" << endl;
			if (it->left != nullptr) {
				it = it->left;
			}
			else {
				it->left = new Node(newVal);
				cout << "Insert True" << endl;
				count++;
				return true;
			}
		}
		else if (it->data < newVal) {
			cout << "Check right" << endl;
			if (it->right != nullptr) {
				it = it->right;
			}
			else {
				it->right = new Node(newVal);
				cout << "Insert True" << endl;
				count++;
				return true;
			}
		}
	}
	// check empty
	if (root == nullptr) {
		root = new  Node(newVal);
		cout << "Insert empty tree" << endl;
		cout << "Insert True" << endl;
		count++;
		return true;
	}
	return false;
}

void Tree::print(ostream & ostr, Node * curNode) const
{
	if (curNode->left != nullptr) {
		print(ostr, curNode->left);
		ostr << curNode->data << " ";
		cout << curNode->data << " ";
	}
	else {
		ostr << curNode->data << " ";
		cout << curNode->data << " ";
	}
	if (curNode->right != nullptr) {
		print(ostr, curNode->right);
	}
}

ostream & operator<<(ostream & str, const Tree & tree)
{
	tree.print(str, tree.root);
	str << "Count: " << tree.count;
	cout << "Count: " << tree.count << endl;
	return str;
}
