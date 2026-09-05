class Solution {
public: bool canplace(vector<string> &board, int i , int j ,int n)
    {
        int r,c;

        r=i,c=j;

        while(r>=0 && c>=0)
        {
            if(board[r][c]=='Q')
                return false;
            r--;
            c--;
        }
        r=i,c=j;

        while(c>=0)
        {
            if(board[r][c]=='Q')
                return false;
            c--;
        }

        r=i,c=j;

        while(r<n && c>=0)
        {
            if(board[r][c]=='Q')
                return false;
            r++;
            c--;
        }

        return true;
    }
    void func(vector<vector<string>> &v , vector<string> &board,int col,int n )
    {
        if(col==n)
        {
            v.push_back(board);
            return ;
        }

        for(int i =0 ; i < n ;i++)
        {
            if(canplace(board,i,col,n))
            {
                board[i][col]='Q';
                func(v,board,col+1,n);
                board[i][col]='.';
            }
        }    
    }
    int totalNQueens(int n) {
         vector<string> board(n);

        string s(n,'.');

        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }
        vector<vector<string>> v;
        func(v,board,0,n);
        return v.size();
    }
};