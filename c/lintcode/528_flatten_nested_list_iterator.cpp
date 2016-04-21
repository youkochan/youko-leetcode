/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer,
 *     // rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds,
 *     // if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds,
 *     // if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
private:
    stack<vector<NestedInteger>::const_iterator> spit; // 当前迭代器
    stack<vector<NestedInteger>::const_iterator> seit; // 当前迭代的结束
    vector<NestedInteger>::const_iterator pit;
    vector<NestedInteger>::const_iterator eit;

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        // Initialize your data structure here.
        if (nestedList.size()) {
            pit = nestedList.begin();
            eit = nestedList.end();
            
            // 构造函数中就应该先判断一下是否有下一个
            // 当然这堆逻辑可以放在 hasNext 中
            // 但是讲道理的话，hasNext 中不应该有修改当前迭代器的操作
            // 否则连续调用 hasNext 就会出问题
            // 这里要考虑两点：
            // 1. 当前迭代器指向的是一个 vector，这时候需要入栈，寻找下一个非 vector
            // 2. 当前迭代器已经走到了尽头，为什么会出现这种情况呢？
            //    主要是因为有一些 vector 本身就是空的，所以入栈后直接就到了末尾
            //    因此当迭代器栈不为空时，这种情况需要进行出栈操作
            while (pit == eit || !(pit->isInteger())) {
                if (pit == eit) {
                    if (spit.size() && seit.size()) {
                        pit = spit.top();
                        eit = seit.top();
                        spit.pop();
                        seit.pop();
                        pit ++;
                    }
                    else
                        break;
                }
                else {
                    spit.push(pit);
                    seit.push(eit);
                    eit = pit->getList().end();
                    pit = pit->getList().begin();
                }
            }
        }
        else {
            pit = nestedList.end();
            eit = nestedList.end();
        }
    }

    // @return {int} the next element in the iteration
    int next() {
        // Write your code here
        int result = pit->getInteger();
        pit ++;
        
        while (pit == eit || !(pit->isInteger())) {
            if (pit == eit) {
                if (spit.size() && seit.size()) {
                    pit = spit.top();
                    eit = seit.top();
                    spit.pop();
                    seit.pop();
                    pit ++;
                }
                else
                    break;
            }
            else {
                spit.push(pit);
                seit.push(eit);
                eit = pit->getList().end();
                pit = pit->getList().begin();
            }
        }
        
        return result;
    }

    // @return {boolean} true if the iteration has more element or false
    bool hasNext() {
        // Write your code here
        return pit != eit;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) v.push_back(i.next());
 */