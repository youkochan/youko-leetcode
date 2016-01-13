/**
 * Clone Graph
 * https://leetcode.com/problems/clone-graph/
 */

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == nullptr)
            return nullptr;

        map<int, UndirectedGraphNode*> nodemap;         // 保存新建的节点
        map<UndirectedGraphNode*, bool> visitmap;       // 保存访问节点

        _f(node, nodemap, visitmap);

        return nodemap[node->label];
    }

    void _f(UndirectedGraphNode *node,
            map<int, UndirectedGraphNode*> &nodemap,
            map<UndirectedGraphNode*, bool> &visitmap) {
        if (!node)
            return;
        if (visitmap.find(node) != visitmap.end())
            return;
        int val = node->label;

        UndirectedGraphNode *newnode = nullptr;

        if (nodemap.find(val) == nodemap.end()) {
            newnode = new UndirectedGraphNode(val);
            nodemap[val] = newnode;
        }
        else {
            newnode = nodemap[val];
        }

        visitmap[node] = true;

        for (int i = 0; i < node->neighbors.size(); i ++) {
            UndirectedGraphNode *neighbor = node->neighbors[i];
            int nval = neighbor->label;
            UndirectedGraphNode *temp = nullptr;
            if (nodemap.find(nval) == nodemap.end()) {
                temp = new UndirectedGraphNode(nval);
                nodemap[nval] = temp;
            }
            temp = nodemap[nval];
            newnode->neighbors.push_back(temp);

            _f(neighbor, nodemap, visitmap);
        }

    }
};
