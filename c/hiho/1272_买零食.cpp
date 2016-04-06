#include <iostream>
#include <vector>

using namespace std;

void search(vector<int> &prices,
            vector<int> &degree,
            int pos,
            int price_sum,
            int degree_sum,
            int cnt,
            int &result) {
    if (cnt > 3)
        return;
    if (price_sum % 50 == 0 && degree_sum > result)
        result = degree_sum;

    if (pos == prices.size())
        return;
    search(prices, degree, pos+1,price_sum+prices[pos], degree_sum+degree[pos], cnt+1, result);
    search(prices, degree, pos+1, price_sum, degree_sum, cnt, result);
}

int main() {
    int Q = 0;
    cin >> Q;
    while (Q --) {
        int N;
        cin >> N;
        vector<int> prices;
        vector<int> degree;
        while (N --) {
            float a;
            int b;
            cin >> a >> b;
            prices.push_back(a * 10);
            degree.push_back(b);
        }
        int result = 0;
        search(prices, degree, 0, 0, 0, 0, result);
        cout << result << endl;
    }

    return 0;
}
