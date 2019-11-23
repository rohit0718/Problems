#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int n = 1; n <= T; ++n) {
		int A;
		cin >> A;
		vector<string> v(A);
		for (auto &s : v) cin >> s;
		
		vector<bool> done(A, 0);
		vector<char> ans;
		bool possible = 1;

		for (int i = 0; i < 500; ++i) {
			int total = 0;
			for (int j = 0; j < A; ++j) {
				if (done[j]) continue;
				string s = v[j];
				char c = s[i % s.size()];
				switch (c) {
					case('P'):
						total |= 1;
						break;
					case('S'):
						total |= 2;
						break;
					default:
						total |= 4;
				}
			}
			if (total == 1 || total == 3) {
				// push back s, check whether any of the cases are done,
				ans.push_back('S');
				for (int j = 0; j < A; ++j) {
					string s = v[j];
					char c = s[i % s.size()];
					if (c == 'P') done[j] = true;
				}
			}
			else if (total == 2 || total == 6) {
				// push back s, check whether cany of the cases are done
				ans.push_back('R');
				for (int j = 0; j < A; ++j) {
					string s = v[j];
					char c = s[i % s.size()];
					if (c == 'S') done[j] = true;
				}
			}
			else if (total == 4 || total == 5) {
				// push back p and check
				ans.push_back('P');
				for (int j = 0; j < A; ++j) {
					string s = v[j];
					char c = s[i % s.size()];
					if (c == 'R') done[j] = true;
				}
			}
			else if (total == 7) possible = 0;
			else break;
		}

		// check if possible and cout the ans here
		if (possible) {
			ans.push_back('\0');
			cout << "Case #" << n << ": " << ans.data() << "\n";
		}
		else cout << "Case #" << n << ": IMPOSSIBLE\n";

	}

	return 0;
}