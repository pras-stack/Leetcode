//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    void dfs(int start,vector<int>adj[],bool visited[]){
           
           
           visited[start]=  true;
           
           for(auto u:adj[start]){
               
               if(visited[u]==false){
                   dfs(u,adj,visited);
               }
           }
       }
    
    bool isconnect(int start,vector<int>adj[],vector<bool> &mark){
        
        bool visited[26];
        for(int i=0;i<26;i++) visited[i]=false;
        dfs(start,adj,visited);
        for(int i=0;i<26;i++){
            
            if(visited[i]==false&& mark[i]==true) return false;
        }
        return  true;
        
    }
    int isCircle(int n, vector<string> a)
    {
        // code here
        vector<bool>mark(26,false);
        vector<int>adj[26];
        vector<int>indegree(26,0),outdegree(26,0);
        
        for(int i=0;i<n;i++){
              string s = a[i];
         int u = s[0] - 'a';
          int v = s[s.size() - 1] - 'a';
          indegree[v]++;
          outdegree[u]++;
          
          adj[u].push_back(v);
          mark[u]=true;
          mark[v]=true;
            
            
        }
        for(int i=0;i<26;i++){
            if(indegree[i]!=outdegree[i]) return false;
            
            
        }
        return isconnect(a[0].front()-'a',adj,mark);
    }

};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<string> A;
        string s;
        
        for(int i = 0;i < N; i++)
        {
            cin>>s;
            A.push_back(s);
        }
        
        Solution ob;
        cout<<ob.isCircle(N, A)<<endl;
    }
    return 0;
}
// } Driver Code Ends