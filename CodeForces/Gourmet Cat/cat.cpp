#include <iostream>
#include <vector>

using namespace std;


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, c;
	cin >> a;
	cin >> b;
	cin >> c;
	int counter = 0;

	while (a >= 3 && b >= 2 && c >= 2) {

		a -= 3;
		b -= 2;
		c -= 2;
		counter++;

	}

	int tmpA = a;
	int tmpB = b;
	int tmpC = c;


	char mon[] = { 'x','y','z','x','z','y','x','x','y','z','x','z','y','x' };
	int days = 0;
	int maxDays = 0;
	// go form mon[0] to mon[6] till a b and c is 0 
	// and count number of days
	// repeat for 1 to 7, .... 6 to 12
	for (int i = 0; i < 7; i++) {

		for (int j = 0; j < 7; j++) {

			if (mon[j + i] == 'x') a--;
			else if (mon[j + i] == 'y') b--;
			else if (mon[j + i] == 'z') c--;
			if (a < 0 || b < 0 || c < 0) break;
			else days++;
		}

		if (days > maxDays) maxDays = days;
		days = 0;
		a = tmpA;
		b = tmpB;
		c = tmpC;

	}
		
	cout << (counter * 7) + maxDays;


	return 0;
}