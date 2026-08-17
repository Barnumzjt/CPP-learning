#include <iostream>
using namespace std;

class listnode {
public:
	int val;
	listnode* next;
	listnode* last;
	bool f;
	listnode() :val(0), next(nullptr), last(nullptr), f(false) {};
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	listnode* l = new listnode[n + 2];

	l[1].val = 1;
	l[1].next = nullptr;
	l[1].last = nullptr;
	l[1].f = true;
	int head = 1;

	for (int i = 2; i <= n; ++i) {
		int k, p;
		cin >> k >> p;
		l[i].val = i;
		l[i].f = true;
		if (p == 0) {
			//插入k左边
			l[i].last = l[k].last;
			l[i].next = &l[k];
			if (l[k].last != nullptr) {
				l[k].last->next = &l[i];
			}
			l[k].last = &l[i];
			if (k == head) {
				head = i;
			}
		}
		else if (p == 1) {
			//插入k右边
			l[i].last = &l[k];
			l[i].next = l[k].next;
			if(l[k].next != nullptr){
				l[k].next->last = &l[i];
			}
			l[k].next = &l[i];
		}
	}

	int m;
	cin >> m;
	int x;
	while (m--) {
		cin >> x;
		if (!l[x].f) continue;
		l[x].f = false;
		//处理前驱
		if(l[x].last != nullptr){
			l[x].last->next = l[x].next;
		}else{
			//删除的是头节点
			head = l[x].next ? l[x].next->val : 0;
		}
		//处理后继
		if(l[x].next != nullptr){
			l[x].next->last = l[x].last;
		}
	}

	listnode* cur = &l[head];
	while (cur != nullptr) {
		cout << cur->val << " ";
		cur = cur->next;
	}

	delete[] l;
	return 0;
}
