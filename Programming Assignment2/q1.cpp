#include<iostream>

using namespace std;

#define ll long long int

ll k;
ll mod = -1e7;
ll mod1 = 1e8;

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

// BST search
ll search(nodeBST* root, ll num) {
	if (root == NULL)
		return -1e7;

	else if (root->key < num) {
		ll temp = search(root->right, num);
		if (temp == mod) //when we reach the leaf return the leaf key value
			return root->key;
		else // if not leaf then return search value
			return temp;
	}

	else
		return search(root->left, num);


}

int main() {
	nodeBST* root = NULL;
	ll n, ans = 1e8;
	cin >> n;
	ll arr[n];
	root = insert(root, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];

	}
	cin >> k;
	ll sum = 0;
	for (ll i = 0; i < n; i++) {
		sum += arr[i]; //prefix sum array
		arr[i] = sum;
		ll temp = search(root, arr[i] - k);
		root = insert(root, sum);

		if (temp == mod)
			continue;

		ll temp_ans = arr[i] - temp;

		if (temp_ans < ans)
			ans = temp_ans;

	}

	if (ans == mod1)
		cout << -1;
	else
		cout << ans;


}