#include <iostream>
#include <string>

using namespace std;

int main() {
	int bc = 0;
	string str; cin >> str;
	int cnt = 0;

	for (const char& ch : str) {
		if (ch == ')' && bc == 0) cnt++;
		else if (ch == ')') bc--;
		else bc++;
	}

	cout << bc + cnt;

	return 0;
}