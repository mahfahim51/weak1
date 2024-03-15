#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    set<long long> s;
    int q;
    long long x;
    while(t--)
    {
        cin >> q;
        if(q==1)
        {
             cin >> x;
             s.insert(x);
        }
        if(q==2)
        {
            if(s.empty()) 
            {
                cout <<"empty\n";
            }
            else
            {
               cout <<*(s.begin())<<"\n";
               s.erase(s.begin());
            }
        }
    }
    
    return 0;
}