#include <iostream>
#include <string>


using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	string s;
	cin >> s;


	int arr[15];
	for (int i = 0; i < 9; i++) cin >> arr[i];

	bool start = 0;
	bool end = 0;

	for (auto &c : s) {
		if (c - '0' < arr[c - '0' - 1] && end == 0) {
			cout << arr[c - '0' - 1];
			start = 1;
		}
		else {
			cout << c;
			if (start && c - '0' != arr[c - '0' - 1]) end = 1;
		}
		
	}
	

	return 0;
}