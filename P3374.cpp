#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class fenwicktree {
private:
	vector<int> tree;
public:
	fenwicktree(int size):tree(size+2,0){}
	void upgrade(int idx,int n) {
		while (idx <= tree.size()) {
			tree[idx] += n;
			idx += idx & -idx;
		}
	}
	int query(int idx) {
		int sum = 0;
		while (idx > 0) {
			sum += tree[idx];
			idx -= idx & -idx;
		}
		return sum;
	}
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> vec(n);
	fenwicktree tree(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
		tree.upgrade(i+1, vec[i]);
	}
	for (int i = 0; i < m; i++) {
		int k, x, y;
		cin >> k >> x >> y;
		if (k == 1) {
			tree.upgrade(x, y);
		}
		else if (k == 2) {
			int res = tree.query(y) - tree.query(x-1);
			cout << res << endl;
		}
	}
	return 0;
}
