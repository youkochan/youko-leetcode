/**
 * Given two integers representing the numerator and denominator of a fraction, 
 * return the fraction in string format.
 * If the fractional part is repeating, enclose the repeating part in parentheses.
 * For example,
 * Given numerator = 1, denominator = 2, return "0.5".
 * Given numerator = 2, denominator = 1, return "2".
 * Given numerator = 2, denominator = 3, return "0.(6)".
 */

/**
 * 这题不难，关键在于各种小细节。
 */

class Solution {
public:
    int find(vector<int> vmod, int mod) {
        for(int i = 0; i < vmod.size(); i ++) {
            if(vmod[i] == mod)
                return i;
        }
        
        return -1;
    }
    
    string itoa(long long i) {
        stringstream ss;
        ss << i;
        string s = ss.str();
        
        return s;
    }

    string fractionToDecimal(int numerator, int denominator) {
        bool flag = false;
        long long ln = numerator;
        long long ld = denominator;
        int index = -1;
        
        if(ln < 0) {
            flag = !flag;
            ln = -1 * ln;
        }
        if(ld < 0) {
            flag = !flag;
            ld = -1 * ld;
        }
        
        long long div = ln / ld;
        long long mod = ln % ld;
        
        string s = itoa(div);
        
        if(mod == 0 && div == 0)
            return s;
        else if(mod == 0 && div != 0) {
            if(flag)
                s = '-' + s;
            return s;
        }
        
        if(flag)
            s = '-' + s;
        
        vector<int> vmod;
        vector<int> vdiv;
        
        while(mod != 0) {
            vmod.push_back(mod);
            
            long long num = mod * 10;
            mod = num % ld;
            div = num / ld;
            
            vdiv.push_back(div);
            
            index = find(vmod, mod);
            if(index != -1)
                break;
        }
        
        s = s + '.';
        
        for(int i = 0; i != index && i < vdiv.size() ; i ++) {
            s = s + itoa(vdiv[i]);
        }
        
        if(index != -1) {
            s = s + '(';
            
            for(int i = index; i < vdiv.size(); i ++) {
                s = s + itoa(vdiv[i]);
            }
            s = s + ')';
        }
        
        return s;
    }
};