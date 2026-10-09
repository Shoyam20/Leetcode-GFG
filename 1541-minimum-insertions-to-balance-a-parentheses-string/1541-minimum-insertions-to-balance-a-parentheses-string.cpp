class Solution {
public:
    int minInsertions(string s) {
        stack<char> st;

        int  move=0;
        int count=0;
        int i=0;
       while(i<s.size())
        {
            if(s[i]=='('){
                count++;
                i++;
            }
            else 
            {
                if(count>0){
                    count--;
                }
                else{
                    move++;
                }

                if(i+1 <s.size() && s[i+1]==')'){
                    i+=2;
                }
                else{
                    move++;
                    i++;
                }
            }
            }

        
        
        

        return move+count*2;
    }
};