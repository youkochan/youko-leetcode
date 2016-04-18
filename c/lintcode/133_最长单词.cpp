class Solution {
public:
    /**
     * @param dictionary: a vector of strings
     * @return: a vector of strings
     */
    vector<string> longestWords(vector<string> &dictionary) {
        // write your code here
        vector<string> results;
        int max = 0;
        for (auto &word : dictionary) {
            if (word.size() > max) {
                max = word.size();
                results.clear();
                results.push_back(word);
            }
            else if (word.size() == max) {
                results.push_back(word);
            }
        }
        return results;
    }
};
