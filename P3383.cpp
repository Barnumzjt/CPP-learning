#include<iostream>
#include <vector>
using namespace std;
vector<bool> sieve(int n) {
	vector<bool> is_prime(n + 1, true);
	is_prime[0] = false;
	is_prime[1] = false;
	for (int i = 2; i * i <= n; ++i) {
		if (is_prime[i]) {
			for (int j = i * i; j <= n; j += i) {
				is_prime[j] = false;
			}
		}
	}
	return is_prime;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<bool> is_prime = sieve(n);
	vector<int> res;
	for (int i = 0; i <= n; ++i) {
		if (is_prime[i])res.push_back(i);
	}
	int q;
	cin >> q;
	int k;
	while (q--) {
		cin >> k;
		cout << res[k - 1] << "\n";
	}
	return 0;
}



//能过但是有更优解，速度其实差不多
#include <iostream>
#include <vector>
using namespace std;

// 线性筛（欧拉筛）O(n) 最优质数筛
vector<int> linear_sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    vector<int> primes;  // 直接存储质数，省去后续遍历
    is_prime[0] = is_prime[1] = false;
    
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);  // 是质数就加入列表
        }
        // 核心：每个合数只被最小质因子筛除
        for (int p : primes) {
            if (1LL * i * p > n) break;
            is_prime[i * p] = false;
            if (i % p == 0) break;  // 保证线性复杂度
        }
    }
    return primes;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> primes = linear_sieve(n);  // 直接拿到质数列表
    
    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        cout << primes[k - 1] << '\n';
    }
    return 0;
}
