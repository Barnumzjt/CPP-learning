#include <iostream>
#include <queue>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	char ch;
	queue<char> q;
	while(cin>>ch&&ch!='@'){
		if (ch == '(')q.push('(');
		else if (ch == ')') {
			if (!q.empty())q.pop();
			else {
				cout << "NO";
				return 0;
			}
		}
	}
	if (q.empty())cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
