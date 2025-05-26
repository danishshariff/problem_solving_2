/*
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        // Code here
        unordered_map<Node*, int> visited;
        Node* temp=head;
        int timer=0;
        
        while(temp!=NULL){
            if(visited.find(temp)!=visited.end()){
                int looplen=timer-visited[temp];
                return looplen;
            }
            
            visited[temp]=timer;
            temp=temp->next;
            timer++;
        }
        
        return 0;
        
    }
};