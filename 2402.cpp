class Solution {
public:
    int   mostBooked(int   n, vector<vector<int >>& meetings) {

        // if(meetings.size()<=n)
        //     return 0;

        sort(meetings.begin(), meetings.end());
        vector<long long > count(n,0);
        priority_queue<long long , vector<long long > , greater<long long > >room;//empty rooms 
        priority_queue<pair<long long ,long long >, vector<pair<long long , long long >>, greater<pair<long long ,long long >> > end; //endtime,roomnumber
        
        for (long long i=0 ;i<n;i++)
            room.push(i);

        long long size = meetings.size();

        for (long long i =0 ;i<size;i++)
        {
            long long curStart = meetings[i][0];
            while(!end.empty())
            {
                if(end.top().first>curStart)
                    break;
                room.push(end.top().second);
                end.pop();

            }

            if(!room.empty())
            {   
                long long roomNumber = room.top();
                cout<<roomNumber<<" ";
                room.pop();
                count[roomNumber]++;
                end.push({meetings[i][1], roomNumber});

            }
            else //no room will be empty till start time of the current meeting at index i , so delay 
            {
                long long firstEndTime = end.top().first;
                cout<<"first end time : "<< firstEndTime <<" ";
                long long roomNumber = end.top().second;
                long long delay = firstEndTime - curStart;
                end.pop();
                count[roomNumber]++;
                end.push({meetings[i][1]+delay, roomNumber});

            }


        }

        long long maxIndex =0 ;
        long long maxVal =  INT64_MIN;
        cout<<endl;
        for(auto i :count )cout<<i<<" ";
        for (long long i =0 ;i<n;i++)
        {
            if(count[i]>maxVal)
            {
                maxVal = count[i];
                maxIndex = i;
            }
        }
        return maxIndex;

    }
};