#include <iostream>
#include <algorithm>

using namespace std;



int main() {

	int n;

	cin >> n;

	int nums[105] = { 0 };

	for (int i = 0; i < n; i++) {

		cin >> nums[i];

	}

	sort(nums, nums + n);

	int ptr = 0;

	int firstNum = nums[0];
	int secondNum = 0;
	int thirdNum = 0;

	for (int i = 1; i < n; i++) {

		if (nums[i] != firstNum) {

			ptr = i;
			secondNum = nums[i];
			break;

		}

		if (i == n - 1) {

			cout << 0;
			return 0;

		}

	}

	for (int i = ptr + 1; i < n; i++) {

		if (nums[i] != secondNum) {

			ptr = i;
			thirdNum = nums[i];
			break;

		}

		if (i == n - 1) {

			cout << secondNum - firstNum;
			return 0;

		}

	}

	for (int i = ptr + 1; i < n; i++) {

		if (nums[i] != thirdNum) {

			cout << -1;
			return 0;

		}

	}

	if (secondNum == 0 && thirdNum == 0) {

		cout << 0;
		return 0;

	}

	if (thirdNum == 0) {

		if ((secondNum - firstNum) % 2 == 0) {

			cout << (secondNum - firstNum) / 2;
			return 0;

		}

		else {

			cout << secondNum - firstNum;
			return 0;

		}

	}
	
	
	
	if (firstNum + (thirdNum - secondNum) == secondNum) {

		cout << thirdNum - secondNum;

	}
	
	else {

		cout << -1;

	}
	
	return 0;

}