#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;

    while(t--)
    {
        int count=0;
        int n;
        cin >> n;
        string s;
        cin >> s;
        char first = s[0];
        if(n>1)
        {
             for(int i=1;i<n;i++)
             {
                if(first=='0' && s[i]=='1')
                {
                    count++;
                    first=s[i];
                }
                if(first=='1' && s[i]=='0')
                {
                    count++;
                    first=s[i];
                }
             }
        }
        cout << count << endl;
        
    }
    return 0;
}
