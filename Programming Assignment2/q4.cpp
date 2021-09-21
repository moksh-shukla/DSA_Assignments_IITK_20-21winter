#include<iostream>

using namespace std;

#define ll long long int

struct nodeBST
{
	ll key;
	nodeBST* right;
	nodeBST* left;
};


nodeBST* defnodeNew(ll key) {
	nodeBST* new_node = new nodeBST();
	new_node->key = key;
	new_node->left = new_node->right = NULL;
	return new_node;
}

nodeBST* insert(nodeBST* root, ll key) {
	if (root == NULL) {
		root = defnodeNew(key);
		return root;
	}
	else if (key <= root->key) {
		root->left = insert(root->left, key);
	}
	else if (key > root->key) {
		root->right = insert(root->right, key);
	}
	return root;
}

void pathNode(nodeBST* root, ll node1, ll node2) {

	ll count1 = 0, count2 = 0;
	nodeBST* intersectl;
	nodeBST* intersectr;

	while (1) {
		if (node1 < root->key && node2 < root->key)
			root = root->left;
		else if (node1 > root->key && node2 > root->key)
			root = root->right;
		else {
			intersectl = root;
			intersectr = root;
			break;
		}
	}

	while (1) {
		if (node1 > intersectl->key) {
			intersectl = intersectl->right;
			count1++;
		}
		else if (node1 < intersectl->key) {
			intersectl = intersectl->left;
			count1++;
		}
		else if (node1 == intersectl->key) {
			break;
		}

	}

	while (1) {
		if (node2 > intersectr->key) {
			intersectr = intersectr->right;
			count2++;
		}
		else if (node2 < intersectr->key) {
			intersectr = intersectr->left;
			count2++;
		}
		else if (node2 == intersectr->key) {
			break;
		}

	}

	cout << count1 + count2 + 1;
}

int main() {
	nodeBST* root = NULL;
	ll n, k;
	cin >> n >> k;
	while (n--) {
		ll temp;
		cin >> temp;
		root = insert(root, temp);
	}
	while (k--) {
		ll node1, node2;
		cin >> node1 >> node2;
		pathNode(root, node1, node2);
		cout << "\n";
	}
}