// #define fast                          \
//     ios_base::sync_with_stdio(false); \
//     cin.tie(NULL);                    \
//     cout.tie(NULL);
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
int n;
VVI adj;
vector<int> a, s;
bool flag = false;
void DFS(int curr, int par, int level)
{   if(flag)
        return;
    if (level % 2 == 0) //even level node
    {
        int choice = INT64_MAX;
        for (auto x : adj[curr])
        {
            if (x == par)
                continue;
            choice = min(choice, s[x]);
        }
        if (choice == INT64_MAX)
        {
            a[curr] = 0;
            s[curr] = a[curr] + s[par];
        }
        else
        {
            s[curr] = choice;
            a[curr] = s[curr] - s[par];
            if (a[curr] < 0)
            {
                flag = true;
                return;
            }
        }
    }
    else //odd level node
    {
        if (par == -1)
        {
            a[curr] = s[curr];
        }
        else
        {
            a[curr] = s[curr] - s[par];
            if (a[curr < 0]) 
            {
                flag = true;
                return;
            }
        }
    }
    // cout<<"DFS "<<curr<<" "<<par<<" "<<level<<" "<<a[curr]<<endl;
    for(auto x:adj[curr])
    {   if(x==par)
              continue;
        DFS(x,curr,level+1);
    }
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
    cin >> n;
    adj.resize(n + 1);
    a.resize(n + 1);
    s.resize(n + 1);
    for (int i = 2; i <= n; i++)
    {
        int p;
        cin >> p;
        adj[i].push_back(p);
        adj[p].push_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    DFS(1, -1, 1); // DFS(node,its parent,its level or height)
    if(flag)
    {
        cout<<"-1";
    }
    else
    {    int sum=0;
        for(int i=1;i<=n;i++)
        {
            sum=sum+a[i];
        }
        cout<<sum;

    }

    return 0;
}