#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1 << 20;

class BIT {
private:
	int *bit, *vis;

	int sum(int k) {
		int s = 0;
		while (k) {
			s += bit[k];
			k -= k&-k;
		}
		return s;
	}
	
public:
	BIT() {
		bit = new int[MAX]();
		vis = new int[MAX]();
	}

	~BIT() {
		delete [] bit;
		delete [] vis;
	}

	void insert(int x) {
		++vis[x];
		while (x < MAX) {
			++bit[x];
			x += x&-x;
		}
	}

	void erase(int x) {
		if (vis[x]) {
			--vis[x];
			while (x < MAX) {
				--bit[x];
				x += x&-x;
			}
		}
	}

	int count(int from, int to) {
		return sum(to) - sum(from - 1);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	BIT b;
	long long ans = 0;
	while (n--) {
		int s, x;
		cin >> s >> x;
		s = min(s, MAX - 1);
		if (s < 0) b.insert(x);
		else if (s == 0) b.erase(x);
		else ans += b.count(min(s, x), max(s, x));
	}
	cout << ans << endl;
	return 0;
}
