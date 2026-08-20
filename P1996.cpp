#include <iostream>
using namespace std;
class listnode {
public:
	int val;
	listnode* next;
	int order;
	bool f;
	listnode() {
		val = 1;
		next = nullptr;
		order = 1;
		f = false;
	}
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	listnode* l;
	l = new listnode[n];
	listnode* head = nullptr;
	listnode* cur = nullptr;
	for (int i = 0; i < n; ++i) {
		l[i].f = true;
		l[i].order = i + 1;
	}
	bool flag = false;
	int data = 1;
	int remain = n;   //【改动1】增加剩余人数
	int i = 0;
	//【改动2】把原来的 for(int i=0;i<n;++i) 改成 while，去掉for的i++
	while (remain > 0)
	{
		if (!l[i].f) {
			i++;
			if(i == n) i = 0;
			continue;
		}
		if (data == m) {
			data = 0;
			l[i].f = false;
			remain--;   //【改动3】出局剩余人数减一
			if (cur != nullptr) {
				cur->next = &l[i];
			}
			else {
				head = &l[i];
			}
			cur = &l[i];
			cur->next = nullptr; // 只给新尾结点置空，没问题
		}
		data++;
		i++;   //手动i++，代替for的自增
		if (i == n) {   //【改动4】原来i==n‑1逻辑改成i走到n就回0
			i = 0;
		}
	}
	cur = head;
	while (cur != nullptr) {
		cout << cur->order<< " ";
		cur = cur->next;
	}
	delete[] l;
	return 0;
}
