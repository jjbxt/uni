#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int x, y, z;
	string s, t;
	cin >> x >> y >> z >> s >> t;
	int n = s.size(), m = t.size();
	vector<vector<int>> dp(n + 2, vector<int>(m + 2, -1001));
	dp[n][m] = 0;
	for (int i = n - 1; i >= 0; --i) dp[i][m] = dp[i + 1][m] + y;
	for (int i = m - 1; i >= 0; --i) dp[n][i] = dp[n][i + 1] + x;
	for (int i = n - 1; i >= 0; --i) {
		for (int j = m - 1; j >= 0; --j) {
			dp[i][j] = min({x + dp[i][j + 1], y + dp[i + 1][j], (s[i] == t[j] ? 0 : z) + dp[i + 1][j + 1]});
		}
	}
	cout << dp[0][0] << endl;
	for (int i = 0, j = 0; i < n || j < m; ++i, ++j) {
		if (dp[i][j + 1] + x == dp[i][j]) cout << '+' << t[j] << ' ', --i;
		else if (dp[i + 1][j] + y == dp[i][j]) cout << '-' << s[i] << ' ', --j;
		else if (s[i] == t[j] && dp[i + 1][j + 1] == dp[i][j]) cout << s[i] << ' ';
		else cout << s[i] << '>' << t[j] << ' ';
	}
	cout << endl;
	return 0;
}