\\不会做，想着用递归做结果不用那么麻烦，递归也会超时，我也没写对
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> coins(n, 0);  // 初始全0（正面）
    
    // 输出最少操作次数
    cout << n << endl;
    
    // 执行n次操作：第i次不翻转第i个硬币
    for (int i = 0; i < n; ++i) {
        // 翻转除了第i个之外的所有硬币
        for (int j = 0; j < n; ++j) {
            if (j != i) {
                coins[j] = 1 - coins[j];  // 0变1，1变0
            }
        }
        // 输出当前硬币状态
        for (int num : coins) {
            cout << num;
        }
        cout << endl;
    }
    return 0;
}

\\算是练一练dfs
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> best_path;

// 判断是否全部为 1
bool isAllOne(const vector<int>& coins) {
    for (int x : coins) if (x == 0) return false;
    return true;
}

// DFS
void dfs(vector<int> coins, int step, vector<vector<int>> path) {
    // 找到目标
    if (isAllOne(coins)) {
        best_path = path;
        return;
    }

    // 最多走 n 步（最优解就是 n）
    if (step >= n) return;

    // 按顺序枚举：第 i 个硬币不翻转（字典序最小）
    for (int i = 0; i < n; ++i) {
        vector<int> newCoins = coins;
        for (int j = 0; j < n; ++j) {
            if (j != i) newCoins[j] = 1 - newCoins[j];
        }

        path.push_back(newCoins);
        dfs(newCoins, step + 1, path);
        path.pop_back();

        // 一旦找到答案直接退出
        if (!best_path.empty()) return;
    }
}

int main() {
    cin >> n;
    vector<int> coins(n, 0);
    dfs(coins, 0, {});

    // 输出
    cout << best_path.size() << endl;
    for (auto& line : best_path) {
        for (int x : line) cout << x;
        cout << endl;
    }
    return 0;
}
