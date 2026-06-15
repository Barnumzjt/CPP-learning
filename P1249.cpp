#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 高精度乘法：低位在前
vector<int> mul(vector<int> num, int x)
{
    int carry = 0;
    for (int i = 0; i < num.size(); ++i)
    {
        long long tmp = 1LL * num[i] * x + carry;
        num[i] = tmp % 10;
        carry = tmp / 10;
    }
    while (carry)
    {
        num.push_back(carry % 10);
        carry /= 10;
    }
    return num;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a;
    int sum = 0, cur = 2;

    // 构造从2开始的连续自然数
    while (sum + cur <= n)
    {
        a.push_back(cur);
        sum += cur++;
    }

    int rem = n - sum;
    // ========== 修复：循环分配余数，直到rem=0 ==========
    int pos = a.size() - 1;
    while (rem > 0)
    {
        a[pos]++;
        rem--;
        pos--;
        if (pos < 0) pos = a.size() - 1; // 走到头回到末尾，循环分配
    }

    // 处理出现1的情况（1会减小乘积，合并到最后一位）
    if (!a.empty() && a[0] == 1)
    {
        a.back() += 1;
        a.erase(a.begin());
    }

    // 输出分解序列
    for (size_t j = 0; j < a.size(); ++j)
    {
        if (j) cout << " ";
        cout << a[j];
    }
    cout << endl;

    // 高精度计算乘积
    vector<int> res;
    res.push_back(1);
    for (int x : a)
    {
        res = mul(res, x);
    }

    // 逆序输出大数
    reverse(res.begin(), res.end());
    for (int d : res)
    {
        cout << d;
    }
    cout << endl;

    return 0;
}
