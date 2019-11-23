#include <iostream>
#include <vector>

using namespace std;


int main() {


	int T, F;
	cin >> T >> F;

	for (int n = 0; n < T; n++) {

		vector<char> ans(6);
		char reply;
		vector<int> startA;
		vector<int> startB;
		vector<int> startC;
		vector<int> startD;
		vector<int> startE;
		
		
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
			if (x == 'A') {
				A++;
				startA.push_back(1 + (i * 5));
			}
			else if (x == 'B') {
				B++;
				startB.push_back(1 + (i * 5));
			}
			else if (x == 'C') {
				C++;
				startC.push_back(1 + (i * 5));
			}
			else if (x == 'D') {
				D++;
				startD.push_back(1 + (i * 5));
			}
			else if (x == 'E') {
				E++;
				startE.push_back(1 + (i * 5));
			}
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

		// using the first letter to narrow searches

		vector<int> secondA;
		vector<int> secondB;
		vector<int> secondC;
		vector<int> secondD;
		vector<int> secondE;


		if (ans[0] == 'A') {
			for (int i = 0; i <= 23; i++) {
				char x;
				cout << startA[i] + 1;
				cin >> x;
				if (x == 'A') {
					A++;
					secondA.push_back(startA[i] + 1);
				}
				else if (x == 'B') {
					B++;
					secondB.push_back(startA[i] + 1);
				}
				else if (x == 'C') {
					C++;
					secondC.push_back(startA[i] + 1);
				}
				else if (x == 'D') {
					D++;
					secondD.push_back(startA[i] + 1);
				}
				else if (x == 'E') {
					E++;
					secondE.push_back(startA[i] + 1);
				}
			}
		}

		else if (ans[0] == 'B') {
			for (int i = 0; i <= 23; i++) {
				char x;
				cout << startB[i] + 1;
				cin >> x;
				if (x == 'A') {
					A++;
					secondA.push_back(startB[i] + 1);
				}
				else if (x == 'B') {
					B++;
					secondB.push_back(startB[i] + 1);
				}
				else if (x == 'C') {
					C++;
					secondC.push_back(startB[i] + 1);
				}
				else if (x == 'D') {
					D++;
					secondD.push_back(startB[i] + 1);
				}
				else if (x == 'E') {
					E++;
					secondE.push_back(startB[i] + 1);
				}
			}
		}

		else if (ans[0] == 'C') {
			for (int i = 0; i <= 23; i++) {
				char x;
				cout << startC[i] + 1;
				cin >> x;
				if (x == 'A') {
					A++;
					secondA.push_back(startC[i] + 1);
				}
				else if (x == 'B') {
					B++;
					secondB.push_back(startC[i] + 1);
				}
				else if (x == 'C') {
					C++;
					secondC.push_back(startC[i] + 1);
				}
				else if (x == 'D') {
					D++;
					secondD.push_back(startC[i] + 1);
				}
				else if (x == 'E') {
					E++;
					secondE.push_back(startC[i] + 1);
				}
			}
		}

		else if (ans[0] == 'D') {
			for (int i = 0; i <= 23; i++) {
				char x;
				cout << startD[i] + 1;
				cin >> x;
				if (x == 'A') {
					A++;
					secondA.push_back(startD[i] + 1);
				}
				else if (x == 'B') {
					B++;
					secondB.push_back(startD[i] + 1);
				}
				else if (x == 'C') {
					C++;
					secondC.push_back(startD[i] + 1);
				}
				else if (x == 'D') {
					D++;
					secondD.push_back(startD[i] + 1);
				}
				else if (x == 'E') {
					E++;
					secondE.push_back(startD[i] + 1);
				}
			}

		}

		else if (ans[0] == 'E') {
			for (int i = 0; i <= 23; i++) {
				char x;
				cout << startE[i] + 1;
				cin >> x;
				if (x == 'A') {
					A++;
					secondA.push_back(startE[i] + 1);
				}
				else if (x == 'B') {
					B++;
					secondB.push_back(startE[i] + 1);
				}
				else if (x == 'C') {
					C++;
					secondC.push_back(startE[i] + 1);
				}
				else if (x == 'D') {
					D++;
					secondD.push_back(startE[i] + 1);
				}
				else if (x == 'E') {
					E++;
					secondE.push_back(startE[i] + 1);
				}
			}

		}

		if (A != 6) ans.push_back('A');
		else if (B != 6) ans.push_back('B');
		else if (C != 6) ans.push_back('C');
		else if (D != 6) ans.push_back('D');
		else if (E != 6) ans.push_back('E');

		A = 0;
		B = 0;
		C = 0;
		D = 0;
		E = 0;

		// using the second letter to narrow searches

		vector<int> thirdA;
		vector<int> thirdB;
		vector<int> thirdC;
		vector<int> thirdD;
		vector<int> thirdE;

		if (ans[1] == 'A') {
			for (int i = 0; i <= 5; i++) {
				char x;
				cout << secondA[i] + 1;
				cin >> x;
				if (x == 'A') {
					A++;
					thirdA.push_back(secondA[i] + 1);
				}
				else if (x == 'B') {
					B++;
					thirdB.push_back(secondA[i] + 1);
				}
				else if (x == 'C') {
					C++;
					thirdC.push_back(secondA[i] + 1);
				}
				else if (x == 'D') {
					D++;
					thirdD.push_back(secondA[i] + 1);
				}
				else if (x == 'E') {
					E++;
					thirdE.push_back(secondA[i] + 1);
				}
			}
		}

		else if (ans[1] == 'B') {
			for (int i = 0; i <= 5; i++) {
				char x;
				cout << secondB[i] + 1;
				cin >> x;
				if (x == 'A') {
					A++;
					thirdA.push_back(secondB[i] + 1);
				}
				else if (x == 'B') {
					B++;
					thirdB.push_back(secondB[i] + 1);
				}
				else if (x == 'C') {
					C++;
					thirdC.push_back(secondB[i] + 1);
				}
				else if (x == 'D') {
					D++;
					thirdD.push_back(secondB[i] + 1);
				}
				else if (x == 'E') {
					E++;
					thirdE.push_back(secondB[i] + 1);
				}
			}
		}

		else if (ans[1] == 'C') {
			for (int i = 0; i <= 5; i++) {
				char x;
				cout << secondC[i] + 1;
				cin >> x;
				if (x == 'A') {
					A++;
					thirdA.push_back(secondC[i] + 1);
				}
				else if (x == 'B') {
					B++;
					thirdB.push_back(secondC[i] + 1);
				}
				else if (x == 'C') {
					C++;
					thirdC.push_back(secondC[i] + 1);
				}
				else if (x == 'D') {
					D++;
					thirdD.push_back(secondC[i] + 1);
				}
				else if (x == 'E') {
					E++;
					thirdE.push_back(secondC[i] + 1);
				}
			}
		}

		else if (ans[1] == 'D') {
			for (int i = 0; i <= 5; i++) {
				char x;
				cout << secondD[i] + 1;
				cin >> x;
				if (x == 'A') {
					A++;
					thirdA.push_back(secondD[i] + 1);
				}
				else if (x == 'B') {
					B++;
					thirdB.push_back(secondD[i] + 1);
				}
				else if (x == 'C') {
					C++;
					thirdC.push_back(secondD[i] + 1);
				}
				else if (x == 'D') {
					D++;
					thirdD.push_back(secondD[i] + 1);
				}
				else if (x == 'E') {
					E++;
					thirdE.push_back(secondD[i] + 1);
				}
			}
		}

		else if (ans[1] == 'E') {
			for (int i = 0; i <= 5; i++) {
				char x;
				cout << secondE[i] + 1;
				cin >> x;
				if (x == 'A') {
					A++;
					thirdA.push_back(secondE[i] + 1);
				}
				else if (x == 'B') {
					B++;
					thirdB.push_back(secondE[i] + 1);
				}
				else if (x == 'C') {
					C++;
					thirdC.push_back(secondE[i] + 1);
				}
				else if (x == 'D') {
					D++;
					thirdD.push_back(secondE[i] + 1);
				}
				else if (x == 'E') {
					E++;
					thirdE.push_back(secondE[i] + 1);
				}
			}
		}

		if (A != 2) ans.push_back('A');
		else if (B != 2) ans.push_back('B');
		else if (C != 2) ans.push_back('C');
		else if (D != 2) ans.push_back('D');
		else if (E != 2) ans.push_back('E');

		A = 0;
		B = 0;
		C = 0;
		D = 0;
		E = 0;

		// using first 3 letters to get the last 2 letters

		if (ans[2] == 'A') {
			for (int i = 0; i < 1; i++) {
				char x;
				cout << thirdA[i] + 1;
				cin >> x;
				if (x == 'A') {
					A++;
					ans[4] = 'A';
				}
				else if (x == 'B') {
					B++;
					ans[4] = 'B';
				}
				else if (x == 'C') {
					C++;
					ans[4] = 'C';
				}
				else if (x == 'D') {
					// fouth char is not d and not ans[0],[1],[2], ans[4] = D
					D++;
					ans[4] = 'D';
				}
				else if (x == 'E') {
					E++;
					ans[4] = 'E';
				}
			}
		}

		else if (ans[2] == 'B') {
			for (int i = 0; i < 1; i++) {
				char x;
				cout << thirdB[i] + 1;
				cin >> x;
				if (x == 'A') {
					A++;
					ans[4] = 'A';
				}
				else if (x == 'B') {
					B++;
					ans[4] = 'B';
				}
				else if (x == 'C') {
					C++;
					ans[4] = 'C';
				}
				else if (x == 'D') {
					// fouth char is not d and not ans[0],[1],[2], ans[4] = D
					D++;
					ans[4] = 'D';
				}
				else if (x == 'E') {
					E++;
					ans[4] = 'E';
				}
			}
		}

		else if (ans[2] == 'C') {
			for (int i = 0; i < 1; i++) {
				char x;
				cout << thirdC[i] + 1;
				cin >> x;
				if (x == 'A') {
					A++;
					ans[4] = 'A';
				}
				else if (x == 'B') {
					B++;
					ans[4] = 'B';
				}
				else if (x == 'C') {
					C++;
					ans[4] = 'C';
				}
				else if (x == 'D') {
					// fouth char is not d and not ans[0],[1],[2], ans[4] = D
					D++;
					ans[4] = 'D';
				}
				else if (x == 'E') {
					E++;
					ans[4] = 'E';
				}
			}
		}

		else if (ans[2] == 'D') {
			for (int i = 0; i < 1; i++) {
				char x;
				cout << thirdD[i] + 1;
				cin >> x;
				if (x == 'A') {
					A++;
					ans[4] = 'A';
				}
				else if (x == 'B') {
					B++;
					ans[4] = 'B';
				}
				else if (x == 'C') {
					C++;
					ans[4] = 'C';
				}
				else if (x == 'D') {
					// fouth char is not d and not ans[0],[1],[2], ans[4] = D
					D++;
					ans[4] = 'D';
				}
				else if (x == 'E') {
					E++;
					ans[4] = 'E';
				}
			}
		}

		else if (ans[2] == 'E') {
			for (int i = 0; i < 1; i++) {
				char x;
				cout << thirdE[i] + 1;
				cin >> x;
				if (x == 'A') {
					A++;
					ans[4] = 'A';
				}
				else if (x == 'B') {
					B++;
					ans[4] = 'B';
				}
				else if (x == 'C') {
					C++;
					ans[4] = 'C';
				}
				else if (x == 'D') {
					// fouth char is not d and not ans[0],[1],[2], ans[4] = D
					D++;
					ans[4] = 'D';
				}
				else if (x == 'E') {
					E++;
					ans[4] = 'E';
				}
			}
		}

		//only left with fourth char/ ans[3] left!

		for (int i = 0; i < 3; i++) {
			if (ans[i] == 'A') A++;
			else if (ans[i] == 'B') B++;
			else if (ans[i] == 'C') C++;
			else if (ans[i] == 'D') D++;
			else if (ans[i] == 'E') E++;
		}

		if (A != 1) ans[3] = 'A';
		else if (B != 1) ans[3] = 'B';
		else if (C != 1) ans[3] = 'C';
		else if (D != 1) ans[3] = 'D';
		else if (E != 1) ans[3] = 'E';


		for (int i = 0; i < 5; i++) {
			cout << ans[i];
		}
		cout << "\n";
		cin >> reply;
		if (reply == 'N') break;
	}



	return 0;
}