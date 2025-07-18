class Solution {
  public:
    pair<int, int> get(int a, int b) {
        // code here
        int aa=(a^b)^a;
        int bb=(a^b)^b;
        return {aa,bb};
        }
};