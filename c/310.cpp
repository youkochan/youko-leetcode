/**
 * Minimum Height Trees
 * https://leetcode.com/problems/minimum-height-trees/
 */

#include <iostream>
#include <vector>
#include <utility>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int> >& edges) {
        if (n <= 1) {
            vector<int> result;
            result.push_back(0);
            return result;
        }

        map<int, vector<int> > graph;
        for (int i = 0; i < n; i ++) {
            // ���Ȱ�graph[i]����ʼ��һ�飬���¾Ͳ�����Բ�ͬ����������ж�
            graph[i] = vector<int>();
        }

        for (int i = 0; i < edges.size(); i ++) {
            pair<int, int> edge = edges[i];
            graph[edge.first].push_back(edge.second);
            graph[edge.second].push_back(edge.first);
        }

        vector<int> temp_index;
        for (int i = 0; i < n; i ++) {
            if (graph[i].size() == 1)
                temp_index.push_back(i);
        }
        vector<int> new_index;

        // ��Ϊ���������£����յĶ�����Ŀ����һ���Ƕ�
        // ��ˣ��ڶ�����Ŀ���ڶ�������£�Ӧ�ü���ɾ��
        // ��Ϊһ�Ķ��㡣
        while (n > 2) {
            // ɾ��node
            for (int i = 0; i < temp_index.size(); i ++) {
                int num = graph[temp_index[i]][0];
                vector<int>::iterator it = graph[num].begin();
                // �ҵ����node�ڽ�node�������node���ڽ�node��������ɾ��
                for (it; it != graph[num].end(); it ++) {
                    if (*it == temp_index[i])
                        break;
                }
                graph[num].erase(it);
                // �����ʱ�ڽ�node�Ķȱ�Ϊ��1��˵����һ����Ҫɾ�����node
                if (graph[num].size() == 1)
                    new_index.push_back(num);
                graph.erase(temp_index[i]);
                n --;
            }

            temp_index = new_index;
            new_index.clear();
        }
        vector<int> result;
        for (int i = 0; i < temp_index.size(); i ++)
            result.push_back(temp_index[i]);
        return result;
    }
};

int main() {
    Solution s;
    vector<pair<int, int> > edges;
    edges.push_back(pair<int, int>(0, 3));
    edges.push_back(pair<int, int>(1, 3));
    edges.push_back(pair<int, int>(2, 3));
    edges.push_back(pair<int, int>(4, 3));
    edges.push_back(pair<int, int>(5, 4));

    vector<int> result = s.findMinHeightTrees(6, edges);
    for (int i = 0; i < result.size(); i ++) {
        cout << result[i] << endl;
    }

    return 0;
}
