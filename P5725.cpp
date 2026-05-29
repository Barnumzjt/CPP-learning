#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n*n;++i){
        cout<<setw(2)<<setfill('0')<<i;
        if(i%n==0)cout<<endl;
    }
    cout<<endl;
    int k=1;
    for(int i=0;i<n;++i){
        for(int j=0;j<n-i-1;++j){
            cout<<"  ";
        }
        for(int j=0;j<i+1;++j){
            cout<<setw(2)<<setfill('0')<<k;
            ++k;
        }
        if(i!=n-1)cout<<endl;
    }
    return 0;
}


\\豆包更优解
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cin >> n;

    // 全局设置：占2位、不足补0（只设置一次）
    cout << setw(2) << setfill('0');

    // 1. 输出 n×n 矩阵
    for (int i = 1; i <= n * n; ++i) {
        cout << i;
        if (i % n == 0) cout << endl;
    }
    cout << endl;

    // 2. 输出数字金字塔
    int num = 1;
    for (int i = 0; i < n; ++i) {
        // 打印前面空格
        for (int j = 0; j < n - i - 1; ++j) {
            cout << "  ";
        }
        // 打印数字
        for (int j = 0; j <= i; ++j) {
            cout << num++;
        }
        cout << endl;
    }

    return 0;
}
setfill('0') 只设置一次
你原来每次输出都写 setw(2)<<setfill('0')<<i，完全没必要，setfill 是持久生效的，只写一次就够。
setw(2) 全局设置
整个程序都需要占 2 位输出，直接在开头统一设置，代码更清爽。
变量名更直观
k → num，一眼就知道是数字计数。
