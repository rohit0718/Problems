#include <iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;2

	if (n == 1) {
		cout << 1;
		return 0;
	}

	n--;
	int x = 5;

	while (n >= 2) x += 4 * n,  n--;

	cout << x;


	return 0;
}
