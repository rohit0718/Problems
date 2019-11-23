#include <iostream>
#include <vector>

using namespace std;


int maxAns(int n) {
	

}


int main()
{

    int n, maxN;
    vector<int> num;
	


    cin >> n;
    cin >> maxN;


    for (int i = 0; i < n; i ++) {

        int x;
        cin >> x;
        num.push_back(x);

    }

	// make a prefix sum vector and initialise values

	vector<int> numPrefixSum(n);
	numPrefixSum[0] = num[0];

	for (int i = 1; i < n; i++) {

		numPrefixSum[i] = numPrefixSum[i - 1] + num[i];

	}

	// calculate maxAns for num[0]

	int maxAns = n;
	if (maxAns % 2 != 0) maxAns -= 1;
	
	// iterate from i to i + (maxAns/2) - 1 and add all
    // iterate from i + (maxAns/2) to i + (maxAns - 1) and add all
    // if neither are > maxN, output maxAns and break
    // else maxAns -= 2 and repeat process
    // if reached 0, output 0


    for (int i = 0; i < n; i++) {

		// binary search for maxAns
       
		int x = (n / 2) - 1
		
		int left = numPrefixSum[i + x / 2 - 1] - numPrefixSum[i - 1];
		int right = numPrefixSum[i + x - 1] - numPrefixSum[i + x / 2 - 1];

		if (left > maxN || right > maxN) {

			// repeat on middle of left half

		}

		else {

			// repeat on middle of right half if valid

		}

		

		return x;
		
		// looping through all possible values of maxAns
        // staring from max and going down 2 every time
        // is ans is obtained jus break the loop
        // if k = 0 jus output 0

        for (int k = maxAns; k >= 0; k -= 2) {

            if (k == 0) {

                cout << k << endl;
				maxAns = k;
                break;

            }

            int x = 0;
            int y = 0;



			x = numPrefixSum[i + k / 2 - 1] - numPrefixSum[i - 1];
			y = numPrefixSum[i + k - 1] - numPrefixSum[i + k / 2 - 1];

            if (x <= maxN && y <= maxN) {

                cout << k << endl;
				maxAns = k;
                break;

            }

        }

    }


    return 0;
}
