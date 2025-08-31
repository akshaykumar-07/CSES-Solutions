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

    int q;
    cin>>q;

    vector<vector<ll>> mat(n, vector<ll> (n, 1e18));

    it (i, m) {
        ll u,v,d;
        cin>>u>>v>>d;
        u--;
        v--;

        mat[u][v] = min(mat[u][v], d);
        mat[v][u] = min(mat[v][u], d);
    }

    it (i, n) it (j, n) if (i==j)   mat[i][j] = 0;

    // Floyd Warshall Algo
    it (k, n) {
        it (i, n) {
            it (j, n) {
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
            }
        }
    }

    it (i, n) {
        it (j, n) {
            if (mat[i][j] >= 1e18)  mat[i][j] = -1;
        }
    }

    it (i, q) {
        int a,b;
        cin>>a>>b;
        cout<<mat[--a][--b]<<endl;
    }

}
