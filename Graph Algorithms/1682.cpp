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

void dfs (int u, vector<int> g[], vector<bool> &vis) {
    vis[u] = 1;
    for (auto &v: g[u]) {
        if (!vis[v]) {
            dfs(v, g, vis);
        }
    }

}

void ak(){
    int n;
    cin>>n ;

    int m;
    cin>>m;

    vector<int> g[n+5], g2[n+5];
    vector<bool> vis(n+5, 0) ;

    it (i, m) {
        int x,y ;
        cin>>x>>y;
        x--;
        y--;

        g[x].pb(y);
        g2[y].pb(x); // reverse graph
    }

    dfs(0, g, vis) ;
    it (i, n) {
        if (!vis[i]) {
            cout<<"NO\n";
            cout<<1<<" "<<i+1<<endl;
            return ;
        }
    }

    it (i, n+5) vis[i]=0;

    dfs(0, g2, vis) ;
    it (i, n) {
        if (!vis[i]) {
            cout<<"NO\n";
            cout<<i+1<<" "<<1<<endl;
            return ;
        }
    }

    cout<<"YES\n";

}
