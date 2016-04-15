/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */

// 用map存储某一个时刻飞机数目的变化数目
// 存储的过程就完成了排序（红黑树）
class Solution {
public:
    /**
     * @param intervals: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        // write your code here
        map<int, int> diff;
        for (int i = 0; i < airplanes.size(); i ++) {
            int start = airplanes[i].start;
            int end = airplanes[i].end;
            if (diff.find(start) != diff.end())
                diff[start] ++;
            else
                diff[start] = 1;
            
            if (diff.find(end) != diff.end())
                diff[end] --;
            else
                diff[end] = -1;
        }
        int result = 0;
        int count = 0;
        map<int, int>::iterator mit = diff.begin();
        while (mit != diff.end()) {
            count += mit->second;
            if (count > result)
                result = count;
            mit ++;
        }
        return result;
    }
};
