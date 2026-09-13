class Solution {
public:

    int findone(vector<vector<int>>& img1,vector<vector<int>>& img2,int n , int m,int x,int y)
    {
        int count=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int n_i=i+x;
                int n_j=j+y;
                if(n_i< 0 || n_i>=n || n_j <0 || n_j>=n) continue;
                if(img1[i][j]==1 && img2[n_i][n_j])
                {
                    count++;
                }
            }
        }
        return count;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        int m=img1[0].size();
        int maxcount=0;
        for(int i=(-n+1) ; i < n;i++)
        {
            for(int j=(-m+1);j<m;j++)
            {
                int count=findone(img1,img2,n,m,i,j);
                maxcount=max(maxcount,count);
            }
        }
        return maxcount;
    }
};