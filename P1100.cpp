\\原代码修复版本（保留字符串思路）
#include <iostream>
#include <string>
using namespace std;

int main() {
	unsigned int n;   // 关键：无符号32位
	cin >> n;
	string s1 = ""; // 存高16位 bit31~bit16
	string s2 = ""; // 存低16位 bit15~bit0
	for (int i = 31; i >= 0; i--) {
		// 加括号！！
		char s = ((n & (1U << i)) == 0 ? '0' : '1');
		if (i > 15)
			s1 += s;
		else
			s2 += s;
	}
	// 交换：新32位 = s2(原低16) + s1(原高16)
	string total = s2 + s1;
	unsigned int res = 0;
	for(int i=0;i<32;i++){
		res = res * 2 + (total[i]-'0');
	}
	cout << res << endl;
	return 0;
}

\\标准解法
#include <iostream>
using namespace std;
int main() {
	unsigned int n;
	cin >> n;
	unsigned int ans = (n >> 16) | (n << 16);
	cout << ans << endl;
	return 0;
}
\\不用字符串，直接位操作：
n >> 16：把原高 16 位移到低 16 位
n << 16：把原低 16 位移到高 16 位
两者按位或合并，类型必须 unsigned int
