#include <iostream>
#include <vector>

using namespace std;


int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;


	for (int n = 1; n <= T; n++) {

		int N, K;
		cin >> N >> K;

		vector<int> C(N);
		for (auto &c : C)
			cin >> c;

		vector<int> D(N);
		for (auto &d : D)
			cin >> d;
				
		int maxC = -1;
		int maxD = -1;
		int count = 0;

		for (int i = 0; i < N; i++) {

			for (int j = N - 1; j >= i; j--) {
				// go from i to j, find max for both
				// abs(__ - __) <= K? count ++
				for (int k = i; k <= j; k++) {
					if (C[k] > maxC) maxC = C[k];
					if (D[k] > maxD) maxD = D[k];
				}
				if (abs(maxC - maxD) <= K) count++;
				maxC = -1;
				maxD = -1;
			}

		}


		cout << "Case #" << n << ": " << count << "\n";

	}

	return 0;
}