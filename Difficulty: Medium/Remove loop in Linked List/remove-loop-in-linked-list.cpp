/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

class Solution {
  public:
    // Function to remove a loop in the linked list.
    
    Node* startofloop(Node* head){
        Node* fast=head;
        Node* slow=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                slow=head;
                while(slow!=fast){
                    fast=fast->next;
                    slow=slow->next;
                }
                    return slow;
            }
        }
        return nullptr;
    }
    void removeLoop(Node* head) {
        // code here
        Node* startofl= startofloop(head);
        Node* temp=startofl;
        if (startofl == nullptr) return;
        
        while(temp->next !=startofl){
            temp=temp->next;
        }
        temp->next=nullptr;
        
    }
};