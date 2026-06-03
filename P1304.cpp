#include <iostream>
#include <cmath>
using namespace std;
bool check(int n){
    if(n<=1)return 0;
    if(n==2)return 1;
    if(n%2==0)return 0;
    for(int i=3;i<=sqrt(n);i+=2){
        if(n%i==0)return 0;
    }
    return 1;
}
void prove(int n){
    for(int i=2;i<=n/2;++i){
        if(check(i)&&check(n-i)){
            cout<<n<<"="<<i<<"+"<<n-i<<endl;
            return;
        }
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=4;i<=n;i+=2){
        prove(i);
    }
    return 0;
}


//更优解
#include <iostream>
#include <vector>
using namespace std;

// 埃拉托斯特尼筛法：预处理出所有 <= max_n 的素数
vector<bool> sieve(int max_n) {
    vector<bool> is_prime(max_n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= max_n; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= max_n; j += i)
                is_prime[j] = false;
        }
    }
    return is_prime;
}

int main() {
    int n;
    cin >> n;
    
    // 一次性筛出所有需要的素数
    vector<bool> is_prime = sieve(n);

    // 验证每个偶数
    for (int even = 4; even <= n; even += 2) {
        // 找第一个符合条件的素数对
        for (int p = 2; p <= even / 2; ++p) {
            if (is_prime[p] && is_prime[even - p]) {
                cout << even << "=" << p << "+" << even - p << endl;
                break;
            }
        }
    }
    return 0;
}
