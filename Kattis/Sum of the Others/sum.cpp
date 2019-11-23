#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	while (getline(cin, s)) {

		istringstream iss(s);
		int sum = 0;
		string w;
		while (iss >> w) {
			sum += stoi(w);
		}

		cout << sum / 2 << "\n";

	}

	return 0;
}