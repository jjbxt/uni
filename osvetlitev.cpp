#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int m, n;
	cin >> m >> n;
	int till = 0, ans = 0;
	vector<pair<int, int>> lights(n);
	for (int i = 0; i < n; i++) {
		int x, d;
		cin >> x >> d;
		lights[i].first = x - d;
		lights[i].second = x + d;
	}
	sort(lights.begin(), lights.end());
	for (int i = 0; i < n; i++) {
		ans += max(0, lights[i].first - till);
		till = max(till, lights[i].second);
	}
	ans += max(0, m - till);
	cout << ans << endl;
	return 0;
}