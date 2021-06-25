#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MP make pair
#define PB push back
#define MOD 1000000007
#define fi first #define se second
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef vector<VI> VVI;
typedef map<int, int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSET;
vector<int> v;
int Find(int l,int r,int key)
{
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        cout<<l<<" "<<r<<" "<<mid<<endl;
        if(v[mid]==key)
           return mid;
        if(key<v[mid])
        {
            return Find(l,mid-1,key);

        }
        else
        {
            return Find(mid+1,r,key);
        }
    }
    return -1; //if we didn't find out key in entire array

}
int32_t main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
int n,key;
cin>>n>>key;
for(int i=0;i<n;i++)
{
    int x;
    cin>>x;
    v.push_back(x);
}
cout<<Find(0,n-1,key)<<endl;


return 0;
}