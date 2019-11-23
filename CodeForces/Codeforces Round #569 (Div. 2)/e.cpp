#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> prices_original;
vector<int> holdings;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		prices_original.push_back(x);
	}

	
	

	for (int i = 0; i < m; ++i) {
		int x;
		cin >> x;
		holdings.push_back(x);
	}

	// processing the queries
	int q;
	cin >> q;

	for (int i = 0; i < q; ++i) {
		int x;
		cin >> x;
		if (x == 1) {
			// update price of dish
			vector<int> prices = prices_original;
			int ptr, price;
			cin >> ptr >> price;
			prices[ptr - 1] = price;
			prices_original = prices;
			sort(prices.begin(), prices.end(), greater<int>());

			// Go down the holdings chain and 
			// delete the dish if <= holding

			for (int j = 0; j < m; ++j) {
				int curr_hol = holdings[j];
				for (int k = 0; k < prices.size(); ++k) {
					if (curr_hol >= prices[k]) {
						prices.erase(prices.begin() + k);
						break;
					}
				}
			
				if (prices.size() == 0) {
					cout << "-1\n";
					break;
				}
			}

			if (prices.size() != 0) {
				cout << prices[0] << "\n";
			}


		}
		else if (x == 2) {
			// update holdings of person
			vector<int> prices = prices_original;
			int ptr, holding;
			cin >> ptr >> holding;
			holdings[ptr - 1] = holding;
			sort(prices.begin(), prices.end(), greater<int>());

			// Go down the holdings chain and 
			// delete the dish if <= holding

			for (int j = 0; j < m; ++j) {
				int curr_hol = holdings[j];
				for (int k = 0; k < prices.size(); ++k) {
					if (curr_hol >= prices[k]) {
						prices.erase(prices.begin() + k);
						break;
					}
				}

				if (prices.size() == 0) {
					cout << "-1\n";
					break;
				}
			}

			if (prices.size() != 0) {
				cout << prices[0] << "\n";
			}
		}


	}



	return 0;
}