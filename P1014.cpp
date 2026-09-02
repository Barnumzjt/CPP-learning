#include <iostream>;
#include <vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	int x = 1, y = 1;
	bool flag = false;
	int dx, dy;
	for (int i = 1; i < n; ++i) {
		if (flag) {
			dx = x + 1;
			dy = y - 1;
		}
		else {
			dx = x - 1;
			dy = y + 1;
		}
		if (dx >= 1 && dy >= 1) {
			x = dx;
			y = dy;
			continue;
		}
		else {
			if (!flag) {
				y++;
				flag = true;
			}
			else {
				x++;
				flag = false;
			}
		}
	}
	cout << x << "/" << y;
	return 0;
}
