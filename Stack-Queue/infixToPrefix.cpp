class Solution {
public:
    int priority(char ch){
        if(ch=='^') return 3;
        if(ch=='*'||ch=='/') return 2;
        if(ch=='+'||ch=='-') return 1;
        else return 0;
    }
    string infixToPostfix(string s) {
        stack<char> st;
        string ans="";
        int i=0;
        while(i<s.size()){
            if((s[i]>='0'&&s[i]<='9')||(s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')) ans+=s[i];
            else if(s[i]=='(') st.push('(');
            else if(s[i]==')'){
                while(st.size()&&st.top()!='('){
                    ans+=st.top();
                    st.pop();
                }
                if(st.size()) st.pop();
            }
            else{
                while(st.size()&&priority(st.top())>priority(s[i])){
                    ans+=st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
            i++;
        }
        while(st.size()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};