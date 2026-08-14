#include <iostream>
using namespace std;
int search(int arr[], int n, int key) {
	int l = 0, r = n - 1;
	int ans = -1;
	while (l <= r) {
		int m = l + (r - l) / 2;
		if (arr[m] > key) {
			r = m - 1;
		}
		else if (arr[m] < key) {
			l = m + 1;
		}
		else if (arr[m] == key) {
			ans = m + 1;
			r = m - 1;
		}
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	int* p;
	p = new int[n];
	for (int i = 0; i < n; ++i)cin >> p[i];
	int key;
	while (m--) {
		cin >> key;
		cout << search(p, n, key) << " ";
	}
	return 0;
}
