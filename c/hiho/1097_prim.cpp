#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int findMinNode(vector<vector<int>> &mat,
                vector<int> &dist,
                vector<int> &flag,
                int node,
                int &sum) {
    int minNode = -1;
    int minDist = INT_MAX;
    for (int i = 0; i < dist.size(); i ++) {
        if (!flag[i] && mat[node][i] < dist[i]) {
            dist[i] = mat[node][i];
        }
        if (!flag[i] && dist[i] < minDist) {
            minDist = dist[i];
            minNode = i;
        }
    }
    sum += minDist;
    flag[minNode] = 1;
    return minNode;
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> mat(N, vector<int>(N, 0));
    vector<int> dist(N, INT_MAX);           // ��¼��ѡ�����о���δѡ�����ж���ľ���
    vector<int> flag(N, 0);                 // ��¼ÿ������ı�ѡ״̬
    for (int i = 0; i < N; i ++)
        for (int j = 0; j < N; j ++)
            cin >> mat[i][j];
    // ��ʼ��
    flag[0] = 1;
    int count = N - 1;
    int min = 0;                           // ��һ������ӵĽڵ�
    int sum = 0;

    cout << "current min: " << min << " current sum: " << sum << endl;
    while (count --) {
        min = findMinNode(mat, dist, flag, min, sum);
        cout << "current min: " << min << " current sum: " << sum << endl;
    }
    cout << sum << endl;

    return 0;
}
