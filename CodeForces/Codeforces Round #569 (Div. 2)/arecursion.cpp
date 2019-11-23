#include <iostream>

using namespace std;


int rhombus(int x) {
	if (x == 1) return 1;
	return rhombus(x - 1) + ((x - 1) * 4);
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	cout << rhombus(n);
	   

	return 0;

}