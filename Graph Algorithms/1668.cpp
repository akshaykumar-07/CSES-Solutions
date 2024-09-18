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

// vvl level(2e5+10) ;
vvl vis(2e5+10), grp(2e5+10) ;
 
vector<vvl> graph(2e5+10) ;
queue<ll> q ;
 
ll bfs (ll source) {
    q.push(source) ;
    vis[source] = 1 ;
    grp[source] = 1 ;
 
    while (!q.empty()) {
        ll curr = q.front() ;
        q.pop() ;
        for (ll child: graph[curr]) {
            if (grp[child] == grp[curr]) return 0 ;
            if (vis[child]) continue ;
            q.push(child) ;
            vis[child] = 1 ;            
            // level[child] = level[curr] + 1 ;

            if (grp[curr] == 1) grp[child] = 2 ;
            else                grp[child] = 1 ;
            
        }
    }
    return 1 ;
}
 
 
 
 
void ak(){
    ll n;
    cin>>n ;
    ll m ;
    cin>>m ;
 
    it (i, m) {
        ll a, b ;
        cin>>a>>b ;
        graph[a].pb(b) ;
        graph[b].pb(a) ;
    }
 
    its (i, 1, n+1) {
        if (vis[i])    continue ;
        if (!bfs(i))    {
            cout<<"IMPOSSIBLE" ;
            return ;
        }
    }
 
    its (i, 1, n+1) cout<<grp[i]<<" " ;
 
}
