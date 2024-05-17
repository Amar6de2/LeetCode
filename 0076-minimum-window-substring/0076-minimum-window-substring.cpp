class Solution {
public:
    string minWindow(string s, string t) {
        int l=0;
        int r=0;
        map<char,int> m;
        int count=0;
        int sind=-1;
        int minlen=INT_MAX;
        for(int i=0;i<t.size();i++){m[t[i]]++;}
        while(r<s.size())
        {
          m[s[r]]--;
          if(m[s[r]]>=0){count++;}
          while(count==t.size())
          {
           if(minlen>r-l+1){minlen=r-l+1;sind=l;}//update the minlen and starting index only when we get a bettwe length or lesser length
            m[s[l]]++;
            if(m[s[l]]>0){count--;}//agar mein yaha equality daaloonga toh: see we do not care for the elements which are not present at t so they will either be negative or 0...toh agar vo 0 honge toh humara count++ hoga which we do not want!
            l++;}
          r++;}
          if(sind==-1){return "";}
          return s.substr(sind,minlen);
        
    }
};