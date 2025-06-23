/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // Your Code Here
        map<int,int> mp;
        queue<pair<Node*,int>> q;
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        q.push({root,0});
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            Node* node=p.first;
            int line=p.second;
            
         
                mp[line]=node->data;
            
            if(node->left!=NULL){
                q.push({node->left,line-1});
            }
             if(node->right!=NULL){
                q.push({node->right,line+1});
            }
            
        }
         for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
        
    }
};