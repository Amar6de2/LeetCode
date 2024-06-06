#define ll  long long 
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        //we make 2 min heap 
        priority_queue<pair<ll ,int>,vector<pair<ll ,int>>,greater<pair<ll ,int>>> meetoccuring;//first int contains the end time of meet and second contains the room number
        priority_queue<int,vector<int>,greater<int>> roomavailable;//will contain the room number
        for(int i=0;i<n;i++){roomavailable.push(i);}
        sort(meetings.begin(),meetings.end());
        vector<int> count(n,0);int mini=-1e9;
        //hence meetings are sorted on basis of start time 
        for(int i=0;i<meetings.size();i++)
        {
            while(!meetoccuring.empty() && meetoccuring.top().first<=meetings[i][0])
            {
            int meet=meetoccuring.top().second;
            meetoccuring.pop();
            roomavailable.push(meet);
            }
            if(!roomavailable.empty())//room available hai
            {
              int avai=roomavailable.top();
              roomavailable.pop();
              meetoccuring.push({meetings[i][1],avai});
              count[avai]++;
            }
            else
            {
              int delayavai=meetoccuring.top().second;
              ll endofprevmeet=meetoccuring.top().first;
             ll meettime=meetings[i][1]-meetings[i][0];
             ll delayend=endofprevmeet+meettime;
              meetoccuring.pop();
              meetoccuring.push({delayend,delayavai});
              count[delayavai]++;
            }} 
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(mini<count[i])
            { mini=count[i];
            ans=i;
            }
        }
        return ans;
    }
};