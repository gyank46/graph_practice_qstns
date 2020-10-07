#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <queue>
#include <stack>

using namespace std;
struct list
{
    int val;
    list *next;
    list(int x) : val(x), next(NULL) {}
};

void ins(vector<pair<int,int>> &dist,int key,int dist,unordered_map<int,int> &m)
{
    int n=dist.size();
    if(n==0)
    {
        dist.push_back(make_pair(key,dist));
        m[key]=0;
    }
    else
    {
        int par_index=(n-1)/2;
        int cur_index=n;
        dist.push_back(make_pair(key,val));
        while(dist[par_index].second>dist[cur_index].second)
        {
            pair<int,int> temp=dist[par_index];
            dist[par_index]=dist[cur_index];
            m[dist[cur_index].first]=par_index;
            m[temp.first]=cur_index;
            dist[cur_index]=temp;
        }
    }
}
pair<int,int> getmin(vector<pair<int,int>> dist)
{
    return dist[0];
}
void extractmini(vector<pair<int,int>> &dist,unordered_map<int,int> &m)
{
    int n=dist.size();
    dist[0]=dist[n-1];
    dist.erase(dist.begin()+n-1);
    heapify(dist,0,m);
}
void heapify_down(vector<pair<int,int>> &dist,int i,unordered_map<int,int> &m)
{
    int n=dist.size();
    int lchi_index=2*i+1,rchi_index=2*i+2;
    int smallest=i;
    if(lchi_index<n&&dist[lchi_index].second<dist[smallest].second)
        smallest=lchi_index;
    if(rchi_index<n&&dist[rchi_index].second<dist[smallest].second)
        smallest=rchi_index;
    if(smallest!=i)
    {
        pair<int,int> temp=dist[i];
        dist[i]=dist[smallest];
        dist[smallest]=temp;
        m[dist[i].first]=smallest;
        m[dist[smallest].first]=i;
        heapify_down(dist,smallest,m);
    }
}


int main()
{
    int v;
    cin>>v;
    int e;
    cin>>e;
    vector<list*> adj_list(v+1);
    for(int i=0;i<=v;i++)
        adj_list[i]=NULL;
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        list *ul=new list(u);
        list *vl=new list(v);
        vl->next=adj_list[u];
        adj_list[u]=vl;
    }
    for(int i=1;i<=v;i++)
    {
        cout<<i<<"->";
        list *temp=adj_list[i];
        while(temp!=NULL)
        {
            cout<<temp->val<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
    unordered_map<int,int> m;
    vector<pair<int,int>> dist;
    for(int i=1;i<=v;i++)
        ins(dist,i,INT_MAX,m);



}
