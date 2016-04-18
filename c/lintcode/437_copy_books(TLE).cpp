class Solution {
public:
    void findResult(vector<int> &pages,     // pages of book[i]
                    vector<int> &tasks,     // pages of people[k]
                    int bpos,               // book position
                    int ppos,               // people position
                    int tempmax,            // temp max
                    int &result) {          // the finnal result
        if (ppos == tasks.size())
            return;
        if (bpos == pages.size()) {
            if (tempmax < result)
                result = tempmax;
            return;
        }
        else {
            tasks[ppos] += pages[bpos];
            if (tasks[ppos] > tempmax)
                findResult(pages, tasks, bpos+1, ppos, tasks[ppos], result);
            else
                findResult(pages, tasks, bpos+1, ppos, tempmax, result);
            tasks[ppos] -= pages[bpos];

            findResult(pages, tasks, bpos, ppos+1, tempmax, result);
        }
        return;
    }

    /**
     * @param pages: a vector of integers
     * @param k: an integer
     * @return: an integer
     */
    int copyBooks(vector<int> &pages, int k) {
        // write your code here
        int _max = 0;
        if (pages.size() < k) {
            for (auto page : pages) {
                _max = max(_max, page);
            }
            return _max;
        }

        int result = INT_MAX;
        vector<int> tasks(k, 0);
        findResult(pages, tasks, 0, 0, 0, result);

        return result;
    }
};
