class Solution {
public:
    void dfs(int i,int j,int intialcolor,int newColor,vector<vector<int>> &image)
    {
		int n = image.size();
		int m = image[0].size();
		if(i<0 || j<0) return;
		if(i>=n || j>=m) return;
		if(image[i][j] != intialcolor) return;
        
        image[i][j] = newColor;
        
		dfs(i-1,j,intialcolor,newColor,image);
		dfs(i+1,j,intialcolor,newColor,image);
		dfs(i,j-1,intialcolor,newColor,image);
		dfs(i,j+1,intialcolor,newColor,image);
	}

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        int intialcolor = image[sr][sc];
        if(intialcolor != newColor)
        	dfs(sr,sc,intialcolor,newColor,image);
        return image;
    }
};