#include <iostream>
#include <algorithm>


using namespace std;


int main() {

	int nums[4] = { 0 };

	for (int i = 0; i < 4; i++) {

		cin >> nums[i];

	}

	sort(nums, nums + 4);

	for (int i = 0; i < 3; i++) {

		int x = nums[3] - nums[i];
		cout << x << " ";

	}


	return 0;
}