#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#include<bits/stdc++.h>
using namespace std;
bool mycomp(string s1,string s2)
{
   return s1.length()<s2.length();
}
int main()
{
    fast 
    #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
    #endif
    vector<int> v{2,3,1,7,9,67};
    sort(v.begin(),v.end());
    // if(binary_search(v.begin(),v.end(),9))
    // {
    //     cout<<"9 present";
    // }
    // else
    // cout<<"9 absent";
   auto it=find(v.begin(),v.end(),9);
    if(it!=v.end())
   {
        cout<<"9 present";
    }
    else
    cout<<"9 absent";

    cout<<endl<<" position is "<<it-v.begin();

   

    
}