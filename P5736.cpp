#include <iostream>
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
	int n;
	cin >> n;
	vector<bool> is_prime = sieve(100000);
	int x;
	while (n--) {
		cin >> x;
		if (is_prime[x])cout << x << " ";
	}
	return 0;
}
