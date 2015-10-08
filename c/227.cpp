/**
Basic Calculator II
Implement a basic calculator to evaluate a simple expression string.
The expression string contains only non-negative integers,
+, -, *, / operators and empty spaces .
The integer division should truncate toward zero.
You may assume that the given expression is always valid.

Some examples:
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5
*/


#include <iostream>
#include <cstdlib>
#include <stack>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> istack;
        stack<char> cstack;
        int num1 = 0;
        int num2 = 0;
        char opt = '+';
        for (int i=0; i <= s.size(); i ++) {
            if (s[i] == ' ') {
                continue;
            }
            else if (s[i] >= '0' && s[i] <= '9') {
                // get a number
                num2 = num2 * 10 + s[i] - '0';
                //cout << s[i] << endl;
                while (s[i+1] >= '0' && s[i+1] <= '9') {
                    num2 = num2 * 10 + s[i+1] - '0';
                    i ++;
                }
            }
            else if ((opt == '+' || opt == '-') && (s[i] == '+' || s[i] == '-')) {
                if (opt == '+')
                    num1 += num2;
                else
                    num1 -= num2;
                num2 = 0;
                opt = s[i];
            }
            else if ((opt == '*' || opt == '/') && (s[i] == '*' || s[i] == '/')) {
                if (opt == '*')
                    num1 *= num2;
                else
                    num1 /= num2;
                num2 = 0;
                opt = s[i];
            }
            else if ((opt == '+' || opt == '-') && (s[i] == '/' || s[i] == '*')) {
                istack.push(num1);
                cstack.push(opt);
                num1 = num2;
                num2 = 0;
                opt = s[i];
            }
            else if ((opt == '*' || opt == '/') && (s[i] == '+' || s[i] == '-')) {
                if (opt == '*')
                    num1 *= num2;
                else
                    num1 /= num2;
                num2 = num1;
                num1 = istack.top();
                opt = cstack.top();
                istack.pop();
                cstack.pop();
                if (opt == '+')
                    num1 += num2;
                else
                    num1 -= num2;
                num2 = 0;
                opt = s[i];
            }

            //cout << num1 << " " << num2 << " " << opt << " " << endl;
        }

        if (opt == '+')
            num1 = num1 + num2;
        else if (opt == '-')
            num1 = num1 - num2;
        else if (opt == '*')
            num1 = num1 * num2;
        else
            num1 = num1 / num2;

        if (!istack.empty()) {
            num2 = num1;
            num1 = istack.top();
            opt = cstack.top();
            istack.pop();
            cstack.pop();
            if (opt == '+')
                num1 += num2;
            else
                num1 -= num2;
        }

        return num1;
    }
};

int main() {
    Solution s;

    //cout << s.calculate("3+2*2") << endl;
    cout << s.calculate("14/3*2") << endl;
    //cout << s.calculate(" 3+5 / 2 ") << endl;

    return 0;
}
