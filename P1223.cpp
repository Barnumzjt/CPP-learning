#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;
class wicktree {
private:
	vector<int> tree;
public:
	wicktree(int size):tree(size+2,0){}
	void update(int idx, int n) {
		while (idx < tree.size()) {
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
struct people{
	int time;
	int id;
};
bool compare(people& p1, people& p2) {
	if (p1.time != p2.time)return p1.time < p2.time;
	else return p1.id < p2.id;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<people> vec;
	int t;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		vec.push_back({ t,i + 1 });
	}
	sort(vec.begin(), vec.end(), compare);
	wicktree tree(n);
	for (int i = 0; i < n; ++i) {
		cout << vec[i].id << " ";
		tree.update(i + 1, vec[i].time);
	}
	double sum = 0;
	for (int i = 2; i <= n; ++i) {
		sum += tree.query(i-1);
	}
	cout << endl <<fixed<<setprecision(2)<< sum / n;
	return 0;
}
