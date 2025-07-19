class Solution {
  public:
  int func(int day,int last,vector<vector<int>>& arr,vector<vector<int>>& dp){
      if (dp[day][last] != -1) return dp[day][last];
      if(day==0){
          int maxi=0;
          for(int i=0;i<=2;i++){
              if(i!=last){
              maxi=max(maxi,arr[0][i]);
              }
          }
          return dp[day][last] = maxi;;
      }
      int maxi=0;
      for(int i=0;i<=2;i++){
          if(i!=last){
              int points=arr[day][i]+func(day-1,i,arr,dp);
              maxi=max(maxi,points);
          }
          
      }
      return dp[day][last] = maxi;;
  }
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int n = arr.size();
       vector<vector<int>> dp(n, vector<int>(4, -1));
        return func(n-1,3,arr,dp);
        
    }
};