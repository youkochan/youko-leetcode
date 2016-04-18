/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    /**
     * @param points an array of point
     * @return an integer
     */
    int maxPoints(vector<Point>& points) {
        // Write your code here
        int result = 0;

        if (points.size() == 0)
            return result;

        for (int i = 0; i < points.size(); i ++) {
            // the function k to nums
            map<double, int> mmap;

            for (int j = 0; j < points.size(); j ++) {
                if (i != j) {
                    int x1 = points[i].x;
                    int y1 = points[i].y;
                    int x2 = points[j].x;
                    int y2 = points[j].y;

                    double k = 0;
                    if (x1 == x2)
                        k = INT_MAX;
                    else
                        k = (double)(y2 - y1) / (x2 - x1);

                    if (mmap.find(k) == mmap.end())
                        mmap[k] = 1;
                    else
                        mmap[k] += 1;
                }
            }

            auto it = mmap.begin();
            while (it != mmap.end()) {
                if (it->second > result)
                    result = it->second;
                it ++;
            }
        }

        return result + 1;
    }
};

