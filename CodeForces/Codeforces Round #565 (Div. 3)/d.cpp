#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
vector<int> p;
vector<int> non_p;
vector<int> ans;
map<int, int> m;


int isPrime(int num)
{
	for (int i = 2; i <= num / 2; i++)
		if (num%i == 0)
			return 0; 

	return 1;
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < 2 * n; ++i) {
		int tmp;
		cin >> tmp;
		if (isPrime(tmp)) p.push_back(tmp);
		else {
			non_p.push_back(tmp);
			m[tmp]++;
		}

	}

	for (int i = 0; i < p.size() / 2; ++i) {
		ans.push_back(p[i]);
		if (ans.size() == n) {
			for (auto &k : ans) {
				cout << k << " ";
			}
			return 0;
		}
	}

	sort(non_p.begin(), non_p.end());

	for (auto &x : non_p) {
		if (m[2 * x] > 0) {
			ans.push_back(x);
			if (ans.size() == n) {
				for (auto &k : ans) {
					cout << k << " ";
				}
				return 0;
			}
			m[2 * x]--;
			m[x]--;
		}
		else {
			ans.push_back(x);
			if (ans.size() == n) {
				for (auto &k : ans) {
					cout << k << " ";
				}
				return 0;
			}
			m[x]--;
		}

	}


	return 0;
}