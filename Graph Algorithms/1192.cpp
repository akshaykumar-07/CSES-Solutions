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
 
 
    // check_prime() ;
    // find_divisors() ;
    // find_fact() ;
 
    while(t--){
        ak();
        cout<<endl;
    } 
 
}
 
void dfs (int i, int j, vector<vvl> &g) {
    if (i<0 || j<0) return ;
    if (i>=g.size() || j>=g[0].size()) return ;
    if (g[i][j] == 1)   return ;
 
    g[i][j] = 1 ;
 
    dfs (i+1, j, g) ;
    dfs (i-1, j, g) ;
    dfs (i, j+1, g) ;
    dfs (i, j-1, g) ;
}
 
 
void ak(){
    ll n;
    cin>>n ;
 
    ll m ;
    cin>>m ;
 
    vector<vvl> graph(n, vvl(m, 0)) ;
 
    it (i, n) {
        string s ;
        cin>>s ;
        it (j, m)   {
            if (s[j] == '.')    graph[i][j] = 0 ; 
            if (s[j] == '#')    graph[i][j] = 1 ;
        }
    }
 
    ll ans = 0 ;
    it (i, n) {
        it (j, m) {
            if (graph[i][j] == 1)   continue ;
            dfs(i, j, graph) ;
            ans ++ ;
        }
    }
 
    cout<<ans ;
 
}
