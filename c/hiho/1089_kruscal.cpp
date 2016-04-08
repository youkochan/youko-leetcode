#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Edge {
public:
    int i;
    int j;
    int dist;

    Edge(int _i, int _j, int _d) {
        i = _i;
        j = _j;
        dist = _d;
    }

    static int cmp(const Edge &e1, const Edge &e2) {
        if (e1.dist != e2.dist)
            return e1.dist < e2.dist;
        else if (e1.i != e2.i)
            return e1.i < e2.i;
        else
            return e1.j < e2.j;
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    vector<Edge> edges;
    vector<bool> flags(M, false);

    while (M --) {
        int i, j, d;
        cin >> i >> j >> d;
        edges.push_back(Edge(i, j, d));
    }

    sort(edges.begin(), edges.end(), Edge::cmp);
    //cout << "---" << endl;
    int sum = 0;
    int count = 0;
    for (int k = 0; k < edges.size(); k ++) {
        //cout << edges[i].i << " " << edges[i].j << " " << edges[i].dist << endl;
        int i = edges[k].i, j = edges[k].j, d = edges[k].dist;
        if (!flags[i] || !flags[j]) {
            if (!flags[i]) {
                count = count + 1;
                flags[i] = true;
            }
            if (!flags[j]) {
                count = count + 1;
                flags[j] = true;
            }
            sum += d;
        }
        if (count == N)
            break;
    }

    cout << sum << endl;
    return 0;
}
