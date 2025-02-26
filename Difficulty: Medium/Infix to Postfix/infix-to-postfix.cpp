//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to return precedence of operators.
    int prec(char c) {
        if (c == '^') return 3;
        else if (c == '/' || c == '*') return 2;
        else if (c == '+' || c == '-') return 1;
        else return -1;
    }

    // Function to convert infix expression to postfix expression.
    string infixToPostfix(string& s) {
        stack<char> st; // Stack to store operators
        string result;

        int n = s.length();
        int i = 0;
        while (i < n) {
            // If operand, add to result
            if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
                result += s[i];
            } 
            // If '(', push to stack
            else if (s[i] == '(') {
                st.push(s[i]);
            } 
            // If ')', pop until '('
            else if (s[i] == ')') {
                while (!st.empty() && st.top() != '(') {
                    result += st.top();
                    st.pop();
                }
                if (!st.empty()) st.pop(); // Pop '('
            } 
            // Operator case
            else {
                while (!st.empty() && prec(s[i]) <= prec(st.top())) {
                    result += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
            i++;
        }

        // Pop remaining operators
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        return result;
    }
};






//{ Driver Code Starts.
//  Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends