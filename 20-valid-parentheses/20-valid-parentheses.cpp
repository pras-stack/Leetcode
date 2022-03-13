class Solution {
public:
    bool isValid(string s) 
    {
       stack<char> st;
    for (auto &i : s)
    {
      if (i == '(' || i == '{' || i == '[')
        st.push(i);
      else
      {
        if (!st.size())
          return false;
        if (i == ')' && st.top() == '(')
          st.pop();
        else if (i == '}' && st.top() == '{')
          st.pop();
        else if (i == ']' && st.top() == '[')
          st.pop();
        else
          return false;
      }
    }
    return st.size() == 0; 
    }
};