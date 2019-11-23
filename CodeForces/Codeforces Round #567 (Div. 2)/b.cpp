#include <iostream>
#include <string>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int digits;
	string s, x, y;
	cin >> digits >> s;

	if (digits % 2 == 0) {
		for (int i = 0; i < digits / 2; ++i) x.push_back(s[i]);
		for (int i = digits / 2; i < digits; ++i) y.push_back(s[i]);

		cout << x << " sep " << y;
	}
	else {
		for (int i = 0; i <= digits / 2; ++i) x.push_back(s[i]);
		for (int i = (digits / 2); i < digits; ++i) y.push_back(s[i]);
		string s = findSum(x, y);
		cout << s << endl;
		cout << x << " sep " << y;
	}
	



	return 0;
}



