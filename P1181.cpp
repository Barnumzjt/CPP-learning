#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	int k;
	int sum = 0;
	int count = 0;
	for (int i = 0; i < n; ++i) {
		cin >> k;
		sum += k;
		if (sum > m) {
			count++;
			sum = k;
		}
		else if (sum == m) {
			count++;
			sum = 0;
		}
	}
	if (sum!=0&&sum < m)count++;
	cout << count;
	return 0;
}


//速度一样，代码最短
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, s=0, c=0, x;
    cin>>n>>m;
    while(n--)cin>>x,s+x>m?c++,s=x:s+=x;
    if(s)c++;
    cout<<c;
}
