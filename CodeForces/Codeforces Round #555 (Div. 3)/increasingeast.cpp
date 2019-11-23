#include <iostream>
#include <string>
#include <stack>

using namespace std;

const int MX = 1e7;
int arr[MX];
int longest[MX];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i], longest[i] = 0;
	stack<int> st;

	// pushing in longest substring from the left
	st.push(0);
	for (int i = 0; i < n; ++i) {
		if (arr[i] < arr[i + 1]) st.push(i + 1);
		else break;
	}

	int ptr = 0;
	while (!st.empty()) longest[ptr] = st.top(), st.pop(), ptr++;
	


	// pushing in longest substring from the right
	st.push(0);
	ptr = 1;
	for (int i = n - 1; i >= 0; --i) {
		if (arr[i] < arr[i - 1]) st.push(ptr), ptr++;
		else break;
	}
	st.push(ptr);
	ptr = 0;
	while (!st.empty()) longest[n - ptr] = st.top(), st.pop(), ptr++;

	int l = 0;
	int r = n - 1;
	int ans = 0;
	int prev_num = 0;
	string s;

	while (l <= r) {
		// compare wiht the prev num first
		if (arr[l] <= prev_num && arr[r] <= prev_num) break;
		else if (arr[l] > prev_num && arr[r] <= prev_num) {
			s.push_back('L'), prev_num = arr[l], l++, ans++;
		}
		else if (arr[r] > prev_num && arr[l] <= prev_num) {
			s.push_back('R'), prev_num = arr[r], r--, ans++;
		}
		else if (arr[l] < arr[r]) {
			if (arr[l] <= prev_num) break;
			else s.push_back('L'), prev_num = arr[l], l++, ans++;
		}
		else if (arr[r] < arr[l]) {
			if (arr[r] <= prev_num) break;
			else s.push_back('R'), prev_num = arr[r], r--, ans++;
		}
		else if (longest[l] > longest[r]) 
			s.push_back('L'), prev_num = arr[l], l++, ans++;
		else s.push_back('R'), prev_num = arr[r], r--, ans++;
		
	}
	cout << ans << "\n";
	for (auto &c : s) cout << c;

	return 0;

}