class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int i=0,j=0;
        while(j<n){
            int c=0;
            char current_char=chars[j];
            while(j<n && chars[j]==current_char){
                c++;
                j++;
            }
            chars[i++]=current_char;
            if(c>1){
                string count=to_string(c);
                for(auto p:count){
                    chars[i++]=p;
                }
            }
           
        }
         return i;
    }
};