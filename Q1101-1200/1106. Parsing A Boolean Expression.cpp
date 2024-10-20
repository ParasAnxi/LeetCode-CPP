class Solution {
public:
    bool parseBoolExpr(string s) {
        stack<char> st;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i]==')'){
                int andOp = 1;
                int orOp = 0;
                char exp;
                while(!st.empty() && st.top()!='('){
                    int y;
                    if(st.top()=='f') y = 0;
                    else y = 1;
                    andOp = andOp & y;
                    orOp = orOp | y;
                    exp = st.top();
                    st.pop();
                }
                st.pop();
                if(st.top()=='!'){
                     st.pop();
                     if(exp=='t') st.push('f');
                     else st.push('t');
                }
                else if(st.top()=='&'){
                   st.pop();
                   if(andOp==1) st.push('t');
                   else st.push('f');
                }
                else if(st.top()=='|'){
                    st.pop();
                    if(orOp==1) st.push('t');
                    else st.push('f');
                }
            }
            else{
                if(s[i]==',') continue;
                st.push(s[i]);
            }
        }
        if(st.top()=='f') return false;
        return true;
    }
};