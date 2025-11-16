class Solution {
public:
    int priority(char ch){
        if(ch=='^') return 3;
        if(ch=='*'||ch=='/') return 2;
        if(ch=='+'||ch=='-') return 1;
        else return 0;
    }
    string infixToPrefix(const string& s) {
        string ds=s;
        reverse(ds.begin(),ds.end());
        for(int i=0;i<ds.size();i++){
            if(ds[i]=='(') ds[i]=')';
            else if(ds[i]==')') ds[i]='(';
            else continue;
        }
        stack<char> st;
        int i=0;
        string ans="";
        while(i<ds.size()){
            if((ds[i]>='0'&&ds[i]<='9')||(ds[i]>='a'&&ds[i]<='z')||(ds[i]>='A'&&ds[i]<='Z')) ans+=ds[i];
            else if(ds[i]=='(') st.push(ds[i]);
            else if(ds[i]==')'){
                while(st.size()&&st.top()!='('){
                    ans+=st.top();
                    st.pop();
                }
                if(st.size()) st.pop();
            }
            else {
                while(st.size()&&priority(ds[i])<priority(st.top())){
                    ans+=st.top();
                    st.pop();
                }
                st.push(ds[i]);
            }
            i++;
        }
        while(st.size()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};