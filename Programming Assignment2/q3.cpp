#include<iostream>

using namespace std;

#define ll long long int

struct data {
	ll key;
	ll idx;
};

void _mergeInversions(data *arr, ll *count , ll left, ll right) {

	if (left > right)
		return;

	ll mid = (left + right) / 2;
	data temp[right - left + 1];
	ll i = left; ll j = mid + 1; ll k = 0;

	while ((i <= mid) && (j <= right)) {
		if (arr[i].key < arr[j].key) {
			temp[k] = arr[i];
			k++;
			i++;
		}
		else {
			temp[k] = arr[j];
			count[arr[j].idx] += mid - i + 1;
			k++;
			j++;
		}
	}

	while (i <= mid) {
		temp[k] = arr[i];
		k++;
		i++;
	}

	while (j <= right) {
		temp[k] = arr[j];
		k++;
		j++;
	}

	for (ll i = left; i <= right; i++)
		arr[i] = temp[i - left];

	return;

}

void countInversions(data *arr, ll *count, ll left, ll right) {

	if (left >= right)
		return;

	ll mid = (left + right) / 2;

	countInversions(arr, count , left, mid);
	countInversions(arr, count, mid + 1, right);
	_mergeInversions(arr, count, left, right);

}


int main()
{
	ll n;
	cin >> n;
	data arr[n];

	for (ll i = 0; i < n; i++) {
		cin >> arr[i].key;
		arr[i].idx = i;
	}

	ll count[n] = {0};
	countInversions(arr, count, 0, n - 1);

	for (ll i = 0; i < n; i++)
		cout << count[i] << " ";

	return 0;
}