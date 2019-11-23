#include <iostream>
#include <vector>
#include <string>


using namespace std;

int n, m;

void inv_row(vector<vector<int>> &x, int y) {
	for (int i = 0; i < m; ++i) {
		if (x[y][i] == 0) x[y][i] = 1;
		else if (x[y][i] == 1) x[y][i] = 0;
	}
}


void inv_col(vector<vector<int>> &x, int y) {
	for (int i = 0; i < n; ++i) {
		if (x[i][y] == 0) x[i][y] = 1;
		else if (x[i][y] == 1) x[i][y] = 0;
	}
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	
	cin >> n >> m;
	string r(n, '0');
	string c(m, '0');

	vector<int> row_sum;

	vector<vector<int>> matrix(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		int tmp = 0;
		for (int j = 0; j < m; ++j) {
			cin >> matrix[i][j];
			tmp += matrix[i][j];
		}
		row_sum.push_back(tmp);
	}

	// invertign all 0s in the first row and pushing back to string r
	// if first row is sorted leave it alone
	// if first row all 1 change to all 0
	if (row_sum[0] == m) {
		inv_row(matrix, 0);
		r[0] = '1';
		row_sum[0] = 0;
	}

	bool is_sorted = 1;
	for (int i = 1; i < m; ++i) {
		if (matrix[0][i] < matrix[0][i - 1]) {
			is_sorted = 0;
			break;
		}
	}
	
	if (!is_sorted) {

		for (int i = 0; i < m; ++i) {
			if (matrix[0][i] == 1) {
				inv_col(matrix, i);
				c[i] = '1';
			}
		}

		row_sum[0] = 0;
	}
	

	// special cases for when n and m are lesser or equal to 2
	if (n == 1) {
		cout << "YES\n" << r.data() << "\n" << c.data();
		return 0;
	}
	else if (n == 2) {

		if (row_sum[0] != 0 && row_sum[1] == 0) {
			inv_row(matrix, 1);
			r[1] = '1';
		}


		is_sorted = 1;
		for (int i = 1; i < m; ++i) {
			if (matrix[1][i] < matrix[1][i - 1]) {
				inv_row(matrix, 1);
				r[1] = '1';
				break;
			}
		}

		for (int i = 1; i < m; ++i) {
			if (matrix[1][i] < matrix[1][i - 1]) {
				is_sorted = 0;
				break;
			}
		}

		if (!is_sorted) {

			for (int i = 0; i < m; ++i) {
				if (matrix[1][i] == 0) {
					inv_col(matrix, i);
					c[i] = '1';
				}
			}
		}


		is_sorted = 1;

		for (int i = 0; i < n; ++i) {
			for (int j = 1; j < m; ++j) {
				if (j == 1 && i > 0) {
					if (matrix[i][j - 1] < matrix[i - 1][m - 1]) {
						is_sorted = 0;
						break;
					}
				}
				if (matrix[i][j] < matrix[0][j - 1]) {
					is_sorted = 0;
					break;
				}
			}
		}


		if (is_sorted) {
			cout << "YES\n";
			for (int i = 0; i < n; ++i) cout << r[i];
			cout << "\n";
			for (int i = 0; i < m; ++i) cout << c[i];
			return 0;
		}
		else {
			cout << "NO\n";
			return 0;
		}


	}





	// checking to see how many non sorted rows the array has from 1 to n - 1
	vector<int> non_sorted_rows;

	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < m; ++j) {
			if (matrix[i][j] < matrix[i][j - 1]) {
				non_sorted_rows.push_back(i);
			}
		}
	}

	if (non_sorted_rows.size() > 1) {
		int first_unsorted_row = non_sorted_rows[0];
		for (int i = 0; i < m; ++i) {
			if (matrix[first_unsorted_row][i] == 0) {
				inv_col(matrix, i);
				if (c[i] == '1') c[i] = '0';
				else c[i] = '1';
			}
		}

	}

	else {
		for (int i = 1; i < n; ++i) {
			if (row_sum[0] == 0 && row_sum[i] != 0) {
				inv_row(matrix, i);
				r[i] = '1';
			}
			else if (row_sum[0] > 0 && row_sum[i] != m) {
				inv_row(matrix, i);
				r[i] = '1';
			}
		}
	}



	// check if matrix is sorted if it is then can just print out the answer
	is_sorted = 1;

	for (int i = 0; i < n; ++i) {
		for (int j = 1; j < m; ++j) {
			if (j == 1 && i > 0) {
				if (matrix[i][j - 1] < matrix[i - 1][m - 1]) {
					is_sorted = 0;
					break;
				}
			}
			if (matrix[i][j] < matrix[0][j - 1]) {
				is_sorted = 0;
				break;
			}
		}
	}


	if (is_sorted) {
		cout << "YES\n";
		for (int i = 0; i < n; ++i) cout << r[i];
		cout << "\n";
		for (int i = 0; i < m; ++i) cout << c[i];
		return 0;
	}
	else {
		cout << "NO\n";
		return 0;
	}


	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}


	cout << "r is: " << r.data() << endl;
	cout << "c is: " << c.data() << endl;


	return 0;
}