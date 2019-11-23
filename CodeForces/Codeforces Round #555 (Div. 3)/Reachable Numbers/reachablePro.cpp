#include <iostream>
#include <map>

using namespace std;

int main() {

	map<int, bool> bio;
	int n;
	cin >> n;

	while (!bio[n]) {
		bio[n] = 1;
		n++;
		while (n % 10 == 0) n /= 10;
	}

	cout << bio.size();

	return 0;
}