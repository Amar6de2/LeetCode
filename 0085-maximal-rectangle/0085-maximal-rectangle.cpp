/*
This is a code to find the largest rectangle containing only 1's in a binary matrix.
The logic used here is that I have seen each row as a histogram of unit breadth and for length,
I have added the successive column's 1s and if any succesive column has 0 make that length 0.
Data Structure used here is stacks to find the next and previous smaller elements in least time complexity.
*/
class Solution {
public:
  vector<int> ps(vector<int> row,int n)
  { vector<int> ans1(n);
    stack<int> s;s.push(-1);
    for(int h=0;h<n;h++)
    { int curr=row[h];
    while(s.top()!=-1 && row[s.top()]>=curr)
    {s.pop();}
    ans1[h]=s.top();
    s.push(h);
    }
    return ans1;
}

  vector<int> ns(vector<int> row,int n)
  {
    vector<int> ans2(n);
    stack<int> s;s.push(-1);
    for(int g=(n-1);g>=0;g--)
    {   int curr=row[g];
        while(s.top()!=-1 && row[s.top()]>=curr){s.pop();}
        ans2[g]=s.top();
        s.push(g);
    }
    return ans2;
}
   int maxareaa(vector<int> row,int size)
   {
    int a;int m=0;
    vector<int> prevsmall(size);
    //find previous small ones
    prevsmall=ps(row,size);
    //find the next small ones
    vector<int> nextsmall(size);
    nextsmall=ns(row,size);
    for(int k=0;k<size;k++)
    {
        int l=row[k];
        if(nextsmall[k]==-1){nextsmall[k]=size;}
        int b=nextsmall[k]-prevsmall[k]-1;
        a=l*b;
        m=max(m,a);
    }
    return m;
   }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int size=matrix[0].size();//column size
        int sizerow=matrix.size();//row size
        vector<int> rowadd(size,0);int area;int maxarea=0;
        for(int i=0;i<sizerow;i++)
        { for(int j=0;j<size;j++)
          {int ele=matrix[i][j]-48;//convert character to number
              if(ele==0){rowadd[j]=0;continue;}  
              rowadd[j]=rowadd[j]+ele;}
              area=maxareaa(rowadd,size);
              maxarea=max(maxarea,area);

        }
        return maxarea;
    }
};