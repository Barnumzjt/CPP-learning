#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> vec;
    int n;
    while(cin>>n&&n!=0){
        vec.push_back(n);
    }
    for(int i=vec.size()-1;i>=0;i--){
        cout<<vec[i];
        if(i!=0)cout<<" ";
    }
    return 0;
}


\\豆包优解
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec;
    int n;

    // 读入数据直到 0
    while (cin >> n && n != 0) {
        vec.push_back(n);
    }

    // 逆序遍历 + 优雅输出
    bool first = true;
    for (auto it = vec.rbegin(); it != vec.rend(); ++it) {
        if (!first) cout << " ";
        cout << *it;
        first = false;
    }

    return 0;
}
\\使用反向迭代器 rbegin () /rend ()，更符合 “逆序” 语义
\\用 auto 自动推导类型，代码更简洁
\\用 first 控制空格，逻辑比判断 i!=0 更通用（任何容器都能用）
\\可读性大幅提升
