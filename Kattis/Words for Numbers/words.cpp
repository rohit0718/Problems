#include <iostream>
#include <string>

using namespace std;

bool isNum(char n);
string ctoSingle(char x);
string ctoDouble(char x);

int main() {

	string s;

	while (getline(cin, s)) {
		for (int i = 0; i < s.length(); i++) {
				if (!isNum(s[i])) cout << s[i];
				else if (!isNum(s[i + 1]) || i == s.length() - 1) {
					string x = ctoSingle(s[i]);
					if (i == 0) toupper(x[0]);
					cout << x;
				}
				// ADD ALL CASES FROM 11 - 19 FFS..
				else {
					string x = ctoDouble(s[i]);
					string y = ctoSingle(s[i + 1]);
					x += y;
					if (i == 0) toupper(x[0]);
					cout << x;
				}	
		}
		cout << "\n";
	}

	return 0;
}


bool isNum(char n) {
	if (n != '0' || n != '1' || n != '2'
		|| n != '3' || n != '4' || n != '5'
		|| n != '6' || n != '7' || n != '8'
		|| n != '9') return false;
	else return true;
}

string ctoSingle(char x) {
	if (x == '0') return "zero";
	else if (x == '1') return "one";
	else if (x == '2') return "two";
	else if (x == '3') return "three";
	else if (x == '4') return "four";
	else if (x == '5') return "five";
	else if (x == '6') return "six";
	else if (x == '7') return "seven";
	else if (x == '8') return "eight";
	else if (x == '9') return "nine";
}

string ctoDouble(char x) {
	if (x == '2') return "twenty-";
	if (x == '3') return "thirty-";
	if (x == '4') return "fourty-";
	if (x == '5') return "fifty-";
	if (x == '6') return "sixty-";
	if (x == '7') return "seventy-";
	if (x == '8') return "eighty-";
	if (x == '9') return "ninety-";
}