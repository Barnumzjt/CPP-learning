#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 高精度加法优化版：a,b低位在前
string add(const string& a, const string& b) {
    string res;
    res.reserve(max(a.size(), b.size()) + 1); // 预分配内存，减少扩容
    int carry = 0;
    int i = 0;
    while (i < a.size() || i < b.size() || carry) {
        int sum = carry;
        if (i < a.size()) sum += a[i] - '0';
        if (i < b.size()) sum += b[i] - '0';
        carry = sum / 10;
        res.push_back(sum % 10 + '0');
        i++;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); // 关闭同步，cin加速
    
    int n;
    cin >> n;
    if (n == 1) {
        cout << "1\n";
        return 0;
    }
    if (n == 2) {
        cout << "2\n";
        return 0;
    }
    // 低位存在字符串首部："1"代表1，"2"代表2
    string f1 = "1", f2 = "2", f3;
    for (int i = 3; i <= n; ++i) {
        f3 = add(f1, f2);
        f1.swap(f2);  // 交换，零拷贝
        f2.swap(f3);
    }
    // 低位在前，反转输出
    reverse(f2.begin(), f2.end());
    cout << f2 << endl;
    return 0;
}
