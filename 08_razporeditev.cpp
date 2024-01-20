#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n);
	vector<int> group(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		if (!group[i]) {
			group[i] = 1;
			queue<int> q;
			q.push(i);
			while (!q.empty()) {
				int node = q.front();
				q.pop();
				for (int nei : g[node]) {
					if (group[nei] == group[node]) {
						cout << -1 << '\n';
						return 0;
					}
					if (!group[nei]) {
						group[nei] = 3 - group[node];
						q.push(nei);
					}
				}
			}
		}
	}
	for (int x : group) cout << x << '\n';
	return 0;
}
