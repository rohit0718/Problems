#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    for (int cs = 1; cs <= T; ++cs) {
        if (cs > 1) cout << "\n";
        cout << "Case #" << cs << ": ";
        vector<int> v;
        for (int i = 1; i <= 9; ++i) {
            int x; cin >> x;
            for (int j = 0; j < x; ++j) v.push_back(i);
        }
        sort(v.begin(), v.end());
        bool b = true;
        do {
            int sum = 0;
            for (int i = 0; i < v.size(); ++i) {
                if (i & 1) sum -= v[i];
                else sum += v[i];
            }
            if (!(sum % 11)) {
                b = false;
                break;
            }
        } while (next_permutation(v.begin(), v.end()));
        if (!b) cout << "YES";
        else cout << "NO";
    }


    return 0;
}
