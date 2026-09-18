class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<string> result;

        vector<int> start(26,-1);
        vector<int> end(26);

        for(int c=0;c<s.size();c++)
        {
            int ind=s[c]-'a';

            if(start[ind]==-1){
                start[ind]=c;
                // break;
            }
            end[ind]=c;
        }

        vector<bool> isvalid(26,true);

        for(int i=0;i<26;i++)
        {
            if(start[i]==-1)
                continue;
            
            for(int j=start[i] ; j<end[i];j++)
            {
                if(start[s[j]-'a']<start[i]){
                    isvalid[i]=false;
                    break;
                }
                end[i]=max(end[i],end[s[j]-'a']);
            }
        }

        int lasttaken=INT_MAX;

        for(int i=s.size()-1;i>=0;i--)
        {
            int ind=s[i]-'a';

            if(!isvalid[ind]) continue;

            if(i==start[ind] && end[ind]<lasttaken)
            {
                result.push_back(s.substr(i,end[ind]-i+1));
                lasttaken=i;
            }
        }
        return result;
    }
};