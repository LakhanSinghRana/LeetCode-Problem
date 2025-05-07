class Solution {
public:
  int myAtoi(string s) {
    int num = 0;
    int sign = 1;
    int i = 0;
    int n = s.size();

    // Skip leading whitespaces
    while (i < n && s[i] == ' ') i++;

    // Check for sign
    if (i < n && (s[i] == '-' || s[i] == '+')) {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    // Convert digits to integer
    while (i < n && isdigit(s[i])) {
        int dig = s[i] - '0';

        // Check for overflow
        if (num > (INT_MAX - dig) / 10) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }

        num = num * 10 + dig;
        i++;
    }

    return num * sign;
}

};