class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
    // int n = mat.size();
    // int knowme[n] = {0};  // Number of people who know person i
    // int iknow[n] = {0};   // Number of people person i knows

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         if (mat[i][j] == 1) {
    //             // i knows j → so j is known by someone
    //             knowme[j]++;
    //             // i knows someone
    //             iknow[i]++;
    //         }
    //     }
    // }

    // for (int i = 0; i < n; i++) {
    //     if (knowme[i] == n - 1 && iknow[i] == 0) {
    //         return i;  // i is the celebrity
    //     }
    // }

    // return -1;  // No celebrity
    
    
    int top=0;
    int down=mat.size()-1;
    while(top<down){
        if(mat[top][down]==1){
            top=top+1;
        }
        else if(mat[down][top]==1){
            down=down-1;
        }
        else{
            top++;
            down--;
        }
    }
    for(int i=0;i<mat.size();i++){
        if(i==top) continue;
        if(mat[top][i]==1||mat[i][top]==0){
            return -1;
        }
   
    }
    return top;
}
};