//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int lenOfLongestSubarr(vector<int>& arr, int k) {
        // code here
    //     int len=0;
    //     for(int i=0;i<arr.size();i++){
    //     int sum=0;
    //         for(int j=i;j<arr.size();j++){
    //              sum+=arr[j];
    //                 if(sum==k)
    //                 len=max(len,j-i+1);
                
    //         }
    //     }
    //     return len;
    // }
    int left=0;
    int right=0;
    int n=arr.size();
    int sum=arr[0];
    int maxl=0;
    while(right<n){
        while(left<=right && sum>k){
            sum-=arr[left];
            left++;
        }
        if(sum==k){
            maxl=max(maxl,right-left+1);
        }
        right++;
       if(right<n) sum+=arr[right];
        

    }
    return maxl;
    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.lenOfLongestSubarr(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends