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
    void print_graph();
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
void graph::print_graph()
{
    cout<<"Vertex   Distance from Source"<<endl;
    for(int i=0;i<u;i++)
        cout<<i<<" \t\t "<<dist[i]<<endl;
}
void graph::BellmanFord(int src)
{
    bool flag=false;
    int a,b,w;
    dist[src]=0;
    list<pii >::iterator it;
    forp(i,1,u)
    {
        for(int s=0;s<u;s++){
            for(it=adj[s].begin();it!=adj[s].end();it++)
            {
                a=s;
                b=(*it).first;
                w=(*it).second;
                if(dist[a]!=INF && dist[b]>(dist[a]+w))
                {
                    dist[b]=dist[a]+w;
                }
            }
        }
    }
    for(int s=0;s<u;s++){
        for(it=adj[s].begin();it!=adj[s].end();it++)
        {
            a=s;
            b=(*it).first;
            w=(*it).second;
            if(dist[a]!=INF && dist[b]>(dist[a]+w))
            {
                flag=true;
            }
        }
    }
    if(flag)
        cout<<"Minimum distance is not possible due to the existence of nagetive cycle in the given graph."<<endl;
    else
        print_graph();
}

int main()
{
    cout<<"Please insert the number of vertices and edges."<<endl;
    int v,e,src,dest,w;
    cin>>v>>e;
    graph g(v);
    cout<<"Please insert the source, destination of edge and its weight for given number of edges."<<endl;
    for(int i=0;i<e;i++)
    {
        cin>>src>>dest>>w;
        g.addedge(src-1,dest-1,w);
    }
    clock_t tStart = clock();
    g.BellmanFord(0);
    cout<<"Time taken: "<<(double)(clock() - tStart)/CLOCKS_PER_SEC<<endl;
    return 0;
}