#include <iostream>
#include <algorithm>

using namespace std;

class Building {
public:
    int s;
    int e;
    int h;

    Building(int _s, int _e, int _h) {
        s = _s;
        e = _e;
        h = _h;
    }

    // 堆的cmp函数和sort的cmp函数不太一样
    // 堆如果想实现大顶堆，那么比较函数应该 return n1 < n2，结果就是把大的元素排到了前面。
    // 如果是排序想把大的元素排在前面呢，则应该 return n1 > n2
    static bool cmpHeap(const Building &b1, const Building &b2) {
        if (b1.h != b2.h)
            return b1.h < b2.h;
        if (b1.e != b2.e)
            return b1.s > b2.s;
        return 0;
    }

    static bool cmpSort(const Building &b1, const Building &b2) {
        if (b1.s != b2.s)
            return b1.s < b2.s;
        if (b1.e != b2.e)
            return b1.e > b2.e;
        return 0;
    }
};

class Solution {
public:
    /**
     * @param buildings: A list of lists of integers
     * @return: Find the outline of those buildings
     */
    vector<vector<int> > buildingOutline(vector<vector<int> > &buildings) {
        // write your code here
        vector<vector<int>> results;
        if (buildings.size() == 0)
            return results;

        vector<Building> bsort;
        vector<Building> bheap;
        for (vector<int> &b : buildings)
            bsort.push_back(Building(b[0], b[1], b[2]));
        sort(bsort.begin(), bsort.end(), Building::cmpSort);

        int s = -1, e = -1, h = -1;
        int count = 1;
        for (Building &b : bsort) {
            //cout << "b" << count++ << endl;

            while (bheap.size() && bheap[0].e <= b.s) {
                e = bheap[0].e;
                h = bheap[0].h;
                vector<int> temp = {s, e, h};
                results.push_back(temp);

                pop_heap(bheap.begin(), bheap.end(), Building::cmpHeap);
                bheap.pop_back();

                if (!bheap.size())
                    s = e = h = -1;
                else {
                    s = e;
                    e = -1;
                    h = bheap[0].h;
                }

            }

            bheap.push_back(Building(b.s, b.e, b.h));
            push_heap(bheap.begin(), bheap.end(), Building::cmpHeap);

            /*
            cout << "=======" << endl;
            for (int i = 0; i <= bheap.size()-1; i ++)
                cout << "(" << bheap[i].s << "," << bheap[i].e << "," << bheap[i].h << ") ";
            cout << "\n=======" << endl;

            cout << "heap size: " <<  bheap.size() << endl;
            cout << "max: " << bheap[0].s << " " << bheap[0].e << " " << bheap[0].h << " " << endl;
            */

            if (h != -1 && bheap[0].h != h) {
                e = b.s;
                vector<int> temp = {s, e, h};
                results.push_back(temp);
                s = bheap[0].s;
                e = -1;
                h = bheap[0].h;
            }
            else if (h == -1) {
                s = bheap[0].s;
                h = bheap[0].h;
            }
            //cout << "s,e,h:" << s << " " << e << " " << h << " " << endl;
        }

        e = bheap[0].e;
        vector<int> temp = {s, e, h};
        results.push_back(temp);

        return results;
    }
};

int main() {
    Solution s;
    vector<vector<int>> buildings = {{1,3,3}, {2,4,4}, {5,6,1}};
    vector<vector<int>> results = s.buildingOutline(buildings);
    for (auto &result : results) {
        for (auto num : result) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
