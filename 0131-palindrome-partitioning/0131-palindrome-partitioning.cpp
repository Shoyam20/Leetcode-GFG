class Solution {
public:
    bool ispalind(string s, int i,int j)
    {
        while(i<=j)
        {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    void func(string s,vector<vector<string>> &v ,vector<string> temp,int ind)
    {
        if(ind==s.size())
        {
            v.push_back(temp);
            return;
        }
        for(int i =ind ;i<s.size();i++)
        {
            if(ispalind(s,ind,i))
            {
                temp.push_back(s.substr(ind,i-ind+1));
                func(s,v,temp,i+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> v;
        vector<string> temp;

        func(s,v,temp,0);
        return v;
    }
};