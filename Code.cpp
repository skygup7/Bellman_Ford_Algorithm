#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define LLMAX 1000000000000000010
#define MAX 100005
#define gcd __gcd
#define INF 1000000007
#define pb(n) push_back(n)
#define fr front()
#define vint vector<int>
#define vstring vector<string>
#define vll vector<long long int>
#define pii pair<int,int>
#define forp(i,a,n) for(int i=(a);i<(n);i++)
#define forn(i,a,n) for(int i=(a);i>=(n);i--)
#define mp std::map<string, int>
#define csl ios_base::sync_with_stdio(false); cin.tie(NULL)


class graph
{
    int u;
    list<pii > * adj;
    int * dist;
public:
    graph(int v);
    void addedge(int src,int dest,int w);
    void BellmanFord(int src);
};

graph::graph(int v)
{
    u=v;
    adj=new list<pii >[v];
    dist=new int[v];
    for(int i=0;i<u;i++)
        dist[i]=INF;
}
void graph::addedge(int src,int dest,int w)
{
    adj[src].pb(make_pair(dest,w));
}
void graph::BellmanFord(int src)
{
    dist[src]=0;
    
}

int main()
{
    graph g(4);
    g.addedge(0,1,1);
    g.addedge(0,2,1);
    g.addedge(1,2,1);
    g.addedge(2,0,1);
    g.addedge(2,3,1);
    g.addedge(3,3,1);
}