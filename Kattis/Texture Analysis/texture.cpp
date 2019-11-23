#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {

	string s;
	int case_num = 1;
	bool even = true;

	while (getline(cin, s) && s != "END") {
		int len = s.length();
		int ans = 0;
		vector<int> V;
		for (int i = 1; i < len; ++i) {
			if (s[i] == '.') ans++;
			else if (s[i] == '*') {
				V.push_back(ans);
				ans = 0;
			}
		}
		int lenV = V.size();
		for (int i = 1; i < V.size(); ++i) {
			if (V[i] != V[i - 1]) {
				cout << case_num << " NOT EVEN" << "\n";
				case_num++;
				even = false;
				break;
			}
		}

		if (even) {
			cout << case_num << " EVEN" << "\n";
			case_num++;
		}
		else even = true;
		
	}
}
