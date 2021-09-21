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

bool search(nodeBST* root, ll num) {

	if (root == NULL)
		return false;
	else if (root->key == num)
		return true;
	else if (root->key >= num)
		return search(root->left, num);
	else
		return search(root->right, num);

}

int main() {

	nodeBST* root = NULL;
	ll n1, n2, k, count = 0;

	cin >> n1;
	ll a[n1];

	for (ll i = 0; i < n1; i++)
		cin >> a[i];

	cin >> n2;

	for (ll i = 0; i < n2; i++) {
		ll temp;
		cin >> temp;
		root = insert(root, temp);
	}

	cin >> k;

	for (ll i = 0; i < n1; i++) {
		bool temp1 = search(root, (k - a[i]));
		if (temp1 == true)
			count++;
	}

	cout << count;

}
