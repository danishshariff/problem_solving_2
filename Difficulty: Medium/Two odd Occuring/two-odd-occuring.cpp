class Solution {
  public:
    vector<int> twoOddNum(vector<int>& arr) {
        int xorr = 0;
        for (int i = 0; i < arr.size(); i++) {
            xorr ^= arr[i];
        }

        int rightmost = xorr & -xorr;

        int b1 = 0, b2 = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] & rightmost)
                b1 ^= arr[i];
            else
                b2 ^= arr[i];
        }

        if (b1 > b2) return {b1, b2};
        return {b2, b1};
    }
};
