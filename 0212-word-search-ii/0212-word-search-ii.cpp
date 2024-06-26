class Trie{public: 
           bool isterminal;
           Trie* children[26];
           char data;
           Trie(char ch)
           {this->data=ch;
            this->isterminal=false;
            for(int i=0;i<26;i++){this->children[i]=NULL;}}
};
class Trienode{public:
               Trie* root;
               Trienode(){root=new Trie('\0');}
            void addstr(string str)
            {   Trie* r=root;
                int n=str.size();
                for(int i=0;i<n;i++)
                {
                  int numb=str[i]-'a';
                  if(r->children[numb]!=NULL)
                  {
                    r=r->children[numb];
                  }
                  else
                  {
                    Trie* child=new Trie(str[i]);
                    r->children[numb]=child;
                    r=child;
                  }}
                  r->isterminal=true;

                  }};
    void search(int r,int c,int n,int m,vector<vector<int>> &vis,vector<vector<char>> &board,map<string,       int> &present,Trie* d,int di[],int dj[],string str)
    {
        vis[r][c]=1;
        if(d->isterminal)
        {present[str]=1;}
        for(int i=0;i<=3;i++)
        {
            int nr=r+di[i];
            int nc=c+dj[i];
            if(nr>=0 && nc>=0 && nr<n && nc<m && !vis[nr][nc])
            {
                char ch=board[nr][nc];
                int numb=ch-'a';
                if(d->children[numb]!=NULL){search(nr,nc,n,m,vis,board,present,d->children[numb],di,dj,str+ch);vis[nr][nc]=0;}
            }
            
        }


    }
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trienode* obj=new Trienode(); 
        map<string,int> present; 
        vector<string> ans;
        for(int i=0;i<words.size();i++)
        {obj->addstr(words[i]);present[words[i]]=0;}
        int n=board.size();int m=board[0].size();
        int di[]={0,1,-1,0};
        int dj[]={1,0,0,-1};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {  if(obj->root->children[board[i][j]-'a'])
              { vector<vector<int>> vis(n,vector<int>(m,0));
               string str="";str+=board[i][j];Trie* d=obj->root->children[board[i][j]-'a'];
               search(i,j,n,m,vis,board,present,d,di,dj,str);
            }}
        }
        for(int i=0;i<words.size();i++)
        {
            if(present[words[i]]==1){ans.push_back(words[i]);}
        }
        return ans;
        


        
    }
};