#include <iostream>

using namespace std;

int hand[200005];
int deck[200005];
int pos[200005];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);


	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) cin >> hand[i];
	for (int i = 0; i < n; ++i) cin >> deck[i], pos[deck[i]] = i + 1;


	bool can_solve = 1;
	for (int i = n - 1; i >= 0; ++i) {
		if (arr[i - 1] == 1 && arr[i] - arr[i - 1] == 1) break;
		if (arr[i] - arr[i - 1] != 1) {
			can_solve = 0;
			break;
		}
	}


	return 0;
}