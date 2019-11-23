#include <iostream>
#include <vector> 
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;
	n++;

	string res;
	for (; n > 1; n >>= 1) {
		cout << "starting value of res: " << res << endl;
		res += (n & 1) ? '7' : '4';

	}

	reverse(res.begin(), res.end());
	cout << res << '\n';
	return 0;
	
}