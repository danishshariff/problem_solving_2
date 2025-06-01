class Solution {
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        // code here
       int count = 0;

        for (int i = 0; i < mat1.size(); i++) {
            for (int j = 0; j < mat1[0].size(); j++) {
                int a = mat1[i][j];
                int target = x - a;

               
                for (int k = 0; k < mat2.size(); k++) {
                    if (binary_search(mat2[k].begin(), mat2[k].end(), target)) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};