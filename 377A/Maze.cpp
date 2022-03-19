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
#define         aff(v) for(auto e:v) cout<<e<<endl;cout<<endl;
#define         all(v) v.begin(), v.end()
#define         rall(v) v.rbegin(), v.rend()
#define         READ freopen("d_difficult.in.txt", "r",stdin)
#define         WRITE freopen("outputd.txt", "w",stdout)

            /***************** Useful Functions *********************/

ll division(ll a, ll b) {return a % b == 0 ? a / b : a / b +1;}
ll fact(ll x){return(x<2?1:x*fact(x-1));}
ll binexp(ll a,ll k){ll ans=1;while(k){if(k&1)ans=(ans*a)%MOD;a=(a*a)%MOD;k>>=1;}return ans;}
ll gcd(ll a, ll b){while (b) swap(b, a %= b);return a;}inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }ll ext(ll a, ll b, ll& x, ll& y){x = 1, y = 0;ll x1 = 0, y1 = 1, a1 = a, b1 = b;while (b1){ll q = a1 / b1;tie(x, x1) = make_pair(x1, x - q * x1);tie(y, y1) = make_pair(y1, y - q * y1);tie(a1, b1) = make_pair(b1, a1 - q * b1);}return a1;}
string yup(ll a,ll b){if(a%b==0)return to_string(a/b);string ch=to_string(a/b);ll c=a%b;ll g=gcd(c,b);c/=g;b/=g;ch+="+"+to_string(c)+"/"+to_string(b);return ch;}

           /******************Code*********************/
map<pi,char>mp;
map<pi,vector<pi>>graph;
map<pi,bool>vis;
vector<pi>offf;
void dfs(pi p,ll maxi){
    if(vis[p])return;
    if(offf.size()==maxi)return;
    offf.pb(p);
    vis[p]=1;
    for(auto x:graph[p]){
        dfs(x,maxi);
    }
}
vl X={0,0,1,-1};
vl Y={1,-1,0,0};
void solve(){
    ll n,m,k;
    cin>>n>>m>>k;
    ll nb=0;
    pi okba;
    for(ll i=0;i<n;i++){
        string ch;
        cin>>ch;
        for(ll j=0;j<m;j++){
            if(ch[j]=='.'){mp[{i,j}]='.';nb++;okba={i,j};}
            else mp[{i,j}]='#';
        }
    }
    for(auto x:mp){
        if(x.S=='.'){
            for(ll k=0;k<4;k++){
                if(x.F.F+X[k]>=0&&x.F.S+Y[k]>=0&&x.F.F+X[k]<n&&x.F.S+Y[k]<m&&mp[{x.F.F+X[k],x.F.S+Y[k]}]=='.')graph[x.F].pb({x.F.F+X[k],x.F.S+Y[k]});
            }
        }
    }
    ll ans=nb-k;
    dfs(okba,ans);
    ll c=0;
    for(auto x:mp){
        if(mp[x.F]=='.'){
            if(vis[x.F])cout<<'.';
            else cout<<'X';
        }
        else cout<<mp[x.F];
        c++;
        if(c==m){cout<<endl;c=0;}
    }
}
int main()
{
    L_Headshot_7;
    //READ;
    //WRITE;
    //ll test;
    //cin>>test;
   // while(test--){
        solve();
      // }
    return 0;
}