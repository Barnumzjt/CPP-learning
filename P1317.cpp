#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; ++i)
        cin >> h[i];

    int cnt = 0;
    int i = 1;
    while (i < n - 1)
    {
        // 当前位置比左边低，可能进入谷底区域
        if (h[i] < h[i - 1])
        {
            int valley = h[i];
            // 走到谷底平坦段末尾
            while (i < n - 1 && h[i + 1] == valley)
                i++;
            // 判断右侧是否高于谷底，形成封闭洼地
            if (h[i + 1] > valley)
                cnt++;
        }
        i++;
    }
    cout << cnt << endl;
    return 0;
}
