class Solution {
public:
   bool isPalindrome(int x) 
   {
	long reverse = 0;
	for(long i = 1; i <= x; i *= 10){
		reverse *= 10;
		reverse += (x / i) % 10;
	}
	return x == reverse;
}
};