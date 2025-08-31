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

int n, m;

vector<long long> dijkstra (int u, vector<pair<ll, ll>> g[]) {
    vector<long long> dist(n);
    it (i, n)   dist[i] = 1e18;
    dist[u] = 0;

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

    pq.push({0, u});

    while (!pq.empty()) {
        ll d = pq.top().first;
        ll node = pq.top().second;
        pq.pop();

        if (d > dist[node]) continue; // do not proceed if distance is more than pre stored distance

        for (auto &it: g[node]) {
            ll w = it.second;
            ll adjNode = it.first;

            if (dist[adjNode] > d*1LL + w) {
                dist[adjNode] = 0LL+d+w ;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    return dist ;

}



void ak(){
    cin>>n ;

    cin>>m;

    vector<pair<ll, ll>> g[n];

    it (i, m) {
        ll u, v, d;
        cin>>u>>v>>d;
        u--;
        v--;

        g[u].pb({v, d});
        // g[v].pb({u, d});
    }

    vector<ll> ans = dijkstra(0, g);

    it (i, n)   cout<<ans[i]<<" ";

}
