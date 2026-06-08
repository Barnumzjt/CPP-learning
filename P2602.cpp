#include <iostream>
using namespace std;
long long count(long long n, int d) {
	if (n < 0)return 0;
	if (n == 0 && d == 0)return 1;
	long long ans = 0;
	long long base = 1;
	while (base <= n) {
		long long high = n / (base * 10);
		long long curr = n / base % 10;
		long long low = n % base;
		if (d == 0) {
			if (curr == 0) {
				ans += (high-1) * base + low + 1;
			}
			else if (curr > 0) {
				ans += high * base;
			}
		}
		else if (curr < d) {
			ans += high * base;
		}
		else if (curr == d) {
			ans += high * base + low + 1;
		}
		else if (curr > d) {
			ans += (high + 1) * base;
		}
		base *= 10;
	}
	return ans;
}
int main() {
	long long a, b;
	cin >> a >> b;
	for (int i = 0; i <= 9; ++i) {
		cout << count(b, i) - count(a - 1, i) << " ";
	}
	return 0;
}
