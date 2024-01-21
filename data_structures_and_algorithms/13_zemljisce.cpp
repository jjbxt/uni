#include <iostream>
#include <array>
#include <algorithm>
#include <cmath>

using namespace std;

using point = pair<int, int>;
using rect = array<point, 4>;

#define x first
#define y second

inline double dist(point p, point q) {
	return sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y));
}

inline int closest_corners(rect &p1, rect &p2) {
	return (int)ceil(8 * min({dist(p1[0], p2[3]), dist(p1[1], p2[2]),
	                          dist(p1[2], p2[1]), dist(p1[3], p2[0])}));
}

inline int vertical_dist(rect &p1, rect &p2) {
	return 8 * max(p1[0].y - p2[1].y, p2[0].y - p1[1].y);
}

inline int horizontal_dist(rect &p1, rect &p2) {
	return 8 * max(p1[0].x - p2[2].x, p2[0].x - p1[2].x);
}

inline bool vertical_check(rect &p1, rect &p2) {
	return
		p1[0].x <= p2[0].x && p2[0].x <= p1[2].x ||
		p1[0].x <= p2[2].x && p2[2].x <= p1[2].x ||
		p2[0].x <= p1[0].x && p1[0].x <= p2[2].x;

}

inline bool horizontal_check(rect &p1, rect &p2) {
	return
		p1[0].y <= p2[0].y && p2[0].y <= p1[1].y ||
		p1[0].y <= p2[1].y && p2[1].y <= p1[1].y ||
		p2[0].y <= p1[0].y && p1[0].y <= p2[1].y;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		point a, b, c, d;
		cin >> a.x >> a.y >> b.x >> b.y
		    >> c.x >> c.y >> d.x >> d.y;
		rect p1 = {a, b, {a.x, b.y}, {b.x, a.y}},
		     p2 = {c, d, {c.x, d.y}, {d.x, c.y}};
		sort(p1.begin(), p1.end());
		sort(p2.begin(), p2.end());
		if (p1[1].y < p1[2].y) swap(p1[1], p1[2]);
		if (p2[1].y < p2[2].y) swap(p2[1], p2[2]);
		bool same_column = vertical_check(p1, p2),
		     same_row = horizontal_check(p1, p2);
		if (same_column && same_row) {
			cout << 0 << '\n';
		} else if (same_column) {
			cout << vertical_dist(p1, p2) << '\n';
		} else if (same_row) {
			cout << horizontal_dist(p1, p2) << '\n';
		} else {
			cout << closest_corners(p1, p2) << '\n';
		}
	}
	return 0;
}
