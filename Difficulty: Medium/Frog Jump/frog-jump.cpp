class Solution {
  public:
    int recr(int ind,vector<int>& height,vector<int>&dp){
        
       dp[0]=0;
       if(dp[ind]!=-1) return dp[ind];
        int jump2=INT_MAX;
        int jump1=recr(ind-1,height,dp)+abs(height[ind]-height[ind-1]);
        if(ind>1)
         jump2=recr(ind-2,height,dp)+abs(height[ind]-height[ind-2]);
        return dp[ind]=min(jump1,jump2);
    }
    int minCost(vector<int>& height) {
        // Code here
        int n=height.size();
        vector<int> dp(n+1,-1);
        return recr(n-1,height,dp);
       
    }
};