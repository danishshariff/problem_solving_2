// User function Template for C++

/*  Function to calculate the longest consecutive ones
 *   N: given input to calculate the longest consecutive ones
 */
class Solution {
  public:
    int maxConsecutiveOnes(int N) {
        // code here
       int maxi=0;
        int count=0;
        while(N>0){
            if(N%2==1){
                count++;
                maxi=max(maxi,count);
            }
            else{
                count=0;
            }
            N=N/2;
        }
        return maxi;
    }
};
