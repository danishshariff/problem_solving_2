
class Solution {
public:
    int sumSubstrings(string &s) {
        long long total = 0;
        int n = s.length();
        const int mod = 1e9 + 7;

        for (int i = 0; i < n; i++) {
            long long num = 0;
            for (int j = i; j < n; j++) {
                num = (num * 10 + (s[j] - '0'));
                total = (total + num);
            }
        }

        return total;
    }
};
