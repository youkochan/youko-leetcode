#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	vector<int> v;
	v.push_back(111);

	for (auto i : v)
		cout << i << endl;
    //cout << to_string(18882) << endl;

	return 0;
}
