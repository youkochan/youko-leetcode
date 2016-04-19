class Solution {
public:
    /**
     * @param s A string
     * @return the length of last word
     */
    int lengthOfLastWord(string& s) {
        // Write your code here
        int len = 0;
        int pos = s.size() - 1;
        while (pos >= 0) {
            char c = s[pos];
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
                len ++;
            else {
                if (len)
                    break;
            }
            pos --;
        }

        return len;
    }
};
