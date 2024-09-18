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
 
void ak(){
    ll n;
    cin>>n ;
 
    ll m ;
    cin>>m ;
 
    vector<vvl> graph(n+1) ;
    vvl vis(n+1, 0), par(n+1, 0), level(n+1, 0) ;
 
    it (i, m) {
        ll a, b ;
        cin>>a>>b ;
        graph[a].pb(b) ;
        graph[b].pb(a) ;
    }
 
    queue<ll> q ;
    q.push(1) ;
    vis[1] = 1 ;
 
    while (!q.empty()) {
        ll curr = q.front() ;
        q.pop() ;
        for (ll child: graph[curr]) {
            if (vis[child]) continue ;
            q.push(child) ;
            vis[child] = 1 ;
            par[child] = curr ;
            level[child] = level[curr] + 1 ;
        }
    }
 
    if (level[n] == 0) {
        cout<<"IMPOSSIBLE" ;
        return ;
    }
 
    ll node = n ;
    cout<<level[n] + 1<<endl ;
    vvl ans ;
    ans.pb(node) ;
    while (node != 1) {
        node = par[node] ;
        ans.pb(node) ;
    }
 
    reverse(all(ans)) ;
    oarr(ans) ;
 
}
