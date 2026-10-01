class StockSpanner {
public:
    vector<int> v;


    StockSpanner() {
        
    }
    
    int next(int price) {
        v.push_back(price);

        int c=1;
        int n =v.size()-1;
        for(int i=n-1;i>=0;i--)
        {
            if(v[i]>v[n]) break;
            c++;

        }

        if(v.size()==0) return 0;

        return c;    
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */




























