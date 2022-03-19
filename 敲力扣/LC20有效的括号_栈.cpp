class Solution {
public:
    bool isValid(string s) {
        int len=s.length();
        stack<char> st;
        for(int i=0;i<len;i++){
            char ch=s[i];
            if(ch=='(' || ch=='[' || ch=='{')
                st.emplace(ch);
            else if(ch==')' || ch==']' || ch=='}'){
                if(!st.empty()){
                    char tmp=st.top();
                    if(tmp=='(' && ch==')')
                        st.pop();
                    else if(tmp=='[' && ch==']')
                        st.pop();
                    else if(tmp=='{' && ch=='}')
                        st.pop();
                    else
                        return false;
                }else
                    return false;
            }else{
                return false;
            }
        }
        if(st.empty())
            return true;
        return false;
    }
};
