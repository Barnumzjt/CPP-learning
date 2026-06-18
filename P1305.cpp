#include <iostream>
#include <string>
using namespace std;
char lp[30], rp[30];
void preorder(char ch) {
	if (ch == '*')return;
	cout << ch;
	preorder(lp[ch - 'a']);
	preorder(rp[ch - 'a']);
}
int main() {
	int n;
	cin >> n;
	char root;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		char fa = s[0], l = s[1], r = s[2];
		if (i == 0)root = fa;
		lp[fa - 'a'] = l;
		rp[fa - 'a'] = r;
	}
	preorder(root);
	return 0;
}
