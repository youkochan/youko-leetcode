#include <iostream>
#include <vector>
#include <stack>

/**
 * Evaluate Reverse Polish Notation My Submissions Question Solution 
 * Total Accepted: 52076 Total Submissions: 238864 Difficulty: Medium
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 * Valid operators are +, -, *, /. Each operand may be an integer or another expression.
 * 
 * Some examples:
 * ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 * ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 */

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (int i = 0; i < tokens.size(); i ++) {
        	string token = tokens[i];
        	if (token == "+") {
        		int num1 = s.top(); s.pop();
        		int num2 = s.top(); s.pop();
        		s.push(num1 + num2);
        	}
        	else if (token == "-") {
        		int num1 = s.top(); s.pop();
        		int num2 = s.top(); s.pop();
        		s.push(num2 - num1);
        	}
        	else if (token == "*") {
        		int num1 = s.top(); s.pop();
        		int num2 = s.top(); s.pop();
        		s.push(num1 * num2);
        	}
        	else if (token == "/") {
        		int num1 = s.top(); s.pop();
        		int num2 = s.top(); s.pop();
        		s.push(num2 / num1);
        	}
        	else {
        		s.push(atoi(token.c_str()));
        	}
        }
        return s.top();
    }
};

int main() {
	vector<string> v;
	v.push_back("0");
	v.push_back("3");
	v.push_back("/");

	Solution s;

	cout << s.evalRPN(v) << endl;

	return 0;
}