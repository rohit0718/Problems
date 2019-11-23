#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

	int K;
	cin >> K;
	K++;
	
	string ans;
	while (K > 1) ans.push_back((K & 1) ? '7' : '4'), K /= 2;
	reverse(ans.begin(), ans.end());
	cout << ans << '\n';

	return 0;

}