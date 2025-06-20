// Function to search a node in BST.
class Solution {

  public:
    int floor(Node* root, int x) {
        // Code here
        int floori=-1;
        while(root){
            if(root->data==x){
                floori=root->data;
                return floori;
            }
            if(root->data>x){
                root=root->left;
            }
            else{
                floori=root->data;
                root=root->right;
            }
        }
        return floori;
    }
};