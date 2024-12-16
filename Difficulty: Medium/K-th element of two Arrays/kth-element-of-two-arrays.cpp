//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        int m = b.size();
        int i = 0, j = 0, count = 0;
        int result = -1;

        // Use two pointers to merge arrays up to the k-th element
        while (i < n && j < m) {
            if (a[i] < b[j]) {
                count++;
                if (count == k) {
                    result = a[i];
                    break;
                }
                i++;
            } else {
                count++;
                if (count == k) {
                    result = b[j];
                    break;
                }
                j++;
            }
        }

        // If one array is exhausted, continue with the other array
        while (i < n) {
            count++;
            if (count == k) {
                result = a[i];
                break;
            }
            i++;
        }

        while (j < m) {
            count++;
            if (count == k) {
                result = b[j];
                break;
            }
            j++;
        }

        return result;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> a, b;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            b.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(a, b, k) << endl << "~\n";
    }
    return 0;
}
// } Driver Code Ends