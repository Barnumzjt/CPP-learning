#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> res;
    while(n!=1){
        res.push_back(n);
        if(n%2==0){
            n/=2;
        }
        else {
            n=n*3+1;
        }
    }
    res.push_back(1);
    for(auto it=res.rbegin();it!=res.rend();++it){
        cout<<*it<<" ";
    }
    return 0;
}


\\更优解
#include <iostream>
using namespace std;

// 递归函数：先计算下一个数，再输出当前数（自动逆序）
void collatz(int n) {
    if (n == 1) {
        cout << 1 << " ";
        return;
    }
    // 核心：先递归处理下一个数，再输出当前数 = 逆序输出
    collatz(n % 2 == 0 ? n / 2 : n * 3 + 1);
    cout << n << " ";
}

int main() {
    int n;
    cin >> n;
    collatz(n);
    return 0;
}
