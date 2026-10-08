class Solution {
public:
    string removeOuterParentheses(string s) {
        int count=0;

        string str="";
        int prev=0;

        for(int i=0;i<s.size();i++){

            if(s[i]=='('){
                count++;
            }
            else{
                count--;
            }
            if(count==0){
                str.append(s,prev+1,i-prev-1);

                // str+=s.substr(prev+1, prev-i-1);
                prev=i+1;
            }
        }
        return str;
    }
};