class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        //answer i guarantee
        //we will use the thing that is given that is ki the profit will never reduce!
        vector<pair<int,int>> vec(profits.size());
        for(int i=0;i<profits.size();i++)
        {
            vec[i]={capital[i],profits[i]};
        }
        sort(vec.begin(),vec.end());//sorted according to the capital needed !
        priority_queue<int> pq;//will contain the profit!
        int in=0;//index
        while(k>0)
        {
            //lets take the projects we can affort!
            while(in<profits.size() && w>=vec[in].first)
            {
              pq.push(vec[in].second);in++;
            }
            if(!pq.empty())
           { w+=pq.top();
            pq.pop();
            }k--;
        }
        return w;
        
    }
};