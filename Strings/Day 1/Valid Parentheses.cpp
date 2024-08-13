class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto it:s){
            if(it=='('||it =='{'|| it=='[')st.push(it);
            else{
                if(st.size()==0)return false;
                char ch=st.top();
                st.pop();
                if((it==')' and ch=='(')or (it == ']' 
                and ch == '[') or
                 (it == '}' and ch == '{')) continue;
                 return false;
            }
        }
        return st.empty();
    }
};

//TC=O(N)
//SC=0(N)
