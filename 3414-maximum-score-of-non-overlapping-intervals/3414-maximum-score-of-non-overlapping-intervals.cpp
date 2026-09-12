class Solution {
public:
    struct Node{
        long long score=-1;
        vector<int> idx;
    };
    vector<vector<Node>> t;
    int n;
    vector<int> nextind;
    int findnext(vector<vector<int>>& intervals , int end)
    {
        int l=0;
        int h=n-1;
        int result=n;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(intervals[mid][0]>end){
                result=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return result;
    }

    Node solve(vector<vector<int>>& intervals, int i , int k)
    {
        if(k==0 ||i >=n)
            return Node();

        if(t[i][k].score!=-1) return t[i][k];

        int wt=intervals[i][2];
        int ind=intervals[i][3];
        int j=nextind[i];

        Node skip=solve(intervals,i+1,k);
        Node temp=solve(intervals,j,k-1);
        Node take;

        take.score=wt+temp.score;
        take.idx=temp.idx;
        take.idx.push_back(ind);

        sort(begin(take.idx),end(take.idx));


        Node result;
        if(take.score>skip.score)
        {
            result=take;
        }
        else if (take.score<skip.score)
        {
            result=skip;
        }
        else{
            result=(take.idx >skip.idx) ? skip:take;
        }

        return t[i][k]=result;
        
    }
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        n=intervals.size();

        nextind.resize(n);
        for(int i=0;i<n;i++)
        {
            intervals[i].push_back(i);
        }
        sort(intervals.begin(),intervals.end());

        for(int i=0;i<n;i++)
        {
            int end=intervals[i][1];
            nextind[i]=findnext(intervals,end);
        }

        int k=4;
        t.assign(n+1,vector<Node>(k+1));
        return solve(intervals,0,k).idx;
    }
};