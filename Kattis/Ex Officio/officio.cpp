#include <iostream>

using namespace std;


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int R, C;

	cin >> R >> C;
	// if rows are odd


	// print first line 

	for (int i = 0; i < 2 * C; i++) {
		
		if (i % 2 == 0) cout << " ";
		else cout << "_";

	}

	cout << "\n";
		
	// loop thorugh values of R
	for (int i = 0; i < R; i++) {

		// loop through C
		for (int j = 0; j < 2*C + 1; j++) {

			if (j == 0 || j == 2*C) cout << "|";
			else if (i == R - 1 && R > 2) {
				if (j % 2 == 0) cout << "|";
				else cout << "_";
			}
			else if (i != R / 2) {
				if (j % 2 == 0) cout << "|";
				else cout << " ";
			}
			else if (i == R - 1 && R <= 2) {
				if (j % 2 == 0) cout << " ";
				else cout << "_";
			}

			else cout << " ";

		}

		cout << "\n";
	}


	return 0;
}