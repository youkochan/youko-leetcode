/**
 * 331. Verify Preorder Serialization of a Binary Tree
 * https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        if (preorder.size() == 0)
        	return true;
        // how many positions can we place a number
        int pos = 1;
        int size = preorder.size();
        for (int i = 0; i < size;) {
        	while (i + 1 < size && preorder[i+1] != ',') {
        		i ++;
        	}

        	if (preorder[i] == '#') {
        		if (pos <= 0)
        			return false;
        		pos -= 1;
        		i += 2;
        		continue;
        	}

        	if (pos <= 0)
        			return false;
        	
        	pos += 1;
        	i += 2;

       	}

        if (pos == 0)
        	return true;
        else
        	return false;
    }
};

int main() {
	Solution s;
	// string str = "9,3,4,#,#,1,#,#,2,#,6,#,#";
	// string str = "#,#,3,5,#";
	string str = "#,7,6,9,#,#,#";

	if (s.isValidSerialization(str)) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}
	return 0;
}