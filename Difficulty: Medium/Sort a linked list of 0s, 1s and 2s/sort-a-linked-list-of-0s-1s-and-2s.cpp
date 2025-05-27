/*  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        Node* zerohead=new Node(-1);
        Node* onehead=new Node(-1);
         Node* twohead=new Node(-1);
        Node* zero=zerohead;
        Node* one=onehead;
        Node* two=twohead;
        Node* temp=head;
        
        while(temp!=nullptr){
            if(temp->data == 0){
                zero->next=temp;
                zero=temp;
            }
            else if(temp->data ==1){
                one->next=temp;
                one=temp;
            }
            else{
                two->next=temp;
                two=temp;
                
            }
            temp=temp->next;
        }
        zero->next=(onehead->next)? onehead->next: twohead->next;
        one->next=twohead->next;
        two->next=nullptr;
        
        return zerohead->next;
        
        
    }
};