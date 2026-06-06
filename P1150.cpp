#include<iostream>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k; 
    int sum=n;
    while(n/k){
        int x=n/k;
        sum+=x;
        n=n-k*x+x;
    }
    cout<<sum;
    return 0;
}


//更优解
#include <iostream>
using namespace std;

int main() {
    long long n, k;  // 必须用 long long，防止爆 int
    cin >> n >> k;
    long long ans = n + (n - 1) / (k - 1);
    cout << ans << endl;
    return 0;
}
第一步：算 “换一次烟” 发生了什么你有 k 个烟蒂：
用掉 k 个 → 换 1 根烟
抽这根烟 → 得到 1 个新烟蒂
净变化：
烟蒂数量 = 原来 - k + 1
= 少了 k-1 个👉 每换 1 根烟，净消耗 k-1 个烟蒂第二步：最多能换多少次？我们总共有 n 个烟蒂（一开始抽完 n 根）
每次兑换 消耗 k-1 个
最后必须剩下 <k 个烟蒂，不能再换最关键的结论：
能换的次数 = 总共能消耗多少个 (k-1)但因为最后必须剩一点，所以：
能换的次数 = (n - 1) // (k - 1)为什么减 1？
因为最后至少要剩 1 个烟蒂换不了，不能把所有烟蒂都用光。第三步：总抽烟数 = 一开始 + 兑换的总抽烟数
= 最初的 n 根
兑换的 (n-1)/(k-1) 根
最终公式：
\(ans = n + \frac{n-1}{k-1}\)
