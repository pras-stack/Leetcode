//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) 
	{
	   int col=m-1;
       int row=-1;
    //   Traversing row by row
       for(int i=0;i<n;i++)
       {
        //   last column to first
           for(int j=col;j>=0;j--)
           {
               if(arr[i][j]==1)
               {
                   row=i;
                //   We will not see same column again
                   col--;
               }
            //   if you see zero 0 then skip that row
            else{
                break;
            }
           }
       }
       return row;
	}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends