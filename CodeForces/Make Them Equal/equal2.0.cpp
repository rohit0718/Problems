#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	vector<int> A(N);


	for (auto &a : A) {

		cin >> a;

	}

	sort(A.begin(), A.end());
	A.resize(unique(A.begin(), A.end()) - A.begin());

	if (A.size() > 3) {
		cout << -1;
		return 0;
	}

	if (A.size() == 1) {

		cout << 0;
		return 0;

	}

	if (A.size() == 2) {

		if ((A[1] - A[0]) % 2 == 0) cout << (A[1] - A[0]) / 2;
		else cout << A[1] - A[0];

		return 0;

	}

	if (A.size() == 3) {

		if ((A[2] - A[1]) == (A[1] - A[0])) cout << A[2] - A[1];
		else cout << -1;

		return 0;

	}



	return 0;
}