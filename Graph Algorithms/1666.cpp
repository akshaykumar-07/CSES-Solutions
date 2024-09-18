#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define it(i,n) for (int i=0; i<n; i++)
#define its(i,j,n) for (ll i=j; i<n; i++)
#define iarr(a)	    for (auto &x: a) {cin>>x;}
#define oarr(a)	    for (auto &x: a) {cout<<x<<" ";} cout<<endl;
 
#define vvl      vector<ll> 
#define all(a)  a.begin(), a.end()
#define pb      push_back
 
#define pi      acos(-1)
#define root(n) pow(n,0.5)
 const ll M = 1e9+7 ;
 
/* ______________________________________________________________________________ */
 
void ak();
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
 
    int t = 1;
    // cin>>t;

 
    while(t--){
        ak();
        cout<<endl;
    } 
 
}
 
void dfs (int vertex, vvl &vis, vector<vvl> &g, vvl &tmp) {
    if (vis[vertex])    return ;
    tmp.pb(vertex) ;
    vis[vertex] = 1 ;
    for (auto &child: g[vertex]) {
        dfs(child, vis, g, tmp) ;
    }
}
 
 
void ak(){
    ll n;
    cin>>n ;
 
    ll m ;
    cin>>m ;
 
    vector<vvl> graph(n+1) ;
    vvl vis(n+1, 0), roads ;
 
    it (i, m) {
        ll a, b ;
        cin>>a>>b ;
        graph[a].pb(b) ;
        graph[b].pb(a) ;
    }
 
 
    ll ans = 0 ;
 
    its (i, 1, n+1) {
        if (vis[i])   continue ;
        vvl tmp ;
        dfs (i, vis, graph, tmp) ;
        roads.pb(tmp[0]) ;
        ans ++ ;
    }
    
    cout<<ans-1<<endl ;
 
    if (ans>1)   for (int i=0; i<roads.size()-1; i++)  {
        cout<<roads[i]<<" "<<roads[i+1]<<endl ;
    }
 
}
