#include <iostream>
#include <map>

using namespace std;

class Solution {
private:
    map<int, string> _map;

public:
    Solution() {
        _map[0] = "Zero";
        _map[1] = "One";
        _map[2] = "Two";
        _map[3] = "Three";
        _map[4] = "Four";
        _map[5] = "Five";
        _map[6] = "Six";
        _map[7] = "Seven";
        _map[8] = "Eight";
        _map[9] = "Nine";
        _map[10] = "Ten";
        _map[11] = "Eleven";
        _map[12] = "Twelve";
        _map[13] = "Thirteen";
        _map[14] = "Fourteen";
        _map[15] = "Fifteen";
        _map[16] = "Sixteen";
        _map[17] = "Seventeen";
        _map[18] = "Eighteen";
        _map[19] = "Nineteen";
        _map[20] = "Twenty";
        _map[30] = "Thirty";
        _map[40] = "Forty";
        _map[50] = "Fifty";
        _map[60] = "Sixty";
        _map[70] = "Seventy";
        _map[80] = "Eighty";
        _map[90] = "Ninety";
        _map[100] = "Hundred";
        _map[1000] = "Thousand";
        _map[1000000] = "Million";
        _map[1000000000] = "Billion";
        
    }

    string numberToWords(int num) {
        int div;
        int mod;
        if (num / 1000000000) {
            div = num / 1000000000;
            mod = num % 1000000000;
            if (mod)
                return numberToWords(div) + " " + _map[1000000000] + " " + numberToWords(mod);
            else
                return numberToWords(div) + " " + _map[1000000000];
        }
        else if (num / 1000000) {
            div = num / 1000000;
            mod = num % 1000000;
            if (mod)
                return numberToWords(div) + " " + _map[1000000] + " " + numberToWords(mod);
            else
                return numberToWords(div) + " " + _map[1000000];
        }
        else if (num / 1000) {
            div = num / 1000;
            mod = num % 1000;
            if (mod)
                return numberToWords(div) + " " + _map[1000] + " " + numberToWords(mod);
            else
                return numberToWords(div) + " " + _map[1000];
        }
        else if (num / 100) {
            div = num / 100;
            mod = num % 100;
            if (mod)
                return numberToWords(div) + " " + _map[100] + " " + numberToWords(mod);             
            else
                return numberToWords(div) + " " + _map[100];
        }
        else if (num / 10) {
            div = num / 10;
            mod = num % 10;
            if (_map.find(num) != _map.end())
                return _map[num];
            else
                return numberToWords(div * 10) + " " + numberToWords(mod);
        }
        else
            return _map[num];
    }
};


int main() {
    Solution s;

    cout << s.numberToWords(0) << endl;
    cout << s.numberToWords(12345) << endl;
    cout << s.numberToWords(1234567891) << endl;

    return 0;
}