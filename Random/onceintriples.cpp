/////////////////////// QUESTION ///////////////////////////
// Find the element that appears once
// Given an array where every element occurs three times,
// except one element which occurs only once.
// Find the element that occurs once.
// Expected time complexity is O(n) and O(1) extra space.
//
// Examples :
//
// Input: arr[] = {12, 1, 12, 3, 12, 1, 1, 2, 3, 3}
// Output: 2
// In the given array all element appear three times
// except 2 which appears once.
//
// Input: arr[] = {10, 20, 10, 30, 10, 30, 30}
// Output: 20
// In the given array all element appear three times
// except 20 which appears once.
////////////////////////////////////////////////////////////

#include <bits/stdc++.h>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int arr[] = {10, 20, 10, 30, 10, 30, 30};

  // get the sum at each bit and modulo 3. if result is greater than 3,
  // it means that the remainder belongs to the last number

  int res = 0;
  for (int bit = 0; bit < 32; ++bit) {
    int sum = 0;
    int x = (1 << bit);
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) if (arr[i] & x) sum++;
    if (sum % 3) res |= x;
  }

  cout << res;


  return 0;
}
