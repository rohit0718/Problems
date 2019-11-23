#include <iostream>
#include <vector>
#include <string>

using namespace std;

string repeat(string s, int n)
{
	string s1 = s;

	for (int i = 1; i < n; i++)
		s += s1; 

	return s;
}

int main() {

	int T;
	cin >> T;

	for (int n = 1; n <= T; n++) {
		int A;
		cin >> A;

		vector<string> V(A);
		for (auto &v : V)
			cin >> v;

		vector<char> ans;

		// finding len of longest str
		int maxlen = 0;
		for (int i = 0; i < A; i++) {
			if (V[i].length() > maxlen) maxlen = V[i].length();
			
		}

		
		// lengthening all strings to reach the maxlen
		for (int i = 0; i < A; i++) {
			V[i] = repeat(V[i], maxlen);
		}

		int R = 0;
		int P = 0;
		int S = 0;
		bool possible = 1;

		for (int j = 0; j < maxlen; j++) {
			for (int i = 0; i < A; i++) {
				if (V[i][j] == 'R') R++;
				else if (V[i][j] == 'P') P++;
				else if (V[i][j] == 'S') S++;
			}	
			if (S > 0 && P > 0 && R > 0) {
				cout << "Case #" << n << ": IMPOSSIBLE\n";
				possible = 0;
				break;
			}
			else if (S > 0 && P == 0 && R == 0) {
				ans.push_back('R');
			}
			else if (P > 0 && S == 0 && R == 0) {
				ans.push_back('S');
			}
			else if (R > 0 && P == 0 && S == 0) {
				ans.push_back('P');
			}
			else if (S == 0) {
				ans.push_back('P');
			}
			else if (P == 0) {
				ans.push_back('R');
			}
			else if (R == 0) {
				ans.push_back('S');
				
			}
			R = 0;
			P = 0;
			S = 0;
		}

	

		if (possible) {

			cout << "Case #" << n << ": ";

			bool hasR = 0;
			bool hasP = 0;
			bool hasS = 0;

			for (int i = 0; i < maxlen; i++) {
				if (ans[i] == 'R') hasR = 1;
				if (ans[i] == 'P') hasP = 1;
				if (ans[i] == 'S') hasS = 1;
			}

			if (hasR && !hasP && !hasS) {
				ans.push_back('P');
				for (int i = 0; i <= maxlen; i++) {
					cout << ans[i];
				}
			}
			else if (hasP && !hasR && !hasS) {
				ans.push_back('S');
				for (int i = 0; i <= maxlen; i++) {
					cout << ans[i];
				}
			}
			else if (hasS && !hasP && !hasR) {
				ans.push_back('R');
				for (int i = 0; i <= maxlen; i++) {
					cout << ans[i];
				}
			}
			else {
				for (int i = 0; i < maxlen; i++) {
					cout << ans[i];
				}
			}

			cout << "\n";

		}





	}

	return 0;
}