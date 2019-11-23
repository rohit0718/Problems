#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {

	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;

		char ans[32];
		memset(ans, '?', 32);


		for (int case_num = 0; case_num < n; ++case_num) {
			string s;
			cin >> s;
			if (s == "SET") {
				int x;
				cin >> x;
				ans[31- x] = '1';
			}
			else if (s == "CLEAR") {
				int x;
				cin >> x;
				ans[31 - x] = '0';
			}
			else if (s == "AND") {
				int x, y;
				cin >> x >> y;
				if (ans[31 - x] == '1' && ans[31 - y] == '?')
					ans[31 - x] = '?';
				else if (ans[31 - y] == '0')
					ans[31 - x] = '0';
			}
			else if (s == "OR") {
				int x, y;
				cin >> x >> y;
				if (ans[31 - x] == '0' && ans[31 - y] == '?')
					ans[31 - x] = '?';
				else if (ans[31 - y] == '1')
					ans[31 - x] = '1';
			}
		}

		for (auto &a : ans) cout << a;
		cout << "\n";
	}
}