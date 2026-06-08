#include<iostream>
#include<string>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    string s;
    int ans=0;
    for(int i=a;i<=b;++i){
        s=to_string(i);
        for(char &c:s){
            if(c=='2')ans++;
        }
    }
    cout<<ans;
    return 0;
}


//更优解，数位统计版
#include <iostream>
#include <vector>
using namespace std;

// 计算 0~n 中数字 2 出现的总次数
int count2(int n) {
    if (n < 0) return 0;
    int res = 0;
    long long base = 1; // 位权：个位=1,十位=10...
    while (base <= n) {
        int high = n / (base * 10); // 高位
        int curr = (n / base) % 10; // 当前位
        int low = n % base;         // 低位

        if (curr < 2) {
            res += high * base;
        } else if (curr == 2) {
            res += high * base + low + 1;
        } else {
            res += (high + 1) * base;
        }
        base *= 10;
    }
    return res;
}

int main() {
    int a, b;
    cin >> a >> b;
    // 答案 = 0~b 的2数量 - 0~a-1 的2数量
    cout << count2(b) - count2(a - 1) << endl;
    return 0;
}

