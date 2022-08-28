class Solution {
public:
    vector<string> generateParenthesis(int n) 
    {
        vector<string> result;
	if(n == 0)
    {
		string empty = "";
		result.push_back(empty);
	}
	else {
		for(int closure = 0; closure < n; closure++) 
        {
			for(auto left: generateParenthesis(closure)) 
            {
				for(auto right: generateParenthesis(n - closure - 1)) 
                {
					result.push_back("(" + left + ")" + right);
				}
			}
		}
	}
	return result;
    }
};