
  class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0];                 // Smallest element
        int high = matrix[n - 1][n - 1];        // Largest element

        while (low < high) {
            int mid = low + (high - low) / 2;
            int count = countLessEqual(matrix, mid);

            if (count < k)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }

private:
    // Count how many elements are less than or equal to mid
    int countLessEqual(vector<vector<int>>& matrix, int mid) {
        int count = 0;
        int n = matrix.size();
        int row = n - 1;
        int col = 0;

        while (row >= 0 && col < n) {
            if (matrix[row][col] <= mid) {
                count += row + 1;
                col++;
            } else {
                row--;
            }
        }
        return count;
    }
};
