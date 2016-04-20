#include <iostream>
#include <algorithm>
#include <vector>

bool cmp1 (const int &n1, const int &n2) {
    return n1 < n2;
}

int main()
{
    std::vector<int> v { 3, 1, 4, 1, 5, 9 };

    std::cout << "before make_heap: \t";
    for (auto i : v) std::cout << i << ' ';
    std::cout << '\n';

    std::make_heap(v.begin(), v.end());

    std::cout << "after make_heap: \t";
    for (auto i : v) std::cout << i << ' ';
    std::cout << '\n';

    v.push_back(6);

    std::cout << "before push_heap: \t";
    for (auto i : v) std::cout << i << ' ';
    std::cout << '\n';

    std::push_heap(v.begin(), v.end());

    std::cout << "after push_heap: \t";
    for (auto i : v) std::cout << i << ' ';
    std::cout << '\n';

    std::cout << "==================" << std::endl;
    std::vector<int> v2 { 3, 1, 4, 1, 5, 9 };
    std::vector<int> v3 { 3, 1, 4, 1, 5, 9 };
    std::cout << "v2: \t";
    for (auto i : v2) std::cout << i << ' ';
    std::cout << '\n';
    std::cout << "v3: \t";
    for (auto i : v3) std::cout << i << ' ';
    std::cout << '\n';

    std::make_heap(v2.begin(), v2.end(), cmp1);
    std::cout << "v2 after make_heap with cmp1: \t";
    for (auto i : v2) std::cout << i << ' ';
    std::cout << '\n';

    std::sort(v3.begin(), v3.end(), cmp1);
    std::cout << "v3 after sort with cmp1: \t";
    for (auto i : v3) std::cout << i << ' ';
    std::cout << '\n';

    std::cout << "==================" << std::endl;
    std::vector<int> v4 { 3, 1, 4, 1, 5, 9 };
    std::vector<int> v5 { 3, 1, 4, 1, 5, 9 };
    std::cout << "v4: \t";
    for (auto i : v4) std::cout << i << ' ';
    std::cout << '\n';
    std::cout << "v5: \t";
    for (auto i : v5) std::cout << i << ' ';
    std::cout << '\n';

    std::make_heap(v4.begin(), v4.end(), std::greater<int>());
    std::cout << "v4 after make_heap with greater<int>: \t";
    for (auto i : v4) std::cout << i << ' ';
    std::cout << '\n';

    std::sort(v5.begin(), v5.end(), std::greater<int>());
    std::cout << "v5 after sort with greater<int>: \t";
    for (auto i : v5) std::cout << i << ' ';
    std::cout << '\n';

    return 0;
}


