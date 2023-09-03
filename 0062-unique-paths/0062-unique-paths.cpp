class Solution {
public:
    int uniquePaths(int m, int n)
    {
        int dp[m][n];
        for(int i=0; i<m;++i)  //start iterating all the cells of the matrix
        {
            for(int j=0; j<n;++j)
            {
                if(i==0 || j==0) 
                    dp[i][j]=1;
                else
                    dp[i][j]= dp[i-1][j]+ dp[i][j-1]; // internal cells
            }
        }
        
        return dp[m-1][n-1];
    }
};