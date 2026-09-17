class Solution {
public:
    long long findtrip(vector<int> & time , long long x)
    {
        long long trips=0;
        for(int i=0;i<time.size();i++)
        {
            trips+=x/time[i];
        }
        return trips;

    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l=1;
        long long h=(*min_element(time.begin(), time.end())*1LL*totalTrips);


        while(l<=h)
        {
            long long mid=l+(h-l)/2;

            long long trips=findtrip(time,mid);
            if(trips>=totalTrips)
            {
                h=mid-1;
            }else{
                l=mid+1;
            }
        }

        return l;
    }
};