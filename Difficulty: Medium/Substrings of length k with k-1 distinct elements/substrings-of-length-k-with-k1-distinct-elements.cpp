class Solution {
  public:
    int substrCount(string &s, int k) {
        int count = 0;
        int i = 0, j = 0;
        unordered_map<char, int> mpp;

        while (j < s.size()) {
            mpp[s[j]]++;

            // When window size reaches k
            if (j - i + 1 == k) {
                if (mpp.size() == k - 1) {
                    count++;
                }

                // Slide the window
                mpp[s[i]]--;
                if (mpp[s[i]] == 0) {
                    mpp.erase(s[i]);
                }
                i++;
            }

            j++;
        }

        return count;
    }
};
