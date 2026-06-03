#include <iostream>
using namespace std;
int main(){
    string s1,s2;
    cin>>s1>>s2;
    int sum1=1,sum2=1;
   for(char &c:s1)sum1*=(c-'A'+1);
   for(char& c:s2)sum2*=(c-'A'+1);
    if(sum1%47==sum2%47)cout<<"GO";
    else cout<<"STAY";
    return 0;
}


\\更优解
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    
    // 封装成函数，代码复用+简洁
    auto calc = [](const string& s) {
        int res = 1;
        for (char ch : s) {
            // 边乘边取模，核心优化点
            res = res * (ch - 'A' + 1) % 47;
          \\res = res * x % 47 ✅ 正确（整体取模）
          \\res *= x % 47 ❌ 错误（少了最后一次取模）没对res取模
        }
        return res;
    };

    // 三目运算符简化输出
    cout << (calc(s1) == calc(s2) ? "GO" : "STAY") << endl;
    return 0;
}
无溢出风险：全程数值 ≤46，int 完全装得下
代码简洁：用 Lambda 函数封装计算逻辑，复用性强
效率更高：少一次取模运算，逻辑更精简
可读性强：变量命名清晰，结构一目了然
