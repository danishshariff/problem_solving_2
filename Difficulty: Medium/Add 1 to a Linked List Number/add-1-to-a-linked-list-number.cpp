/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

Node* reverse(Node* head){
       if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* newhead= reverse(head->next);
    Node* front=head->next;
    front->next=head;
    head->next=NULL;
    return newhead;
}

class Solution {
  public:
    Node* addOne(Node* head) {
        // Your Code here
        head=reverse(head);
        Node* temp=head;
        int carry=1;
        while(temp!=NULL){
            temp->data=temp->data+carry;
            if(temp->data<10){
                carry=0;
                break;
            }
            else{
                temp->data=0;
                carry=1;
            }
            temp=temp->next;
            
        }
        if(carry==1){
            Node* newhead=new Node(1);
            head=reverse(head);
            newhead->next=head;
            return newhead;
            
        }
        head=reverse(head);
        return head;
    
        // return head of list after adding one
    }
};