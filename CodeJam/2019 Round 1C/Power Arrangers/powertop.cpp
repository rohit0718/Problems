#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {

	int T, F;
	cin >> T >> F;

	for (int n = 0; n < T; ++n) {
		
		vector<char> solution;

		// initialise the candidate list
		vector<int> candidates;
		for (int i = 0; i < 119; ++i) candidates.push_back(i);
				
		for (int offset = 0; offset < 4; ++offset) {
			
			vector<vector<int>> next_candidates(5);
			// cout the candidate list
			for (const auto index : candidates) {
				cout << (index * 5) + offset + 1 << "\n" << flush;
				string S;
				cin >> S;
				next_candidates[S[0] - 'A'].push_back(index);
			}
			// check for minimum value of the 5 arrays
			int min = 119;
			for (int i = 0; i < 5; i++) {
				if (count(solution.begin(), solution.end(), i + 'A') > 0) continue;
				if (min > next_candidates[i].size()) min = next_candidates[i].size();
			}
			// pushing back the alpabet which has the shortest length
			for (int i = 0; i < 5; i++) {
				if (count(solution.begin(), solution.end(), i + 'A') > 0) continue;
				if (min == next_candidates[i].size()) {
					solution.push_back(i + 'A');
					candidates = next_candidates[i];
					break;
				}
			}
		}

		// adding the last letter and \0
		for (int i = 0; i < 5; i++) {
			if (count(solution.begin(), solution.end(), i + 'A') > 0) continue;
			solution.push_back(i + 'A');
		}

		solution.push_back('\0');

		cout << solution.data() << "\n" << flush;
		string verdict;
		cin >> verdict;
		
	}


	return 0;
}