class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        if(s1.size() > s2.size()) return false;
    
    vector<int> count(26, 0);

    // Count characters in s1
    for(int i = 0; i < s1.size(); i++)
        count[s1[i] - 'a']++;
    
    // Sliding window over s2
    for(int i = 0; i < s2.size(); i++){
        count[s2[i] - 'a']--;
        if(i >= s1.size())
            count[s2[i - s1.size()] - 'a']++;
        
        bool allZeros = true;
        for(int j = 0; j < 26; j++)
            if(count[j] != 0){
                allZeros = false;
                break;
            }
        if(allZeros) return true;
    }
    return false;
    }
};