#include <bits/stdc++.h>

using namespace std;

int getnext(int i)
{
    return (i+(i&-i));
}
int getparent(int i)
{
    return(i-(i&-i));
}

void update(vector <int> &bit,int i,int val)
{
    int n=bit.size();
    int j=getnext(i);
    // cout<<i<<" ";
    while(j<=n)
    {
        // cout<<j<<" ";
        bit[j]+=val;
        j=getnext(j);
    }
    // cout<<endl;
}

int getsum(vector<int> bit,int i)
{
    int ans=0;
    while(i>0)
    {
        // cout<<i<<" "<<bit[i]<<" "<<ans<<endl;
        ans+=bit[i];
        i=getparent(i);
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    vector<int> bit(n+1);
    for(int i=1;i<=n;i++)
    {
        bit[i]+=a[i-1];
        update(bit,i,a[i-1]);
    }
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    for(int i=1;i<=n;i++)
        cout<<bit[i]<<" ";
    cout<<endl;
    int q;
    cin>>q;
    while(q--)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            int in,val;
            cin>>in>>val;
            bit[in+1]+=val-a[in];
            update(bit,in+1,val-a[in]);
        }
        if(t==2)
        {
            int l,r;
            cin>>l>>r;
            cout<<getsum(bit,r+1)-getsum(bit,l)<<endl;
        }
    }
}
