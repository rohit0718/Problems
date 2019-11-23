#include <iostream>

using namespace std;


int main() {

	int R, C;
	cin >> R >> C;

	// print first line

	for (int i = 0; i < 2 * C; i++) {
		if (i % 2 == 0) cout << " ";
		else cout << "_";
	}
	cout << "\n";


	// if rows are even and col are odd must print rooms horizontally
	if (R % 2 == 0 && C % 2 != 0) {

		for (int i = 0; i < R; i++) {
			// loop through the columns 
			for (int j = 0; j < 2 * C + 1; j++) {
				if (j == 0 || j == 2 * C) cout << "|";
				else if (i == R - 1 && j % 2 != 0) cout << "_";
				else if (j == (2 * C) / 2) cout << " ";
				else if (i == R - 1 && j % 2 == 0) cout << " ";
				else if (j % 2 == 0) cout << " ";
				else if (j % 2 != 0) cout << "_";
			}

			cout << "\n";
		}


	}
	// else print vertically!
	else {
	
		for (int i = 0; i < R; i++) {
			// loop through the columns 
			for (int j = 0; j < 2 * C + 1; j++) {
				if (j == 0 || j == 2 * C) cout << "|";
				else if (i == R - 1 && j % 2 != 0) cout << "_";
				else if (i == R / 2) cout << " ";
				else if (i == R - 1 && j % 2 == 0) cout << "|";
				else if (j % 2 == 0) cout << "|";
				else if (j % 2 != 0) cout << " ";
			}

			cout << "\n";
		}

	}

	return 0;

}