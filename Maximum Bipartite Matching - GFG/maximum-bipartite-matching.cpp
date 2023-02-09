//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int maximumMatch(vector<vector<int>>&G)
	{
	    int m = G.size(), n = G[0].size();
	vector<int> matchedTo(n, -1);
	int matches = 0;
	for (int i = 0; i < m; ++i)
	{
		vector<bool> visited(n);
		if (bpm(G, i, visited, matchedTo))
			matches++;
	}
	return matches;
}

bool bpm(vector<vector<int>>&G, int u, vector<bool>&visited, vector<int>&matchedTo)
{
	for (int v = 0; v < G[u].size(); ++v)
	{
		if (G[u][v] && !visited[v])
		{
			visited[v] = true;
			if (matchedTo[v] < 0 || bpm(G, matchedTo[v], visited, matchedTo))
			{
				matchedTo[v] = u;
				return true;
			}
		}
	}
	return false;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int m, n;
		cin >> m >> n;
		vector<vector<int>>G(m, vector<int>(n, 0));
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++)
				cin >> G[i][j];
		}
		Solution obj;
		int ans = obj.maximumMatch(G);
		cout << ans << "\n";    
	}
	return 0;
}
// } Driver Code Ends