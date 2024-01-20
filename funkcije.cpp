#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

int n;
ll k;
vector<int> a, b;

inline ll calc(ll x, int i) {
	return (ll)(x * pow(log2l(x), (long double)i/n));
}

ll bin(ll val) {
	ll sum = 0;
	for (int i = 1; i <= n; ++i) {
		int lo = a[i] - 1, hi = b[i];
		while (lo < hi) {
			int mid = (lo + hi + 1) / 2;
			if (calc(mid, i) <= val) lo = mid;
			else hi = mid - 1;
		}
		sum += lo - a[i] + 1;
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	a.resize(n + 1);
	b.resize(n + 1);
	for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i];
	ll lo = -1, hi = calc(1e9, n);
	while (lo < hi) {
		ll mid = (lo + hi + 1) / 2;
		ll sum = bin(mid);
		if (sum < k) lo = mid;
		else hi = mid - 1;
	}
	cout << lo + 1 << endl;
	return 0;
}