/**
 * Implement atoi to convert a string to an integer.
 * If no valid conversion could be performed, a zero value is returned. 
 * If the correct value is out of the range of representable values, 
 * INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
 *
 * 这一题难度不是很大，需要考虑最大最小整数以及各种特殊情况。
 */

int myAtoi(char* str) {
    int flagNum  = 0;     // 用于记录数字是否出现
    int flagTag  = 0;     // 用于记录负号是否出现
    int i = 0;
    int sum = 0;
    int num = 0;
    int tag = 1;
    
    while(str[i] != '\0') {
        if(str[i] == '-' || str[i] == '+') {
            if(flagTag == 1 || flagNum == 1) {    // "++123", "-123-" -> 0
                return 0;
            }
            else {
                flagTag = 1;
                tag = str[i] == '-' ? -1 : 1;
            }
        }
        else if(str[i] >= '0' && str[i] <= '9') {
            num = str[i] - '0';
            if(flagNum == 0) {
                flagNum = 1;
            }
            
            if(tag == -1) {  // 负数
                if((sum > -214748364) || (sum == -214748364 && num <= 8)) {
                    sum = sum * 10 - num;
                }
                else
                    return -2147483648;
            }
            else {         // 正数
                if((sum < 214748364) || (sum == 214748364 && num <= 7)) {
                    sum = sum * 10 + num;
                }
                else {
                    return 2147483647;
                }
            }
        }
        else {
            if(flagNum) {           // "12345ab3" -> 12345
                return sum;
            }
            else if(flagTag) {      // " - 12345" -> 0
                return 0;
            }
            else if(!flagNum && str[i] != ' ') {  // " b12345" -> 0
                return 0;
            }
        }
        i++;
    }
    
    return sum;
}
