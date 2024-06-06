class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double,int>> data;//will store ratio of wage/quality and quality
        for(int i=0;i<wage.size();i++)
        {
            double d=quality[i];
            double n=wage[i];
            double r=n/d;
            data.push_back({r,quality[i]});
        }
        sort(data.begin(),data.end());
        priority_queue<int> pq;//will store the quality
        int qsum=0;
        double mrofkminus1=data[k-1].first;
        for(int i=0;i<k;i++)
        {
           qsum+=data[i].second;
           pq.push(data[i].second);
        }
        double ans=qsum*mrofkminus1;
        for(int i=k;i<wage.size();i++)
        {
            double mr=data[i].first;
            qsum=qsum-pq.top()+data[i].second;
            pq.pop();pq.push(data[i].second);
            ans=min(ans,qsum*mr);
        }
        return ans;
       
        
        
    }
};