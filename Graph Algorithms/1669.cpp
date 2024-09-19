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

vvl vis(2e5+10) ;
bool found = 0 ;
vector<vvl> graph(2e5+10) ;

void print(ll node, vvl &path)  {
    found = 1 ;
    ll cnt = 1 ;
    vvl ans {node} ;
    ll i = path.size()-1 ;
    while (1) {
        ans.pb(path[i]) ;
        cnt ++ ;
        if (node == path[i])  break ;
        i -- ;
    }

    // for (auto &x: path) cout<<x<<" " ;
    // cout<<endl ;

    cout<<cnt<<endl ;
    for (auto &x: ans)  cout<<x<<" " ;
}

void dfs (ll node, ll par, vvl &path) {
    if (found)  return ;
    if (vis[node]) {
        if (path.size() > 2) {
            print(node, path) ;
            return ;
        }
    }

    vis[node] = 1 ;
    path.pb(node) ;

    for (auto &child: graph[node]) {
        if (par == child)   continue ;
        dfs(child, node, path) ;
    }
    path.pop_back() ;
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

    vvl path ;

    its (i, 1, n+1) {
        if (vis[i])    continue ;
        dfs(i, -1, path) ;
    }

    if (!found) {
        cout<<"IMPOSSIBLE" ;
    }
}
