#include <iostream>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int main() {

	ll k;
	cin >> k;

	// calculating the number of digits
	int digits = 1;
	ll num = 9;
	while (k - (num * digits) > 0) {
		k -= num * digits;
		num *= 10;
		digits++;
	}

	// calculating the actual number being referenced
	ll starting_num = 1;
	for (int i = 1; i < digits; ++i) starting_num *= 10;
	ll actual_num = starting_num + ((k + digits - 1) / digits) - 1;

	// calculating index of number
	int index = (k % digits == 0) ? digits : k % digits;

	// getting ans
	string s = to_string(actual_num);
	cout << s[index - 1];

	return 0;
}