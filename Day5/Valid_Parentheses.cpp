class Solution {
public:
    bool isValid(string s) {
        stack<int>st;
        for(int i=0;i<s.length();i++)
        {
            char ch=s[i];
            if(ch=='(' || ch=='{' || ch=='[')
            {
                st.push(ch);
            }
            else
            {   if(!st.empty())
             {
                char t = st.top();
                if((ch==')' && t =='(') || (ch=='}' && t=='{') || (ch==']' && t=='[') )
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
             else
             {
                 return false;
             }
            }
        }
        if(st.empty()==true)
        {
            return true;
        }
        else
        {
            return false;
        }
        
        
    }
};