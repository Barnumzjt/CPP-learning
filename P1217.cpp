#include <iostream>
#include <vector>
#include <string>
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
bool ispal(int n) {
	int tmp = n, res = 0;
	while (tmp) {
		res = res * 10 + tmp % 10;
		tmp /= 10;
	}
	if (res == n)return true;
	else return false;
}//用这个来判断比字符串更快
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a, b;
	cin >> a >> b;
	vector<bool> is_prime = sieve(b);
	for (int i = a; i <= b; ++i) {
		if (is_prime[i]) {
			if (ispal(i)) {
				cout << i << endl;
			}
		}
	}
	return 0;
}
