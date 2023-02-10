//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s)
    {
        int count = 0;
    unordered_map<char, int> h;
    for (char c : s) h[c]++;
    while (h['b'] > 0 && h['a'] > 0 && h['l'] > 1 && h['o'] > 1 && h['n'] > 0)
    {
        h['b']--;
        h['a']--;
        h['l'] -= 2;
        h['o'] -= 2;
        h['n']--;
        count++;
    }
    return count ;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends