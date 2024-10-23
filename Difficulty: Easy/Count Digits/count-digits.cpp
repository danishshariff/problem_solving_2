//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends

class Solution{
public:
    int evenlyDivides(int N){
        //code here
        int original_n=N;
        int cnt=0;
        int lastd;
        while(N>0){
        lastd=N%10;
        if(lastd!=0 && (original_n%lastd)==0){
          cnt++;
        }
        N=N/10;
      
        }
        return cnt;
    }
    
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.evenlyDivides(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends