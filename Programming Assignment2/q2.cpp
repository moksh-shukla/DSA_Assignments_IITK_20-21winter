#include<iostream>

using namespace std;

#define ll long long int
#define my_sizeof(type) ((char *)(&type+1)-(char*)(&type))

ll m, n;

ll countMult(ll *a, ll *b, ll mid) {

	ll i, j = n - 1, count = 0;
	for (ll i = 0; i < m; i++) {
		while (j >= 0 && a[i]*b[j] > mid) {
			j--;
		}

		count += j + 1;
	}
	return count;

}

ll solve(ll *a, ll *b, ll k, ll low, ll high) {
	//ll m = my_sizeof(a); ll n = my_sizeof(b);
	ll mid = (low + high) / 2;
	ll count = countMult(a, b, mid);
	if (low >= high)
		return low;
	if (count >= k)
		high = mid - 1;

	else if (count < k)
		low = mid + 1 ;

	else if (count == k)
		return mid;

	return solve(a, b, k, low, high);
}


int main() {

	cin >> m >> n;
	ll a[m], b[n];

	for (ll i = 0; i < m; i++)
		cin >> a[i];
	for (ll i = 0; i < n; i++)
		cin >> b[i];

	ll k;
	cin >> k;
	ll low = a[0] * b[0];
	ll high = a[m - 1] * b[n - 1];


	ll ans =  solve(a, b, k, low, high);

	if (countMult(a, b, ans) < k)
		ans++;
	if (countMult(a, b, ans - 1) == k)
		ans--;

	cout << ans << endl;


}