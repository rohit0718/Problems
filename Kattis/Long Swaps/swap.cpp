#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


using namespace std;
typedef pair<int, int> ii;


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	int k;

	cin >> s >> k;

	int len = s.length();
	string s1(s.begin(), s.end());
	sort(s1.begin(), s1.end());

	vector<int> A(len, 0);

	if (k >= len) {
		cout << "No" << endl; 
		return 0;
	}
	if (k <= len / 2) {
		cout << "Yes" << endl;
		return 0;
	}


	for (int i = len - k; i < k; i++) {

		if (s[i] != s1[i]) {
			cout << "No" << endl;
			return 0;
		}

	}

	cout << "Yes" << endl;

	return 0;
}