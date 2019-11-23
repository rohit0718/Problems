#include <iostream>
#include <string>
#include <cmath>


using namespace std;
typedef long long ll;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	string A;
	cin >> n >> A;

	if (A.empty()) {

		int X = 0;

		for (int i = n; i >= 0; i--) {
			X += pow(2, i);
		}
		cout << X;
		return 0;
	}
	
	// calculate starting number

	int height = A.length();
	ll start = 0;

	for (int i = n; i >= height; i--) {

		start += pow(2, i);

	}

	
	// calculating position of ans in row
	ll length = pow(2, height);
	ll ptrBack = 0;
	ll ptrFront = length - 1;

	// loop through string reading R and L
	for (int i = 0; i < height; i++) {

	
		// if input is R
		if (A[i] == 'R') {
			ptrBack += ((ptrFront - ptrBack) + 1) / 2;
		}

		// else if input is L
		else if (A[i] == 'L') {
			ptrFront -= ((ptrFront - ptrBack) + 1) / 2;
		}

	}

	cout << start - ptrBack;
	return 0;
}