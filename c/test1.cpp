#include <iostream>

using namespace std;

int main() {
	int state = 0;
	string s;

	cin >> s;

	for(int i = 0; i <= s.size(); i ++) {
		if(s[i] == '9' && state == 0) {
			state == 1;
		}
		else if(s[i] == '7' && state == 1) {
			state == 2;
		}
		else if(s[i] == '0' && state == 2) {
			state == 3;
		}
		else if(s[i] == '6' && state == 3)
	}
}