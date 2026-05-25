#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    vector<int> res(n,0);
    for(int i=0;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(vec[j]<vec[i])res[i]++;
        }
    }
    for(int c:res)cout<<c<<" ";
    return 0;
}
\\豆包给的优解
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class FenwickTree {
private:
    vector<int> tree;
public:
    FenwickTree(int size) : tree(size + 2, 0) {}  // 稍微开大一点避免越界

    void update(int idx, int delta) {
        while (idx < tree.size()) {
            tree[idx] += delta;
            idx += idx & -idx;
        }
    }

    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += tree[idx];
            idx -= idx & -idx;
        }
        return sum;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> vec(n), tmp(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
        tmp[i] = vec[i];
    }

    // 离散化
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    for (int& x : vec) {
        x = lower_bound(tmp.begin(), tmp.end(), x) - tmp.begin() + 1;
    }

    FenwickTree ft(tmp.size());
    vector<int> res(n);

    // ✅ 关键修复：从左往右遍历！！！
    for (int i = 0; i < n; i++) {
        // 查询左边已经插入的、比当前数小的数量
        res[i] = ft.query(vec[i] - 1);
        ft.update(vec[i], 1);
    }

    for (int x : res) cout << x << " ";
    return 0;
}
