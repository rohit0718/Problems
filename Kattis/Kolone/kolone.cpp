#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<char, int> ii;

int main() {

	int N1, N2, T;
	cin >> N1 >> N2;
	vector<char> row1(N1);
	vector<char> row2(N2);
	for (auto &n : row1)
		cin >> n;
	reverse(row1.begin(), row1.end());
	for (auto &x : row2)
		cin >> x;
	cin >> T;


	vector<ii> row3(N1 + N2);
	for (int i = 0; i < N1; i++) {
		row3[i] = { row1[i], 0 };
	}
	for (int i = N1; i < N1 + N2; i++) {
		row3[i] = { row2[i - N1], 1 };
	}

	for (int i = 0; i < T; i++) {
		for (int i = 0; i < N1 + N2; i++) {
			if (row3[i].second == 0 && row3[i + 1].second == 1) {
				swap(row3[i], row3[i + 1]);
				i++;
			}
		}
	}

	for (int i = 0; i < N1 + N2; i++) {
		cout << row3[i].first;
	}

	cout << "\n";

	return 0;

}