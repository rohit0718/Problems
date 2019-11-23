#include <iostream>

using namespace std;


int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	while (true) {
		unsigned long long int n;
		cin >> n;

		if (n == 0) break;
	
		n--;
		for (int i = 0; n > 0; ++i) {
			if (n % 2 != 0) {

			}
			else n /= 2;
		}


	}


	return 0;
}