class Solution {
  public:
    bool isPalindrome(string& s) {
        // code here
     int st = 0;
    int e = s.length() - 1;

    while (st < e) {
        if (s[st] != s[e]) {
            return false;
        }
        st++;
        e--;
    }
    return true;

    }
};