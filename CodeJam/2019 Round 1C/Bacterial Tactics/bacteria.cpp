#include <iostream>
#include <vector>

using namespace std;


int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	for (int n = 1; n <= T; n++) {

		int R, C;
		cin >> R >> C;

		vector<vector<char>> matrix(R, vector<char>(C));

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cin >> matrix[i][j];
			}
		}

		vector<int> validRows;
		vector<int> validCols;
		// run through all columns, if all got # return 0
		
		for (int i = 0; i < R; i++) {
			bool rowhasHash = 0;
			for (int j = 0; j < C; j++) {
				if (matrix[i][j] == '#') rowhasHash = 1;
			}
			if (!rowhasHash) validRows.push_back(i);
		}

		// run through all rows, if all got # return 0
		for (int i = 0; i < C; i++) {
			bool colhasHash = 0;
			for (int j = 0; j < R; j++) {
				if (matrix[j][i] == '#') colhasHash = 1;
			}
			if (!colhasHash) validCols.push_back(i);
		}


		if (validRows.size() == 0 || validCols.size() == 0) {
			cout << "Case #" << n << ": 0\n";
			break;
		}

	}

	


	return 0;
}