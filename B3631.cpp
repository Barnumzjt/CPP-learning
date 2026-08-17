#include <iostream>
using namespace std;
class listnode {
public:
	int val;
	listnode* next;
	listnode() {
		val = 1;
		next = nullptr;
	}
};
int main() {
	int q;
	cin >> q;
	listnode* l = new listnode[1000001];
	l[1].val = 1;
	while (q--) {
		int n;
		cin >> n;
		int x, y;
		if (n == 1) {
			cin >> x >> y;
			l[x].val = x;
			l[y].val = y;
			if (l[x].next != nullptr) {
				l[y].next = l[x].next;
			}
			l[x].next = (l + y);
		}
		else if (n == 2) {
			cin >> x;
			if (l[x].next == nullptr)cout << "0" << endl;
			else cout << l[x].next->val << endl;
		}
		else if (n == 3) {
			cin >> x;
			if (l[x].next != nullptr) {
				l[x].next = l[x].next->next;
			}
		}
	}
	return 0;
}
