#include <iostream>
#include <string>

using namespace std;

int main() {

	int l = 1;
	int r = 1000;

	while (true) {

		string s;
		cout << (l + r) / 2 << endl;
		cin >> s;

		if (s == "lower") r = ((l + r) / 2) - 1;
		else if (s == "higher") l = ((l + r) / 2) + 1;
		else if (s == "correct") break;
	}

	return 0;


}

