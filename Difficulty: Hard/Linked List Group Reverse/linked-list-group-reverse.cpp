//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Node is defined as
    struct node
    {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

class Solution {
public:
    Node* reverseKGroup(Node* head, int k) {
        if (!head || k == 1) return head;

        Node dummy(0); 
        dummy.next = head;
        Node* prevGroupEnd = &dummy;

        while (true) {
            Node* current = prevGroupEnd->next;
            int count = 0;

            // Check if there are k nodes to reverse
            while (current && count < k) {
                current = current->next;
                count++;
            }

            if (count < k) break; // Less than k nodes left, no need to reverse

            // Reverse k nodes
            Node* prev = nullptr;
            Node* nextNode;
            current = prevGroupEnd->next;
            Node* groupStart = current;

            for (int i = 0; i < k; i++) {
                nextNode = current->next;
                current->next = prev;
                prev = current;
                current = nextNode;
            }

            // Connect reversed group with the previous part
            prevGroupEnd->next = prev;
            groupStart->next = current;
            prevGroupEnd = groupStart;
        }

        // If there are remaining nodes less than k, reverse them
        Node* remainingStart = prevGroupEnd->next;
        if (remainingStart) {
            Node* current = remainingStart;
            Node* prev = nullptr;
            Node* nextNode;
            while (current) {
                nextNode = current->next;
                current->next = prev;
                prev = current;
                current = nextNode;
            }
            prevGroupEnd->next = prev;
        }

        return dummy.next;
    }
};



//{ Driver Code Starts.

/* Driver program to test above function*/
int main(void) {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        Node* head = new Node(data);
        Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.reverseKGroup(head, k);
        printList(head);
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends