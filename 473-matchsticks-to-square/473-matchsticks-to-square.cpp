class Solution {
public:
   bool calc(int pos,vector<int> &nums,vector<long long int> &sides,long long int &tar){
        if(pos == nums.size()){
            if(sides[0]==tar && sides[1]==tar && sides[2]==tar && sides[3]==tar){
                return true;
            }
            return false;
        }
        
        for(int i=0;i<4;i++){
            if(sides[i] + nums[pos] <= tar){
                sides[i] += nums[pos];
                if(calc(pos+1,nums,sides,tar)){return true;}
                sides[i] -= nums[pos];
            }
        }
        
        return false;
    }
    bool makesquare(vector<int>& matchSticks) {
        
        long long int sum = 0;
        int n = matchSticks.size();
        for(int i=0;i<n;i++){
            sum += matchSticks[i];
        }
        
        if(sum%4){return false;}
        // If sum is not divisible by 4 return false.
        if(n<4){return false;}
        // if number of matchsticks are less than 4 then square cannot be formed return false.
        long long int tar = sum/4;
        
        vector<long long int> sides(4,0);
        //To store the length od each side.
        
        
        sort(matchSticks.begin(),matchSticks.end(),greater<int>());
        //sorting matchSticks in decreasing order.
        
        return calc(0,matchSticks,sides,tar);
    }
};