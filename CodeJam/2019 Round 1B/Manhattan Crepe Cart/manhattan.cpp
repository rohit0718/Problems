#include <iostream>
#include <vector>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T, P, Q;

	cin >> T;

	for (int n = 1; n <= T; n++) {

		cin >> P >> Q;

		vector<vector<int>> arr(Q + 1, vector<int>(Q + 1));


		for (int i = 0; i <= Q; i++) {
			for (int j = 0; j <= Q; j++) {

				arr[i][j] = 0;	

			}

		}

		// read in the test cases, x coordinate, y coordinate, direction

		int X, Y; 
		char dir;

		for (int i = 0; i < P; i++) {

			cin >> X >> Y >> dir;

			// updating the matrix for each person

			if (dir == 'N') {
				// if N, ++ all values from row = 0 to row = Q - Y - 1
				for (int i = 0; i <= Q - Y - 1; i++) {
					for (int j = 0; j <= Q; j++) {
						arr[i][j]++;
					}
				}
			}
			if (dir == 'S') {
				// if S, ++ all val from row = Q - Y + 1 to Q 
				for (int i = Q - Y + 1; i <= Q; i++) {
					for (int j = 0; j <= Q; j++) {
						arr[i][j]++;
					}
				}
			}
			if (dir == 'E') {
				// if E, ++ all val from col 
				for (int i = 0; i <= Q; i++) {
					for (int j = X + 1; j <= Q; j++) {
						arr[i][j]++;
					}
				}
			}
			if (dir == 'W') {
				// if W, ++ all val from 0 to X - 1
				for (int i = 0; i <= Q; i++) {
					for (int j = 0; j <= X - 1; j++) {
						arr[i][j]++;
					}
				}
			}

		}

		// searching matrix for the largest number
		int x = 0;
		int y = 0;
		int ans = 0;

		for (int i = Q; i >= 0; i--) {
			for (int j = 0; j <= Q; j++) {
				if (arr[i][j] > ans) {
					ans = arr[i][j];
					x = j;
					y = Q - i;

				}
			}
		}

		// output ans

		cout << "Case #" << n << ": " << x << " " << y << "\n";

	}


	return 0;
}