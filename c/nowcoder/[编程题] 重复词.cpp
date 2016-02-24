/**
 * 对于两个字符串B和C，
 * 我们定义BC为将C接在B的后面形成的新串。
 * 一个字符串P是串A的前缀，当且仅当存在B使得A＝PB，当然B可以为空串。
 * 若P!=A,则我们称P为A的真前缀。现在定义重复词。
 * 串Q是串A的重复词当且仅当Q是A的真前缀，且A是QQ的前缀。
 * 而A的最长重复词则是A的重复词中最长的一个，或者空串（当A没有任何重复串时）。
 * 如ababab的最长重复词是abab;abc的最长重复词是空串。
 * 给定一个串s(由字母组成)，及它的长度n(1≤n≤100000)，
 * 请返回s的所有前缀的最长重复词的长度之和(空串长度为0)。
 * 测试样例：
 * 8,"babababa"
 * 返回：24
 */

/**
 * 解题思路，用一个数组保存每一个前缀的最大重复词的长度。
 * 遍历每一个前缀，遍历过程中更新数组，
 * 因为当前前缀如果如果是某一个更长前缀的重复词，那么可以更新那个更长前缀的数组的值
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Periods {
public:
    long long getLongest(int n, string s) {
        // write code here
        long long result = 0;
        int size = s.size();
        if (size == 0)
            return 0;
        
        // 保存每一个前缀的最大重复词的长度
        vector<int> temp(size);
        for (int pos = 0; pos < size; pos ++) {
            int pl = 0;
            int pr = pos + 1;
            while (pl <= pos && pr < size && s[pl] == s[pr]) {
                // cout << "pr:" << pr << " pos+1:" << pos + 1 << endl;
                temp[pr] = pos + 1;
                pl ++;
                pr ++;
            }
        }

        int sum = 0;
        for (int i = 0; i < size; i ++) {
            sum += temp[i];
        }
        
        return sum;
    }
};

int main() {
    Periods p;
    cout << p.getLongest(359,"dcfggbgcfffbbeafebeefcaedbfebbcbebfabdceffagfadfabfafaaacgfcfedcgdbbeecdccdabgbdefeeccfbebbdbbbacbaefccdceggdegeefecfgafefeeffgccafbcfabcdcaddeecacgcdagdbfgegbdbefgegcfgabbgaefdcafeecfaedceadegbeegafcdafggcbcdcedfgabdcagecebbegecccaebbdeadcdacdfeggccdfccecbecddacbgfcagaecabdageegaaabfgfdfadgdbgbgfcfggdbfbegebedagcdcebdaeadfbadgfbeaagdgedgeebccgbfafcababdfef") << endl;
    // cout << p.getLongest(8,"babababa") << endl;
    return 0;
}