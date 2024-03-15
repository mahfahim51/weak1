#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
long long ar[N][N];
bool vis[N][N];
int level[N][N];
vector<pair<int,int>> d={{-1,-1},{-1,1},{1,-1},{1,1}};
map<pair<int,int>,pair<int,int>> mp;
int row ,col;
int si,sj,di,dj;
bool flag;
long long sum;
bool valid(int i,int j)
{
    if(i<0 || i>=row || j<0 || j>=col || ar[i][j]==0) return false;
    else return true;
}
class cmp
{
    public:
      bool operator()(pair<int, int> a, pair<int, int> b)
    {
         int i=a.first;
         int j=a.second;
         int k=b.first;
         int l=b.first;
         if(level[i][j] == level[k][l])  return ar[i][j] > ar[k][l];
         else
         {
            return level[i][j] > level[k][l];
         }
    }
};

void bfs(int si,int sj)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
   // queue<pair<int,int>> q;
    q.push({si,sj});
    vis[si][sj]=true;
    level[si][sj]=0;
    while(!q.empty())
    {
        pair<int,int> p=q.top();
        int pi=p.first;
        int pj=p.second;
        q.pop();
        for(int i=0;i<4;i++)
        {
           int ci=pi + d[i].first;
           int cj=pj + d[i].second;
          if(ci==di && cj==dj) flag=true;
            if(valid(ci,cj) && !vis[ci][cj] )
           {
                vis[ci][cj]=true;
                level[ci][cj]=level[pi][pj]+1;
                mp[{ci,cj}]={pi,pj};
                q.push({ci,cj});        
           }
        }
        
    }
}
int main()
{
    int t;
    cin >> t;
    for(int z=1;z<=t;z++)
    {
            flag=false;
            sum=0;
            cin >> row >> col;
            memset(vis,false,sizeof(vis));
            memset(level,-1,sizeof(level));
            
            for(int i=0;i<row;i++)
            {
                for(int j=0;j<col;j++)
                {
                cin >> ar[i][j];

                    if(ar[i][j]==-1)
                    {
                    si=i;
                    sj=j;
                    } 
                    if(ar[i][j]==-2)
                    {
                    di=i;
                    dj=j;
                    }    
                }
            }
            
            bfs(si,sj);
        if(flag)
        {
                int  u = mp[{di,dj}].first;
                int  v = mp[{di,dj}].second;
                while(u != si || v != sj)
                {
                 sum+=ar[u][v];
                int  tempU = mp[{u,v}].first;
                int tempV = mp[{u,v}].second;
                u=tempU;
                v=tempV;
                }
             cout<<"Case "<<z<<": "<<sum<<"\n";
                
        } 
        else
        {
            cout <<"Case "<<z<<": Impossible"<<"\n";
        }
        
            
    } 

    
}