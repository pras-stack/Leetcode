class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) 
    {
        int carry = k;
    for (int i = num.size() - 1; i >= 0 && carry > 0; --i) {
        int sum = num[i] + carry;
        num[i] = sum % 10;
        carry = sum / 10;
    }
    
    while (carry > 0) {
        num.insert(num.begin(), carry % 10);
        carry /= 10;
    }
    return num;
    }
};