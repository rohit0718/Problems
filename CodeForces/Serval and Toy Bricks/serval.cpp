#include <iostream>

using namespace std;

const int MX = 105;

int main() {
	// get inputs and create an 2d array (input), a row array (n),
	// a col array (m) and a height array (h) 

	int n, m, h;

	cin >> n;
	cin >> m;
	cin >> h;

	int cols[MX] = { 0 };

	for (int i = 0; i < m; i++) {

		cin >> cols[i];

	}
	
	int rows[MX] = { 0 };

	for (int i = 0; i < n; i++) {

		cin >> rows[i];

	}

	int input[MX][MX] = { {0} };

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < m; j++) {

			cin >> input[i][j];

		}
	}


	// create an output array (output) of the same dimensions

	int output[MX][MX] = { {0} };

	// iterate accross each element of the input array

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < m; j++) {

			// if 0 output 0 to the output array at the same location

			if (input[i][j] == 0) {

				output[i][j] = 0;

			}

			// if 1, check n[row] and m[col] and output the smaller number

			else {

				if (rows[i] > cols[j]) {

					output[i][j] = cols[j];

				}

				else {

					output[i][j] = rows[i];

				}

			}

		}
	}

	// print output array


	for (int i = 0; i < n; i++) {

		for (int j = 0; j < m; j++) {

			cout << output[i][j] << " ";

		}

		cout << endl;
	}


	return 0;
}