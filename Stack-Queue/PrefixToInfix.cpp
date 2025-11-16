class Solution {
public:
    string prefixToInfix(string s) {
        stack<string> st;
        for(int i=s.size()-1;i>=0;i--){
            if((s[i]>='0'&&s[i]<='9')||(s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')){ 
                st.push(string(1, s[i]));
            }
            else{
                string fe=st.top();
                st.pop();
                string se=st.top();
                st.pop();
                st.push('('+fe+s[i]+se+')');
            }
        }
        return st.top();
    }
};