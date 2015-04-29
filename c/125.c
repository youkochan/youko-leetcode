// Valid Palindrome Total Accepted: 47567 Total Submissions: 215704 My Submissions Question Solution 
// Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

// For example,
// "A man, a plan, a canal: Panama" is a palindrome.
// "race a car" is not a palindrome.

// Note:
// Have you consider that the string might be empty? This is a good question to ask during an interview.

// For the purpose of this problem, we define empty string as valid palindrome.

#include <stdio.h>
#include <stdlib.h>

int getChar(char c){
	if(c >= 'A' && c <= 'Z')
		return c - 'A' + 'a';
	else
		return c;
}

int isChar(char c){
	if(c >= 'a' && c <= 'z')
		return 1;
	else if(c >= 'A' && c <= 'Z')
		return 1;
	else if(c >= '0' && c <= '9')
	    return 1;
	else
		return 0;
}

int isPalindrome(char *s) {
    int l = 0;
    int r = 0;
    int n = 0;

    while(s[r] != '\0'){
    	r ++;
    	n ++;
    }

    if(r == 0)
    	return 1;

    while(!isChar(s[l]) && l <= n){ l++;}
    while(!isChar(s[r]) && r >= 0){ r--;}

    while(l < r){
    	// printf("%c---%c\n", s[l], s[r]);
    	if(getChar(s[l]) != getChar(s[r]))
    		return 0;
    	l ++;
    	r --;
        while(!isChar(s[l]) && l <= n){ l++;}
        while(!isChar(s[r]) && r >= 0){ r--;}
    }

    return 1;
}

int main(){
	// printf("%d\n", isChar('`'));
	printf("%d\n", isPalindrome("`l;`` 1o1 ??;l`"));
	return 0;
}