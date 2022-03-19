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
ll col[N];
bool vis[N];
vl graph[N];
void dfs(ll root,ll p){
    if(vis[p])return;
    vis[p]=1;
    col[p]=-col[root];
    for(auto x:graph[p]){
        dfs(p,x);
    }
}
void solve(){
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++)vis[i]=0;
    rep(i,1,n){
        ll a,b;
        cin>>a>>b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    col[1]=1;
    dfs(1,1);
    ll ans=0;
    ll red=0,blue=0;
    for (ll i=1;i<=n;i++){
        if(col[i]==1)red++;
        else blue++;
    }
    for (ll i=1;i<=n;i++){
            if(col[i]==1)ans+=blue-graph[i].size();
    }
    cout<<ans<<endl;
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
       //}
    return 0;
}
