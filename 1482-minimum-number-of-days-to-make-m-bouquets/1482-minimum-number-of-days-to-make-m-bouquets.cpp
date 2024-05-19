class Solution {
public:
    int f(vector<int> bloomDay,int days,int n,int k,int m)//gives bouquet made
    {   int b=0;
        int fl=0;
        for(int i=0;i<n;i++)
        {
            if(bloomDay[i]<=days){fl++;}
            else{b+=fl/k;
                 fl=0;}
        }
        b+=fl/k;
        return b;}
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        int maxi=INT_MIN;
        int mini=INT_MAX;
        if(k>bloomDay.size() && m>0){return -1;}
        for(int i=0;i<n;i++){maxi=max(maxi,bloomDay[i]);
                             mini=min(mini,bloomDay[i]);}
        if(f(bloomDay,maxi,n,k,m)<m){return -1;}                     
        while(mini<=maxi)
        {
            int mid=(mini+maxi)/2;//number of days taken
            int a=f(bloomDay,mid,n,k,m);//will give the bouquet made
            if(a<m)
            {
                mini=mid+1;
            }
            else
            {
                maxi=mid-1;
            }}
            return mini;}
};