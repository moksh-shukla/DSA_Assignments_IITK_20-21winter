#include<iostream>

using namespace std;

#define ll long long int

struct data {
	ll val;
	ll idx;
};

void merge(data *a, ll left, ll right) {

	ll mid = (left + right) / 2;
	ll n = right - left + 1;
	data temp[n];
	ll i = left; ll j = mid + 1; ll k = 0;

	while ((i <= mid) && (j <= right)) {
		if (a[i].val <= a[j].val) {
			temp[k] = a[i];
			i++;
		}
		else {
			temp[k] = a[j];
			j++;
		}

		k++;
	}

	while (i <= mid) {
		temp[k] = a[i];
		i++; k++;
	}
	while (j <= right) {
		temp[k] = a[j];
		j++; k++;
	}

	for (ll i = left; i <= right ; i++)
		a[i] = temp[i - left];

}

void mergeSort(data *a, ll left, ll right) {
	if (left >= right)
		return;
	ll mid = (left + right) / 2;
	mergeSort(a, left, mid);
	mergeSort(a, mid + 1, right);
	merge(a, left, right);

}

void prefixSum(data *a, ll n, ll *preSum) {
	preSum[0] = a[0].val;
	for (ll i = 1; i < n; i++)
		preSum[i] = preSum[i - 1] + a[i].val;
}

int main() {
	ll n;
	ll sum = 0;
	cin >> n;
	data arr[n];
	for (ll i = 0; i < n; i++) {
		cin >> arr[i].val;
		arr[i].idx = i;
	}

	mergeSort(arr, 0, n - 1);

	for (ll i = 0; i < n; i++)
		sum += arr[i].val;

	ll greatBST[n], preSum[n];

	prefixSum(arr, n, preSum);

	for (ll i = 0; i < n; i++) {
		greatBST[arr[i].idx] = sum - preSum[i] + arr[i].val;
	}

	for (ll i = 0; i < n; i++) {
		cout << greatBST[i] << " ";
	}


}