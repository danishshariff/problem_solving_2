class Solution {
  public:
  bool func(int ind,int sum,vector<int>& arr,vector<vector<int>>& dp){
      if(sum==0) return true;
      if(ind==0) return arr[0]==sum;
      if(dp[ind][sum]!=-1) return dp[ind][sum];
      bool nottake=func(ind-1,sum,arr,dp);
      bool take=false;
      if(sum>=arr[ind]){
          take=func(ind-1,sum-arr[ind],arr,dp);
      }
      return dp[ind][sum]=take|| nottake;
  }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
         vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return func(arr.size()-1,sum,arr,dp);
    }
};