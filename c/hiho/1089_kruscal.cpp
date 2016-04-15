#include<iostream>
#include<algorithm>
using namespace std;

struct edge {
    int u;
    int v;
    int len;
};

int cmp(const edge a, const edge b) {
    return a.len < b.len;
}

#define M 1000005
#define N 100005
edge e[M];
int pos[N];                         //记录各个节点在哪个集合中。

void init(int n) {
    for (int i = 1; i <= n; i++) {
        pos[i] = i;
    }
}

int find(int x) {
    if (x == pos[x])
        return x;
    else {
        pos[x] = find(pos[x]);
        return pos[x];
    }
}

int kruskal(int n, int m) {
    int sum = 0,count = 1;
    for (int i = 0; i < m; i++) {
        int fx = find(e[i].u);
        int fy = find(e[i].v);
        if (fx != fy) {
            sum += e[i].len;
            count++;
            if (count == n)
                return sum;
            pos[fx] = fy;
        }
    }
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        init(n);                            //初始化并查集
        for (int i = 0; i < m; i++) {
            cin >> e[i].u >> e[i].v >> e[i].len;
        }
        sort(e, e + m, cmp);
        cout << kruskal(n, m) << endl;
    }
}
