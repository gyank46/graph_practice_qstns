#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>

using namespace std;

int main()
{
    int v;
    cin>>v;
    vector<vector<int> > adj_mat(v+1,vector<int>(v+1));
    int e;
    cin>>e;
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        adj_mat[u][v]=1;
        adj_mat[v][u]=1; //for directed comment this one
    }
    for(int i=0;i<=v;i++)
    {
        if(i==0)
        {
            cout<<"  ";
            for(int j=0;j<=v;j++)
                cout<<j<<" ";
            cout<<endl;
        }
        cout<<i<<" ";
        for(int j=0;j<=v;j++)
            cout<<adj_mat[i][j]<<" ";
        cout<<endl;
    }
}
