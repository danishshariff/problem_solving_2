class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        int maxi=INT_MIN;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>maxi){
                maxi=arr[i];
            }
        }
        return maxi;
    }
};
