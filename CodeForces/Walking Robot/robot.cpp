#include <iostream>
#include <vector>

using namespace std;


int main() {


	int N, bat, acc;

	cin >> N;
	cin >> bat;
	cin >> acc;
	int accMAX = acc;

	vector<int> A(N);
	for (auto &a : A)
		cin >> a;

	for (int i = 0; i < N; i++) {

		// whenever a 1 is seen, use battery, bat--, acc++
		// if battery is 0 use accumulator, acc--

		if (A[i] == 1) {
			
			if (acc == accMAX) {
				acc--;
			}
		
			else if (bat > 0) {
				bat--;
				if (acc < accMAX) acc++;
			}
			else acc--;
		}


		// whenever a 0 is seen, use accumulator, acc--
		// if accumulator is 0 use battery

		if (A[i] == 0) {
			if (acc > 0) acc--;
			else bat--;
		}

		// if both 0 return ans

		if (bat == 0 && acc == 0) {

			cout << i + 1 << "\n";
			return 0;
		}

	}


	cout << N << "\n";
	return 0;

}

