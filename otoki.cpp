#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct land {
	int y, x, h;
	bool operator>(const land x) const { return h > x.h; }
};

class dsu {
private:
	vector<int> parent;
	vector<bool> out;
	int components, v, s;

	inline int calc_idx(int y, int x) { return y * s + x; }

	int find(int x) {
		if (x == parent[x]) return x;
		return parent[x] = find(parent[x]);
	}

	void unite(int a, int b) {
		a = find(a);
		b = find(b);
		if (a != b) {
			parent[a] = b;
			--components;
		}
	}

public:
	dsu(int _v, int _s, int size): components(0), v(_v), s(_s) {
		parent.resize(size);
		for (int i = 0; i < size; i++) parent[i] = i;
		out.assign(size, false);
	}

	void add(int y, int x) {
		int cell = calc_idx(y, x);
		out[cell] = true;
		++components;
		vector<int> neighbours;
		if (y) neighbours.push_back(calc_idx(y - 1, x));
		if (y + 1 < v) neighbours.push_back(calc_idx(y + 1, x));
		if (x) neighbours.push_back(calc_idx(y, x - 1));
		if (x + 1 < s) neighbours.push_back(calc_idx(y, x + 1));
		for (int n : neighbours) if (out[n]) unite(cell, n);
	}

	int number_of_components() { return components; }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int v, s;
	cin >> v >> s;
	int max_height = 0, size = v * s;
	vector<land> grid(size);
	for (int i = 0; i < size; ++i) {
		cin >> grid[i].h;
		grid[i].y = i / s;
		grid[i].x = i % s;
		max_height = max(max_height, grid[i].h);
	}
	sort(grid.begin(), grid.end(), greater<land>());
	vector<int> output(max_height + 1);
	dsu d(v, s, size);
	for (int height = max_height - 1, p = 0; height >= 0; --height) {
		for (; p < size && grid[p].h > height; ++p) d.add(grid[p].y, grid[p].x);
		output[height] = d.number_of_components();
	}
	for (int x : output) cout << x << '\n';
	return 0;
}