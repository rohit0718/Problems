#include <iostream>
#include <vector>

using namespace std;


int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T, F;
	cin >> T >> F;

	for (int n = 0; n < T; n++) {

		vector<char> ans;
		char reply;
		int A = 0;
		int B = 0;
		int C = 0;
		int D = 0;
		int E = 0;

		// first letter
		for (int i = 0; i <= 118; i++) {
			char x;
			cout << 1 + (i * 5) << "\n";
			cin >> x;
			if (x == 'A') A++;
			else if (x == 'B') B++;
			else if (x == 'C') C++;
			else if (x == 'D') D++;
			else if (x == 'E') E++;
		}

		if (A != 24) ans.push_back('A');
		else if (B != 24) ans.push_back('B');
		else if (C != 24) ans.push_back('C');
		else if (D != 24) ans.push_back('D');
		else if (E != 24) ans.push_back('E');

		A = 0;
		B = 0;
		C = 0;
		D = 0;
		E = 0;

		// second letter
		for (int i = 0; i <= 118; i++) {
			char x;
			cout << 2 + (i * 5) << "\n";
			cin >> x;
			if (x == 'A') A++;
			else if (x == 'B') B++;
			else if (x == 'C') C++;
			else if (x == 'D') D++;
			else if (x == 'E') E++;
		}

		if (A != 24) ans.push_back('A');
		else if (B != 24) ans.push_back('B');
		else if (C != 24) ans.push_back('C');
		else if (D != 24) ans.push_back('D');
		else if (E != 24) ans.push_back('E');

		A = 0;
		B = 0;
		C = 0;
		D = 0;
		E = 0;

		// third letter
		for (int i = 0; i <= 118; i++) {
			char x;
			cout << 3 + (i * 5) << "\n";
			cin >> x;
			if (x == 'A') A++;
			else if (x == 'B') B++;
			else if (x == 'C') C++;
			else if (x == 'D') D++;
			else if (x == 'E') E++;
		}

		if (A != 24) ans.push_back('A');
		else if (B != 24) ans.push_back('B');
		else if (C != 24) ans.push_back('C');
		else if (D != 24) ans.push_back('D');
		else if (E != 24) ans.push_back('E');

		A = 0;
		B = 0;
		C = 0;
		D = 0;
		E = 0;

		// fourth letter: CAREFUL! only 118 tries here!
		for (int i = 0; i <= 117; i++) {
			int A = 0;
			int B = 0;
			int C = 0;
			int D = 0;
			int E = 0;
			char x;
			cout << 4 + (i * 5) << "\n";
			cin >> x;
			if (x == 'A') A++;
			else if (x == 'B') B++;
			else if (x == 'C') C++;
			else if (x == 'D') D++;
			else if (x == 'E') E++;

		}

		// if only 22 in once char, cnfm will be that char
		if (A == 22) ans.push_back('A');
		else if (B == 22) ans.push_back('B');
		else if (C == 22) ans.push_back('C');
		else if (D == 22) ans.push_back('D');
		else if (E == 22) ans.push_back('E');

		// if 23 in 2 chars, push back whichever is not alr inside ans
		if (A == 23 && ans[0] != 'A' && ans[1] != 'A'
			&& ans[2] != 'A') ans.push_back('A');
		else if (B == 23 && ans[0] != 'B' && ans[1] != 'B'
			&& ans[2] != 'B') ans.push_back('B');
		else if (C == 23 && ans[0] != 'C' && ans[1] != 'C'
			&& ans[2] != 'C') ans.push_back('C');
		else if (D == 23 && ans[0] != 'D' && ans[1] != 'D'
			&& ans[2] != 'D') ans.push_back('D');
		else if (E == 23 && ans[0] != 'E' && ans[1] != 'E'
			&& ans[2] != 'E') ans.push_back('E');


		// adding last char to ans
		if (ans[0] != 'A' && ans[1] != 'A' && ans[2] != 'A'
			&& ans[3] != 'A') ans.push_back('A');
		if (ans[0] != 'B' && ans[1] != 'B' && ans[2] != 'B'
			&& ans[3] != 'B') ans.push_back('B');
		if (ans[0] != 'C' && ans[1] != 'C' && ans[2] != 'C'
			&& ans[3] != 'C') ans.push_back('C');
		if (ans[0] != 'D' && ans[1] != 'D' && ans[2] != 'D'
			&& ans[3] != 'D') ans.push_back('D');
		if (ans[0] != 'E' && ans[1] != 'E' && ans[2] != 'E'
			&& ans[3] != 'E') ans.push_back('E');

		for (int i = 0; i < 5; i++) {
			cout << ans[i];
		}
		cout << "\n";
		cin >> reply;
		if (reply == 'N') break;
	}



	return 0;
}