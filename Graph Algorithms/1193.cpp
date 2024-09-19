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

vvl dx {1, 0, -1, 0} ;
vvl dy {0, 1, 0, -1} ;
vector<char> dir{'D', 'R', 'U', 'L'} ;


void ak(){
    ll n;
    cin>>n ;
    ll m ;
    cin>>m ;
    
    vector<string> grid(n) ;
    it(i, n)    cin>>grid[i] ;

    pair<ll, ll> ini, end ;

    it (i, n) {
        it (j, m) {
            if (grid[i][j] == 'A')  ini = {i, j} ;
            if (grid[i][j] == 'B')  end = {i, j} ;

        }
    }


    vector<vector<pair<ll, ll>>> prev (n, vector<pair<ll,ll>> (m, {-1, -1})) ;
    vector<vvl> vis(n, vvl(m, 0)) ;
    vis[ini.first][ini.second] = 1 ;


    queue<pair<ll, ll>> q ;
    q.push(ini) ;

    while (!q.empty()) {
        ll x = q.front().first ;
        ll y = q.front().second ;
        q.pop() ;
        it (i, 4) {
            ll x2 = x + dx[i] ;
            ll y2 = y + dy[i] ;
            if (x2<0 || y2<0 || x2>=n || y2>=m) continue ;

            if (!vis[x2][y2] && grid[x2][y2]!='#') {
                prev[x2][y2] = {x, y} ;
                vis[x2][y2] = 1 ;
                q.push({x2, y2}) ;
            }
        }
    }

    if (!vis[end.first][end.second]) {
        cout<<"NO" ;
        return ;
    }

    vector<pair<ll, ll>> path ;

    auto curr = end ;
    while (1) {
        path.pb(curr) ;
        curr = prev[curr.first][curr.second] ;
        if (curr == ini)    break ;
    }

    path.pb(ini) ;
    reverse(all(path)) ;
    
    cout<<"YES"<<"\n"<<path.size()-1 <<endl;

    string ans = "" ;
    it (j, path.size()-1) {
        it (i, 4) {
            if ((path[j+1].first == path[j].first + dx[i]) && (path[j+1].second == path[j].second + dy[i])) {
                ans += dir[i] ;

            }
        }
    }

    cout<<ans ;
    
}
