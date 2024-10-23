//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* next;

    // Default constructor
    Node() {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};


// } Driver Code Ends
// User function Template for C++
// User function Template for C++

/*class Node {
public:
    int data;
    Node* next;

    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};*/

class Solution {

  public:
    Node* constructLL(vector<int>& arr) {
        // if the array is empty, return NULL
        if (arr.size() == 0) return NULL;

        // Create the head node with the first element
        Node* head = new Node(arr[0]);
        Node* temp = head;

        // Loop through the rest of the array and create the linked list
        for (int i = 1; i < arr.size(); i++) {
            temp->next = new Node(arr[i]);
            temp = temp->next;  // Move the temp pointer to the newly created node
        }

        return head;  // Return the head of the linked list
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        Node* ans = ob.constructLL(arr);
        while (ans) {
            cout << ans->data << " ";
            ans = ans->next;
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends