/************ Author :OKBA HAMDI**************/

#include<bits/stdc++.h>
using namespace std;

    /***************Typedef *************/

typedef         long long ll;
typedef         long double ld;
typedef         vector<ll>vl;
typedef         deque<ll>dq;
typedef         pair<ll,ll>pl;
typedef         priority_queue<ll>pq;
typedef         priority_queue<ll,vector<ll>,greater<ll>>pqg;


    /********** Constantes **************/

//const           ll MOD = 998244353;
const           ll MOD = 1000000007;
const           ll eps=1e-9;
const           double PI=acos(-1);
const           ll N=1e5+2;
const           ll INF=1e10;

            /************  Define  ****************/

#define         F first
#define         S second
#define         pb push_back
#define         ppb pop_back
#define         pf push_front
#define         ppf pop_front
#define         sz(x)  (ll)((x).size())
#define         rep(i,a,b) for(ll i=a;i<b;i++)
#define         KIRA ios_base::sync_with_stdio(false);cin.tie(0);
#define         aff(v) for(auto e:v) cout<<e<<" ";cout<<endl;
#define         all(v) v.begin(), v.end()
#define         rall(v) v.rbegin(), v.rend()
#define         READ freopen("input.txt", "r",stdin)
#define         WRITE freopen("output.txt", "w",stdout)

            /***************** Useful Functions *********************/

ll fact(ll x){return(x<2?1:x*(fact(x-1))%MOD);}
ll C(ll n, ll r){ll p = 1, k = 1;if (n - r < r)r = n - r;if (r != 0) {while (r) {p *= n;k *= r;ll m = __gcd(p, k);p /= m;k /= m;n--;r--;}}else p = 1;return p;}
ll A(ll n,ll k){ll P = 1;for (ll i = 0; i < k; i++)P *= (n-i) ;return P;}
ll binexp(ll a, ll k){ll ans = 1;while (k){if (k & 1) ans = (ans * a) % MOD;a = (a * a) % MOD;k >>= 1;}return ans;}
ll binexpp(ll a, ll k){ll ans = 1;while (k){if (k & 1) ans = (ans * a) ;a = (a * a) ;k >>= 1;}return ans;}
ll gcd(ll a, ll b){while (b) swap(b, a %= b);return a;}
inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
string yup(ll a,ll b){if(a%b==0)return to_string(a/b);string ch=to_string(a/b);ll c=a%b;ll g=gcd(c,b);c/=g;b/=g;ch+="+"+to_string(c)+"/"+to_string(b);return ch;}

                /******************Code******************/

void solve(){
    ll n,k;
    cin>>n>>k;
    map<ll,ll>mp;
    rep(i,0,n){
        ll a;
        cin>>a;
        mp[a]++;;
    }
    vl v;
    vector<pl>ans;
    for(auto x:mp){
        if(x.S>=k)v.pb(x.F);
    }
    if(v.size()==0){
        cout<<-1<<endl;
        return;
    }

    if(v.size()==1){
        cout<<v[0]<<" "<<v[0]<<endl;
        return;
    }
    ans.pb({v[0],v[0]});
    for(ll i=1;i<v.size();i++){
        if(v[i]==ans[ans.size()-1].S+1){
            ans[ans.size()-1].S=v[i];
        }
        else ans.pb({v[i],v[i]});
    }
    ll maxi=-1,ans1,ans2;
    for(auto x:ans){
        if(x.S-x.F>=maxi){
            ans1=x.F;
            ans2=x.S;
            maxi=x.S-x.F;
        }
    }
    cout<<ans1<<" "<<ans2<<endl;
    //for(auto x:ans)cout<<x.F<<" "<<x.S<<" and ";
}

    int main()
    {
        KIRA;
        //READ;
        //WRITE;
        ll _=1;
        cin >>_;
        //cout<<fixed();
        //cout<<setprecision(6);
        while(_--)solve();
    }
