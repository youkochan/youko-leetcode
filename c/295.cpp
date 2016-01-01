/**
 * Find Median from Data Stream
 * https://leetcode.com/problems/find-median-from-data-stream/
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int cmpMinHeap(int n1, int n2) {
	return n1 >= n2;
}

int cmpMaxHeap(int n1, int n2) {
	return n1 <= n2;
}

class MedianFinder {
private:
	vector<int> maxHeap;	// 保证大顶堆中的元素都小于小顶堆的元素
	vector<int> minHeap;	// 保证小顶堆种的元素都大于大顶堆的元素
							// 同时保证大顶堆中元素数目大于或等于小顶堆
public:

    // Adds a number into the data structure.
    void addNum(int num) {
    	if (maxHeap.size() == 0) {
    		maxHeap.push_back(num);
    		return;
       	}
    	if (maxHeap.size() > minHeap.size()) {
    		// 插入大顶堆，这时候需要把大顶堆的堆顶移到小顶堆
    		if (maxHeap[0] > num) {
    			maxHeap.push_back(num);
    			push_heap(maxHeap.begin(), maxHeap.end(), cmpMaxHeap);
    			pop_heap(maxHeap.begin(), maxHeap.end(), cmpMaxHeap);
    			int maxHeapTop = maxHeap.back();
    			maxHeap.pop_back();
    			minHeap.push_back(maxHeapTop);
    			push_heap(minHeap.begin(), minHeap.end(), cmpMinHeap);
    		}
    		else {
    			minHeap.push_back(num);
    			push_heap(minHeap.begin(), minHeap.end(), cmpMinHeap);
    		}
    	}
    	else {
    		if (maxHeap[0] >= num) {
    			maxHeap.push_back(num);
    			push_heap(maxHeap.begin(), maxHeap.end(), cmpMaxHeap);
    		}
    		else {
    			minHeap.push_back(num);
    			push_heap(minHeap.begin(), minHeap.end(), cmpMinHeap);
    			pop_heap(minHeap.begin(), minHeap.end(), cmpMinHeap);
    			int minHeapTop = minHeap.back();
    			minHeap.pop_back();
    			maxHeap.push_back(minHeapTop);
    			push_heap(maxHeap.begin(), maxHeap.end(), cmpMaxHeap);
    		}
    	}
    }

    // Returns the median of current data stream
    double findMedian() {
    	// cout << "======" << endl;
    	// for (int i : maxHeap) cout << i << " "; cout << endl;
    	// for (int i : minHeap) cout << i << " "; cout << endl;
        if (maxHeap.size() > minHeap.size()) {
        	// cout << maxHeap[0] << endl;
        	return maxHeap[0];
        }
        else {
        	// cout << double(maxHeap[0] + minHeap[0]) / 2 << endl;
        	return double(maxHeap[0] + minHeap[0]) / 2;
        }
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();


int main() {
	MedianFinder mf;
	mf.addNum(40);
	mf.findMedian();
	mf.addNum(12);
	mf.findMedian();
	mf.addNum(16);
	mf.findMedian();
	mf.addNum(14);
	mf.findMedian();
	mf.addNum(35);
	mf.findMedian();
	mf.addNum(19);
	mf.findMedian();
	mf.addNum(34);
	mf.findMedian();
	mf.addNum(35);
	mf.findMedian();
	mf.addNum(28);
	mf.findMedian();

	// 12 14 16 19 28 34 35 35 40 

	return 0;
}