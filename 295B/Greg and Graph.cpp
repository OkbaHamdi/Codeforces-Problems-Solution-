   /************      Author :

                L_7

            OKBA HAMDI

                           **************/
#include<bits/stdc++.h>
using namespace std;

    /***************Typedef *************/

typedef         long long ll;
typedef         long double ld;
typedef         vector<ll>vl;
typedef         deque<ll>dq;
typedef         pair<ll,ll>pi;
typedef         priority_queue<ll>pq;
typedef         priority_queue<ll,vector<ll>,greater<ll>>pqg;


    /********** Constantes **************/

const           ll MOD = 1000000007;
const           ll eps=1e-9;
const           double PI=acos(-1);
const           ll N=1e5+5;
const           ll INF=1e18;
            /************  Define  ****************/

#define         F first
#define         S second
#define         pb push_back
#define         ppb pop_back
#define         pf push_front
#define         ppf pop_front
#define         sz(x)  (ll)((x).size())
#define         rep(i,a,b) for(ll i=a;i<b;i++)
#define         L_Headshot_7 ios_base::sync_with_stdio(false);cin.tie(0);
#define         aff(v) for(auto e:v) cout<<e<<" ";cout<<endl;
#define         all(v) v.begin(), v.end()
#define         rall(v) v.rbegin(), v.rend()
#define         READ freopen("input.txt", "r",stdin)
#define         WRITE freopen("output.txt", "w",stdout)

            /***************** Useful Functions *********************/

ll fact(ll x){return(x<2?1:x*fact(x-1));}
ll binexp(ll a,ll k){ll ans=1;while(k){if(k&1)ans=(ans*a)%MOD;a=(a*a)%MOD;k>>=1;}return ans;}
ll gcd(ll a, ll b){while (b) swap(b, a %= b);return a;}inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }ll ext(ll a, ll b, ll& x, ll& y){x = 1, y = 0;ll x1 = 0, y1 = 1, a1 = a, b1 = b;while (b1){ll q = a1 / b1;tie(x, x1) = make_pair(x1, x - q * x1);tie(y, y1) = make_pair(y1, y - q * y1);tie(a1, b1) = make_pair(b1, a1 - q * b1);}return a1;}

                /******************Code*********************/
ll graph[505][505];
vl v,ans;
void Warshall(ll n){
    for (ll k = n-1; k > -1; k--) {
        // let's update the new graph
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                if(graph[v[i]-1][v[j]-1]>graph[v[i]-1][v[k]-1]+graph[v[k]-1][v[j]-1])
                    graph[v[i]-1][v[j]-1]=graph[v[i]-1][v[k]-1]+graph[v[k]-1][v[j]-1];
            }
        }
        // done
        // now sum
        ll s=0;
        for (ll i=n-1;i>=k;i--){
            for(ll j=n-1;j>=k;j--){
                    s+=graph[v[i]-1][v[j]-1];
            }
        }
        ans.pb(s);
    }
}
void solve()
{
    ll n;
    cin>>n;
    for (ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            ll a;
            cin>>a;
            graph[i][j]=a;
        }
    }
    rep(i,0,n){
        ll a;
        cin>>a;
        v.pb(a);
    }
    Warshall(n);
    for(ll i=n-1;i>=0;i--)cout<<ans[i]<<" ";


}
int main()
{
    L_Headshot_7;
    //READ;
    //WRITE;
    //ll test;
    //cin>>test;
    //while(test--){
        solve();
      // }
    return 0;
}
