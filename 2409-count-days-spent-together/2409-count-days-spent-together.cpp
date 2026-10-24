class Solution {
public:
    int finddayofyear(string date,vector<int> &arr){
        int month=stoi(date.substr(0,2));
        int day=stoi(date.substr(3));

        return arr[month-1]+day;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> vec={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        vector<int> arr(13,0);

        arr[1]=31;
        for(int i=2;i<=12;i++)
        {
            arr[i]=arr[i-1]+vec[i-1];
        }


        int arriveAliceDay=finddayofyear(arriveAlice,arr);
        int leaveAliceDay=finddayofyear(leaveAlice,arr);
        int arriveBobDay=finddayofyear(arriveBob,arr);
        int leaveBobDay=finddayofyear(leaveBob,arr);

        int days=min(leaveAliceDay,leaveBobDay)-max(arriveAliceDay,arriveBobDay)+1;
        return days<0?0:days;
    }
};