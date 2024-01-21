#include <iostream>
#include <string>

using namespace std;

const int alphabet_size = 26;
const char alphabet_start = 'a';

struct Node {
	int p, idx;
	Node *children[alphabet_size];
	Node() {
		p = idx = 0;
		for (Node *&child : children) {
			child = nullptr;
		}
	}
};

class Trie {
private:
	Node *root;
	
public:
	Trie() { root = new Node; }

	void insert(string &s, int priority, int idx) {
		Node *node = root;
		for (char c : s) {
			Node *&child = node->children[c - alphabet_start];
			if (child == nullptr) child = new Node;
			if (child->p < priority) {
				child->p = priority;
				child->idx = idx;
			}
			node = child;
		}
	}

	int lookup(string &s) {
		Node *node = root;
		for (char c : s) {
			node = node->children[c - alphabet_start];
			if (node == nullptr) return 0;
		}
		return node->idx;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	Trie t;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		int priority;
		cin >> priority;
		t.insert(s, priority, i);
	}
	int m;
	cin >> m;
	while (m--) {
		string s;
		cin >> s;
		cout << t.lookup(s) << '\n';
	}
	return 0;
}
