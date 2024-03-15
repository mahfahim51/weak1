#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    long long a;
    long long sum=0;
    priority_queue<long long,vector<long long>,greater<long long>> pq;
    for(int i=1;i<=n;i++)
    {
       cin >> a;
       pq.push(a);
    }
    
    sum+=pq.top();
    pq.pop();
    sum+=pq.top();
    cout << sum << endl;
    return 0;
}