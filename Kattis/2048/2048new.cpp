#include <iostream>
#include <stack>

using namespace std;

int arr[5][5];
int ans[5][5];
int n;
bool combined = 0;
stack<int> s;


int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			cin >> arr[i][j];

	cin >> n;


	// LEFT
	if (n == 0) {
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				if (arr[i][j] == 0) continue;
				if (s.size() == 0) s.push(arr[i][j]), combined = 0;
				else if (arr[i][j] == s.top() && !combined) {
					s.pop();
					s.push(2 * arr[i][j]);
					combined = 1;
				}
				else if (arr[i][j] != 0) {
					s.push(arr[i][j]);
					combined = 0;
				}	
			}
			// pushing from stack to the ans arr
			int size = s.size();
			for (int j = size; j > 0; j--) {
				ans[i][j - 1] = s.top();
				s.pop();
			}
			// pushing 0 to rest
			for (int j = size; j < 4; ++j) {
				ans[i][j] = 0;
			}
		}
	}
	
	// UP
	else if (n == 1) {
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				if (arr[j][i] == 0) continue;
				if (s.size() == 0) {
					s.push(arr[j][i]);
					combined = 0;
				}
				else if (arr[j][i] == s.top() && !combined) {
					s.pop();
					s.push(2 * arr[j][i]);
					combined = 1;
				}
				else if (arr[j][i] != 0) {
					s.push(arr[j][i]);
					combined = 0;
				}
			}
			// pushing from stack to the ans arr
			int size = s.size();
			for (int j = size - 1; j >= 0; j--) {
				ans[j][i] = s.top();
				s.pop();
			}
			// pushing 0 to rest
			for (int j = size; j < 4; ++j) {
				ans[j][i] = 0;
			}
		}
	}

	// RIGHT
	else if (n == 2) {
		for (int i = 0; i < 4; ++i) {
			for (int j = 3; j >= 0; j--) {
				if (arr[i][j] == 0) continue;
				if (s.size() == 0) {
					s.push(arr[i][j]);
					combined = 0;
				}
				else if (arr[i][j] == s.top() && !combined) {
					s.pop();
					s.push(2 * arr[i][j]);
					combined = 1;
				}
				else if (arr[i][j] != 0) {
					s.push(arr[i][j]);
					combined = 0;
				}
			}
			// pushing from stack to the ans arr
			int size = s.size();
			for (int j = 4 - size; j < 4; j++) {
				ans[i][j] = s.top();
				s.pop();
			}
			// pushing 0 to rest
			for (int j = 0; j < 4 - size; ++j) {
				ans[i][j] = 0;
			}
		}
	}


	// DOWN
	else if (n == 3) {
		for (int i = 0; i < 4; ++i) {
			for (int j = 3; j >= 0; --j) {
				if (arr[j][i] == 0) continue;
				if (s.size() == 0) s.push(arr[j][i]), combined = 0;
				else if (arr[j][i] == s.top() && !combined) {
					s.pop();
					s.push(2 * arr[j][i]);
					combined = 1;
				}
				else if (arr[j][i] != 0) {
					s.push(arr[j][i]);
					combined = 0;
				}	
			}
			// pushing from stack to the ans arr
			int size = s.size();
			for (int j = 4 - size; j < 4; j++) {
				ans[j][i] = s.top();
				s.pop();
			}
			// pushing 0 to rest
			for (int j = 0; j < 4 - size; ++j) {
				ans[j][i] = 0;
			}
		}
	}



	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			cout << ans[i][j] << " ";
		}	
		cout << "\n";
	}
		





	return 0;
}