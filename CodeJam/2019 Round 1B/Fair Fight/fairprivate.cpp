#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
vector<vector<int>> sparse_table_C, sparse_table_D;
vector<int> log_table;

bool maxVal(int x, int y);
int right_search(int lo, int hi);
int left_search(int lo, int hi);

int main() {

	int T;
	cin >> T;

	for (int n = 1; n <= T; n++) {
		cin >> N >> K;

		vector<int> C(N);
		for (auto &c : C)
			cin >> c;
		vector<int> D(N);
		for (auto &d : D)
			cin >> d;

		// creating of log table for all values of N
		log_table = vector<int>(N + 1);
		for (int i = 2; i < N + 1; i++) {
			log_table[i] = log_table[i / 2] + 1;
		}
		// creating of sparse tables for C
		sparse_table_C = vector<vector<int>>(log_table.back() + 1, vector<int>(N));
		sparse_table_C[0] = C;
		for (int row = 1; row < sparse_table_C.size(); row++) {
			for (int i = 0; i < N; i++) {
				sparse_table_C[row][i] = max(sparse_table_C[row - 1][i], sparse_table_C[row - 1][i + (1 << row - 1)]);
			}
		}
		// creating of sparse tables for D
		sparse_table_D = vector<vector<int>>(log_table.back() + 1, vector<int>(N));
		sparse_table_D[0] = D;
		for (int row = 1; row < sparse_table_D.size(); row++) {
			for (int i = 0; i < N; i++) {
				sparse_table_D[row][i] = max(sparse_table_D[row - 1][i], sparse_table_D[row - 1][i + (1 << row - 1)]);
			}
		}

		int count = 0;
	
		for (int i = 0; i < N; i++) {

			// search right side
			int R = right_search(i, N - 1);
			// search left side
			int L = left_search(0, i);


			if ((R != -1 && L != -1)) {
				count += 2 * (i - L + 1) * (R - i + 1)
					    - (i + 1) * (N - i);
			}
			
			cout << i << ' ' << L << ' ' << R << ' ' << count << "\n";
			
		}

		cout << "Case #" << n << ": " << count << "\n";

	}

	return 0;
}


bool maxVal(int x, int y) {
	int log = log_table[(y + 1) - x];
	int maxC = max(sparse_table_C[log][x], sparse_table_C[log][(y + 1) - (1 << log)]);
	int maxD = max(sparse_table_D[log][x], sparse_table_D[log][(y + 1) - (1 << log)]);
	if (abs(maxC - maxD) <= K) return true;
	return false;
}


int right_search(int lo, int hi) {
	int res = -1;
	int c = lo;
	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if (maxVal(c,mid)) {
			res = mid;
			lo = mid + 1;
		}
		else {
			hi = mid - 1;
		}
	}
	return res;
}
	
int left_search(int lo, int hi) {
	int res = -1;
	int c = hi;
	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if (maxVal(mid, c)) {
			res = mid;
			hi = mid - 1;
		}
		else {
			lo = mid + 1;
		}
	}
	return res;
}
