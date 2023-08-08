class Solution {
public:
    int arrangeCoins(int n)
    {
        long long int i=1;
		long long int j=n;
		int ans = 0;
		while(i<=j){
			long long mid=i+(j-i)/2;
			long long int coins=mid*(mid+1)/2;
			if(n>=coins){
				ans=mid;
				i=mid+1;
			}
			else{
				j=mid-1;
			}
		}
		return ans;
    }
};