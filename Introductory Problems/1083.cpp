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

    vvl a(n-1) ;
    iarr(a) ;

    it (i, n)   a.pb(i+1) ;     // add all no from 1 to n

    ll missing = 0 ;

    // a^a = 0
    // 0^b = b (only non repeting number)

    for (auto &x: a) {
        missing ^= x ;
    }

    cout<<missing ;
    
}
