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
		vector<int> D(N);

		for (int i = 0; i < N; i++) cin >> C[i];
		for (int i = 0; i < N; i++) cin >> D[i];
		

		int count = 0;


		int maxC = -1;
		int maxD = -1;


		// loop from 0-N to 1-N to 2-N .... to N-N
		for (int i = N; i >= 0; i--) {
			for (int j = 0; j < i; j++) {
				for (int k = 0; k < i; k++) {
					
					if (abs(C[j] - D[k]) <= K) count++;

				}
				
				
			}

			
			maxC = -1;
			maxD = -1;
		}

		cout << "Case #" << n << ": " << count << "\n";

	}
	

	return 0;
}