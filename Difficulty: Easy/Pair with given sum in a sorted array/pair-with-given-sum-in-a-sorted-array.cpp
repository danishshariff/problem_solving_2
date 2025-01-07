//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Complete the function
        int count=0;
        int n=arr.size();
        int left=0;
        int right=n-1;
        while(left<right){
            int sum=arr[left]+arr[right];
            if (sum == target) {
                    // Count all combinations of duplicates
                    if (arr[left] == arr[right]) {
                        int totalCount = (right - left + 1);
                        count += (totalCount * (totalCount - 1)) / 2;
                        break; // All pairs with these values are counted
                    } else {
                        int leftCount = 1, rightCount = 1;

                        // Count duplicates on the left
                        while (left + 1 < right && arr[left] == arr[left + 1]) {
                            leftCount++;
                            left++;
                        }

                        // Count duplicates on the right
                        while (right - 1 > left && arr[right] == arr[right - 1]) {
                            rightCount++;
                            right--;
                        }

                        // Multiply combinations from left and right duplicates
                        count += leftCount * rightCount;

                        // Move pointers inward
                        left++;
                        right--;
                    }
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        


        return count;
}
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int target;
        string input;
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        cin >> target;
        cin.ignore();
        Solution obj;
        cout << obj.countPairs(arr, target) << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends