#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;

    unordered_map<char,int>mp;
    for(int i=0;i<s.length();i++)
    {
        if(mp.find(s[i]) == mp.end())
        {
            mp.insert(make_pair(s[i],1));
        }
        else
        {
             mp[s[i]]++;
        }
        
    }

    for(auto it:mp)
    {
        if(it.second>1)
        {
            cout<<it.first<<endl;
        }
    }
    return 0;
}