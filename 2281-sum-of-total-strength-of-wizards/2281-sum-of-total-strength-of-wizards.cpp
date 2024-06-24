class Solution {
public:
    long long int calc(int l,int r,int i,vector<long long int> &prefix,vector<long long int> &preprefix,vector<int> &strength)
    {   int mod=1e9+7;
       long long int a=(preprefix[r-1]+prefix[i]+mod)%mod;
       a=(a-preprefix[i]+mod)%mod;
       a=(a*(i-l)+mod)%mod;
       long long int b=(prefix[i]+strength[l+1]+mod)%mod;
       b=(b-prefix[l+1]+mod)%mod;
       b=(b*(r-i)+mod)%mod;
       long long int c=(preprefix[i]+prefix[l+1]+mod)%mod;
       c=(c-preprefix[l+1]+mod)%mod;
       c=((r-i)*c+mod)%mod;
       return (a+b-c+mod)%mod;
    
    }
    int totalStrength(vector<int>& strength) {
        //preparing nextsmaller and prevsmaller index vector
        int n=strength.size();
        vector<int> prevsmall(n);
        stack<int> s;
        s.push(-1);
        for(int i=0;i<n;i++)
        {
            int curr=strength[i];
            while(s.top()!=-1 && strength[s.top()]>=curr)
            {s.pop();}
            prevsmall[i]=s.top();
            s.push(i);
        }
        vector<int> nextsmall(n);
        stack<int> s2;s2.push(-1);
        for(int i=n-1;i>=0;i--)
        {
            int curr=strength[i];
            while(s2.top()!=-1 && strength[s2.top()]>curr)
            {s2.pop();}
            nextsmall[i]=s2.top();
            s2.push(i);
        }
        //we will be needing 2 prefix sum here 
        vector<long long int> prefix(n);
        vector<long long int> preprefix(n);
       long long  int sum=0;
        for(int i=0;i<n;i++)
        {   sum+=strength[i];
            prefix[i]=sum;
        } 
        sum=0;
        for(int i=0;i<n;i++)
        {
          sum+=prefix[i];
          preprefix[i]=sum;
        }
        long long int ans=0;long long su=0;
        int mod=1e9+7;
        for(int i=0;i<n;i++)
        {
            int l=prevsmall[i];
            //if(l==-1){l=0;}
            int r=nextsmall[i];
           if(r==-1){r=n;}
           
            su=(strength[i]*calc(l,r,i,prefix,preprefix,strength) +mod)%mod ;
             ans=(ans+su+mod)%mod;
        }
        return ans;

    }
};