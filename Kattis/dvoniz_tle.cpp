#include <iostream>
#include <vector>

using namespace std;

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


    // iterate from i to i + (maxAns/2) - 1 and add all
    // iterate from i + (maxAns/2) to i + (maxAns - 1) and add all
    // if neither are > maxN, output maxAns and break
    // else maxAns -= 2 and repeat process
    // if reached 0, output 0


    for (int i = 0; i < n; i++) {


        // calculating maxAns possible for current value of i

        int maxAns = n - i;
        if (maxAns % 2 != 0) maxAns -= 1;

        // looping through all possible values of maxAns
        // staring from max and going down 2 every time
        // is ans is obtained jus break the loop
        // if k = 0 jus output 0

        for (int k = maxAns; k >= 0; k -= 2) {

            if (k == 0) {

                cout << k << endl;
                break;

            }

            int x = 0;
            int y = 0;

            for (int j = i; j < i + (k / 2); j++) {

                x += num[j];

            }


           for (int j = i + (k / 2); j < i + k; j++) {

                y += num[j];

            }


            if (x <= maxN && y <= maxN) {

                cout << k << endl;
                break;

            }

        }

    }




    return 0;
}
