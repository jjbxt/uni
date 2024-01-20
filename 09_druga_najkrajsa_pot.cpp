#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct par {
	int x, y;
	par(int _x, int _y): x(_x), y(_y) {}
	bool operator<(const par p) const { return x < p.x; }
};

const int INF = 1 << 30, MAXN = 2000;
int n, m;
bool vis[MAXN];
vector<par> g[MAXN];
int distances[MAXN], shortest_path[MAXN], dist_from_goal[MAXN];
priority_queue<par> pq;

void dijkstra_backward() {
	for (int &x : dist_from_goal) x = INF;
	dist_from_goal[n - 1] = 0;
	pq.push({0, n - 1});
	while (!pq.empty()) {
		auto [dist, node] = pq.top();
		pq.pop();
		if (dist_from_goal[node] != -dist) continue;
		for (auto &[b, w] : g[node]) {
			if (w - dist < dist_from_goal[b]) {
				shortest_path[b] = node;
				dist_from_goal[b] = w - dist;
				pq.push({-dist_from_goal[b], b});
			}
		}
	}
}

inline bool same_edge(int x1, int y1, int x2, int y2) {
	return x1 == x2 && y1 == y2 || x1 == y2 && x2 == y1;
}

int dijkstra_length(int root, int best) {
	for (int &x : distances) x = INF;
	int next = shortest_path[root];
	distances[root] = dist_from_goal[0] - dist_from_goal[root];
	pq.push({-distances[root], root});
	while (!pq.empty()) {
		auto [dist, node] = pq.top();
		pq.pop();
		if (distances[node] != -dist) continue;
		for (auto [b, w] : g[node]) {
			if (!vis[b] && w - dist + dist_from_goal[b] < best && w - dist < distances[b] && !same_edge(root, next, node, b)) {
				distances[b] = w - dist;
				pq.push({-distances[b], b});
			}
		}
	}
	return distances[n - 1];
}

int yen() {
	dijkstra_backward();
	if (dist_from_goal[0] == INF) return -1;
	int root = 0, best = INF;
	while (root != n - 1) {
		vis[root] = true;
		best = min(best, dijkstra_length(root, best));
		root = shortest_path[root];
	}
	if (best == INF) return -1;
	return best;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	while (m--) {
		int a, b, w;
		cin >> a >> b >> w;
		g[a].emplace_back(b, w);
		g[b].emplace_back(a, w);
	}
	cout << yen() << '\n';
	return 0;
}
