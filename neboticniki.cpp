#include <iostream>
#include <stack>

using namespace std;

const int INF = (int)1e9 + 1;
const int MAX_N = (int)1e6;
int a[MAX_N + 2];

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	a[0] = a[n + 1] = INF;
	long long z = 0;
	stack<int> s1, s2;
	s1.push(0);
	s2.push(n + 1);
	for (int i = 1; i <= n; i++) {
		while (a[s1.top()] <= a[i]) s1.pop();
		z += i - s1.top() - 1;
		s1.push(i);
	}
	for (int i = n; i >= 1; i--) {
		while (a[s2.top()] <= a[i]) s2.pop();
		z += s2.top() - i - 1;
		s2.push(i);
	}
	cout << z << endl;
	return 0;
}