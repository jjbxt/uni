#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	priority_queue<int> p;
	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (p.empty() || x < p.top()) p.push(x);
		else q.push(x);
		if (q.size() + 1 < p.size()) {
			q.push(p.top());
			p.pop();
		}
		if (q.size() > p.size()) {
			p.push(q.top());
			q.pop();
		}
		cout << p.top() << '\n';
	}
	return 0;
}