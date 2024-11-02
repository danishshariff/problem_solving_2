//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// long long int maxSum(int arr[], int n);

// } Driver Code Ends
class Solution {
  public:
    long long maxSum(vector<int>& arr) {
        // code here
        sort(arr.begin(),arr.end());
        long long sum=0;
        vector<int> newarr;
        int i=0;
        int j=arr.size()-1;
        while(i<j){
            newarr.push_back(arr[i]);
            newarr.push_back(arr[j]);
            i++;
            j--;
            if(i==j){
                newarr.push_back(arr[i]);
                i++;
            }
        }
        
        for(int i=1;i<arr.size();i++){
            sum+=abs(newarr[i]-newarr[i-1]);
        }
        sum+=abs(newarr[arr.size()-1]-newarr[0]);
       
        return sum;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        long long ans = ob.maxSum(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends