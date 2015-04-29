/**
 * Valid Parentheses 
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

bool isValid(char* s) {
    char stack[1000];
    int top = -1;
    int i = 0;
    
    while(s[i] != '\0') {

        switch(s[i]) {
        case ')':
            if(top == -1 || stack[top] != '(') {
                return false;
            }
            else {
                top --;
            }
            break;
        case '}':
            if(top == -1 || stack[top] != '{') {
                return false;
            }
            else {
                top --;
            }
            break;
        case ']':
            if(top == -1 || stack[top] != '[') {
                return false;
            }
            else {
                top --;
            }
            break;
        case '(':
        case '{':
        case '[':
            top ++;
            stack[top] = s[i];
            break;
        default:
            break;
        }
        i++;
    }

    if(top != -1)
        return false;
    else
        return true;
}


int main(int argc, char const *argv[]){
    
    if (isValid("()[]{}")) {
        printf("yes\n");
    }
    else {
        printf("no\n");
    }
    return 0;
}