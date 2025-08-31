#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define it(i,n) for (int i=0; i<n; i++)
#define its(i,j,n) for (ll i=j; i<n; i++)
#define iarr(a)	    for (auto &x: a) {cin>>x;}
#define oarr(a)	    for (auto &x: a) {cout<<x<<" ";} cout<<endl;
#define o2Darr(a, n, m)	it (i, n){it(j, m){cout<<a[i][j]<<" ";}cout<<endl; }
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

void ak(){
    cin>>n ;

    cin>>m;

    vector<vector<ll>> ed;
    vector<vector<int>> radj(n);

    it (i, m) {
        ll u, v, w;
        cin>>u>>v>>w;
        u--;
        v--;

        ed.pb({u,v,w});
        radj[v].push_back(u);
    }

    vector<ll> dist(n, -1e18);
    dist[0] = 0;

  // Bellman Ford Algo with variation
    it (i, n-1) {
        for (auto &x: ed) {
            ll u, v, w;
            u = x[0];
            v = x[1];
            w = x[2];

            if (dist[u] != -1e18 && dist[v] < dist[u] + w) {
                dist[v] = dist[u] + w ;
            }
        }
    }

    vector<bool> aff(n, 0);

    for (auto &x: ed) {
        ll u, v, w;
        u = x[0];
        v = x[1];
        w = x[2];

        if (dist[u] != -1e18 && dist[v] < dist[u] + w) {
            aff[v] = 1;
        }
    }

    vector<ll> canReachN(n, 0);
    queue<ll> q;
    q.push(n-1);
    canReachN[n-1] = 1;

    while (!q.empty()) {
        ll u = q.front(); 
        q.pop();
        for (auto& p : radj[u]) {
            if (!canReachN[p]) {
                canReachN[p] = 1;
                q.push(p);
            }
        }
    }

    it (i, n) {
        if (aff[i] && canReachN[i]) {
            cout<<-1;
            return;
        }
    }

    cout<<dist[n-1];
    
}
