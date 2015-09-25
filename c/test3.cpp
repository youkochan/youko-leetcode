#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

// bool check(string s) {
// 	int cl = 0;
// 	for (int i = 0; i <= s.size() - 1; i ++) {
// 		if (s[i] == '(') cl ++;
// 		if (s[i] == ')') cl --;
// 		if (cl < 0)
// 			return false;
// 	}
// 	return cl == 0 ? true : false;
// }

// int solve(string s) {
// 	// 先找到匹配的括号
// 	int i = 0;
// 	int cl = 0;
// 	int begin = 0;
// 	while(s[i] != '(') {
// 		if (s[i] != ' ')
// 			cout << "invalid expression" << endl;
// 		else
// 			i ++;
// 	}
// 	cl ++;
// 	begin = i;
// 	i ++;
// 	while(cl != 0) {
// 		if (s[i] == '(') cl ++;
// 		if (s[i] == ')') cl --;
// 	}
// 	i ++;
	
// }

int solve(string s) {
	char opt = ' ';
	int state = 0;
	int result = 0;


	vector<int> vector_nums;

	while(s[i] != '(') {
		if (s[i] != ' ') {
			cout << "invalid expression" << endl;
			return INT_MAX;
		}
		else
			i ++;
	}

	for (; i <= s.size() - 1; i ++) {
		if(opt == ' ' && s[i] != ' ' && s[i] != '(') {
			cout << "invalid expression" << endl;
			return;
		}
		else if(s[i] == '(') {
			continue;
		}
		else if(s[i] == ')') {
			break;
		}
	}

	i ++;

	while()



}

int main() {

	return 0;
}