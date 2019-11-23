#include <iostream>
#include <string>

using namespace std;


int main() {

	string s;
	int tmp;

	for (int i = 0; i < 90000000; ++i) s += to_string(i);


	int k;
	cin >> k;

	cout << s.size();


	return 0;
}