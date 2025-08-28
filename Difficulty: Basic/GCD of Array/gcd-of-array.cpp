class Solution {
public:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);  // Euclidean algorithm
    }

    int gcd(int n, vector<int> arr) {
        int result = arr[0];
        for (int i = 1; i < n; ++i) {
            result = gcd(result, arr[i]);
        }
        return result;
    }
};