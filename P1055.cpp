#include<iostream>
#include <string>
using namespace std;
int main() {
	string s;
	cin >> s;
	string res = "";
	for (char& c : s) {
		if (c != '-')res += c;
	}
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		sum += (res[i] - '0') * (i + 1);
	}
	char ch;
	if (sum % 11 != 10)  ch = (sum % 11+'0');
	else ch = 'X';
	if (res[9] == ch) {
		cout << "Right";
	}
	else {
		string s1 = s.substr(0, 12);
		cout << s1 << ch << endl;
	}
	return 0;
}

\\豆包更优解
#include <iostream>
#include <string>
using namespace std;

int main() {
    string isbn;
    cin >> isbn;

    int sum = 0;    // 校验和
    int pos = 0;    // 记录当前是第几位数字（1-9）
    char correct_check; // 正确的校验位

    // 第一步：遍历字符串，跳过'-'，计算前9位加权和
    for (char c : isbn) {
        // 遇到分隔符直接跳过
        if (c == '-') continue;
        // 只处理前9位数字
        if (pos < 9) {
            // 非法字符校验（非数字）
            if (c < '0' || c > '9') {
                cout << "invalid input" << endl;
                return 0;
            }
            sum += (c - '0') * (pos + 1);
            pos++;
        } else {
            // 找到第10位（校验位），直接退出循环
            break;
        }
    }

    // 第二步：计算正确的校验位
    int mod = sum % 11;
    correct_check = (mod == 10) ? 'X' : (mod + '0');

    // 第三步：获取原校验位并判断
    // 从后往前找最后一个字符（校验位）
    char original_check = isbn.back();
    if (original_check == correct_check) {
        cout << "Right" << endl;
    } else {
        // 替换校验位输出正确结果
        isbn.pop_back();
        cout << isbn + correct_check << endl;
    }

    return 0;
}
