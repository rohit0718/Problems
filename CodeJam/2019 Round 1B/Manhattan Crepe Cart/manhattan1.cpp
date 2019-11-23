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

		vector<int> x(Q + 1, 0);
		vector<int> y(Q + 1, 0);

		// read in the test cases, x coordinate, y coordinate, direction

		int X, Y;
		char dir;

		for (int i = 0; i < P; i++) {

			cin >> X >> Y >> dir;

			// updating the matrix for each person

			if (dir == 'N') {
				// if N, ++ all values from y = Y + 1 to y = Q
				for (int i = Y + 1; i <= Q; i++) {
					y[i]++;
				}
			}
			if (dir == 'S') {
				// if S, ++ all val from y = 0 to Y - 1 
				for (int i = 0; i <= Y - 1; i++) {
					y[i]++;
				}
			}
			if (dir == 'E') {
				// if E, ++ all val from X + 1 to Q
				for (int i = X + 1; i <= Q; i++) {
					x[i]++;
				}
			}
			if (dir == 'W') {
				// if W, ++ all val from 0 to X - 1
				for (int i = 0; i <= X - 1; i++) {
					x[i]++;
				}
			}

		}

		// searching matrix for the largest number
		int xCoordinate = 0;
		int yCoordinate = 0;
		int ansX = 0;
		int ansY = 0;

		for (int i = 0; i <= Q; i++) {
			if (x[i] > ansX) {
				ansX = x[i];
				xCoordinate = i;
			}
			if (y[i] > ansY) {
				ansY = y[i];
				yCoordinate = i;
			}
		}

		// output ans

		cout << "Case #" << n << ": " << xCoordinate << " " << yCoordinate << "\n";

	}


	return 0;
}