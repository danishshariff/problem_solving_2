class Solution {
  public:
    int maxSum(vector<int> &arr) {
        // code here
        int res=0;
        int maxi=INT_MIN;
        for(int i=0;i<arr.size()-1;i++){
            res=arr[i]+arr[i+1];
            maxi=max(maxi,res);
        }
        return maxi;
    }
};