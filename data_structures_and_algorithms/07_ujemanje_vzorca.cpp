#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	while (n--) {
		string s, t;
		cin >> s >> t;
		vector<string> parts;
		string part;
		for (char c : s) {
			if (c != '*') part += c;
			else if (!part.empty()) {
				parts.emplace_back(part);
				part.clear();
			}
		}
		if (!part.empty()) parts.emplace_back(part);
		if (parts.empty()) {
			cout << 0 << ' ' << 0 << '\n';
			continue;
		}
		int from = 0, match_start;
		bool match;
		for (string part : parts) {
			match = false;
			for (int start = from; start + part.size() <= t.size(); ++start) {
				match = true;
				for (int i = 0; match && i < part.size(); ++i) {
					if (part[i] != '?' && part[i] != t[start + i]) match = false;
				}
				if (match) {
					if (!from) match_start = start;
					from = start + part.size();
					break;
				}
			}
			if (!match) break;
		}
		if (match) cout << (s[0] == '*' ? 0 : match_start) << ' ' << from - 1 << '\n';
		else cout << -1 << '\n';
	}
	return 0;
}
