/*Given a string of numbers and operators,
return all possible results from computing
all the different possible ways to group
numbers and operators. The valid operators
are +, - and *.

Example 1
Input: "2-1-1".

((2-1)-1) = 0
(2-(1-1)) = 2
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> f(string input, map<string, vector<int> > &_map) {
        vector<int> result;
        int len=input.size();
        for(int k=0;k<len;k++)
        {
            if(input[k]=='+'||input[k]=='-'||input[k]=='*')
            {
                string s1 = input.substr(0,k);
                string s2 = input.substr(k + 1);
                vector<int> result1;
                vector<int> result2;
                _map.find(s1) != _map.end() ? result1 = _map[s1] : result1 = f(s1, _map);
                _map.find(s2) != _map.end() ? result2 = _map[s2] : result2 = f(s2, _map);
                for(vector<int>::iterator i=result1.begin();i!=result1.end();i++)
                    for(vector<int>::iterator j=result2.begin();j!=result2.end();j++)
                    {
                        if(input[k]=='+')
                            result.push_back((*i)+(*j));
                        else if(input[k]=='-')
                            result.push_back((*i)-(*j));
                        else
                            result.push_back((*i)*(*j));
                    }
            }
        }
        if(result.empty())
            result.push_back(atoi(input.c_str()));

        _map[input] = result;
        return result;
    }

    vector<int> diffWaysToCompute(string input) {
        vector<int> result;
        map<string, vector<int> > _map;
        result = f(input, _map);

        return result;
    }
};

int main () {
    Solution s;
    vector<int> result = s.diffWaysToCompute("2*3-4*5");
    for (int i = 0; i < result.size(); i ++) {
        cout << result[i] << endl;
    }

    return 0;
}
