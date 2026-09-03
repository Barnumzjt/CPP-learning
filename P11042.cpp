#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool check(int n) {
	vector<int> vec;
	int k = n;
	while (k) {
		vec.push_back(k % 10);
		k /= 10;
	}
	reverse(vec.begin(), vec.end());
	k = 0;
	int size = vec.size();
	while (1) {
		int ans = 0;
		for (int i = k; i < k + size; ++i) {
			ans += vec[i];
		}
		if (ans == n)return true;
		else if (ans > n)return false;
		vec.push_back(ans);
		k++;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for (int i = 1e7; i >= 197; --i) {
		if (check(i)) {
			cout << i;
			return 0;
		}
	}
	return 0;
}


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(int n) {
    vector<int> vec;
    int k = n;
    while (k) {
        vec.push_back(k % 10);
        k /= 10;
    }
    reverse(vec.begin(), vec.end());
    int len = vec.size();

    vector<long long> pre;
    pre.push_back(0);
    for(auto x : vec) pre.push_back(pre.back() + x);

    int pos = 0;
    while(true) {
        // 窗口 [pos, pos+len-1] 和
        long long sum = pre[pos+len] - pre[pos];
        if(sum == n) return true;
        if(sum > n) return false;
        vec.push_back((int)sum);
        pre.push_back(pre.back() + sum);
        pos++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i = 10000000; i >= 197; i--) {
        if(check(i)) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}
