#include<bits/stdc++.h>
using namespace std;

class cmp
{
    public:
      bool operator()(int a,int b)
    {
          return a>b
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t,q,x;
    cin >> t;
    priority_queue<int ,vector<int>,cmp> pq;
    while(t--)
    {
        cin >> q;
        if(q==1)
        {
           cin >> x; 
           pq.push(x);
        }
        if(q==2)
        {
            if(pq.empty())
            {
               cout <<"empty\n";
            }
            else
            {
                int same =pq.top();
               cout <<pq.top()<<"\n";
               pq.pop();
               while(same==pq.top()) 
               {
                pq.pop();
                same=pq.top();
               }

            }
        }
    }

    return 0;
}