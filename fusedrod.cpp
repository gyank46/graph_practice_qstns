#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int> > &a,int i,vector<bool> &visited,int &ans,int n)
{
    if(!visited[i])
    {
        // cout<<i<<" ";
        ans+=1;
        for(int j=i+1;j<=n;j++)
        {
            if(a[i][j]==1&&!visited[j])
                dfs(a,j,visited,ans,n);
        }
    }
    visited[i]=1;
}

int main()
{
    int n;
    cin>>n;
    int np;
    cin>>np;
    vector<vector<int> > a(n+1,vector<int>(n+1));
    for(int i=0;i<np;i++)
    {
        int t1,t2;
        cin>>t1>>t2;
        a[t1][t2]=1;
        a[t2][t1]=1;
    }
    vector<bool> visited(n);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int temp=0;
        if(!visited[i])
        {
            dfs(a,i,visited,temp,n);
            ans+=ceil(sqrt(temp));
            // cout<<endl;
            // cout<<ans<<endl;
        }
    }
    cout<<ans<<endl;

}
