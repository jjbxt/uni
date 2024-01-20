#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = (int)1e6;
int arr[MAX_N];

int main() {
	ios_base::sync_with_stdio(false);
	int n, k, a;
	cin >> n >> k >> a;
	int k_to_a = 1;
	while (a-- && k_to_a < n) k_to_a *= k;
	int from = 0, cnt = 0, maxi = -1;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] < maxi) {
			++cnt;
			if (cnt % k_to_a == 0) {
				sort(arr + from, arr + i);
				from = i;
			}
		}
		maxi = arr[i];
	}
	sort(arr + from, arr + n);
	for (int i = 0; i < n; i++) cout << arr[i] << '\n';
	return 0;
}