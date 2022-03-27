/************ Author :OKBA HAMDI**************/

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

const           ll MOD = 998244353;//1000000007;
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
#define         KIRA ios_base::sync_with_stdio(false);cin.tie(0);
#define         aff(v) for(auto e:v) cout<<e<<" ";cout<<endl;
#define         all(v) v.begin(), v.end()
#define         rall(v) v.rbegin(), v.rend()
#define         READ freopen("input.txt", "r",stdin)
#define         WRITE freopen("output.txt", "w",stdout)

            /***************** Useful Functions *********************/
ll fact(ll x){return(x<2?1:x*(fact(x-1))%MOD);}
ll binexp(ll a,ll k){ll ans=1;while(k){if(k&1)ans=(ans*a)%MOD;a=(a*a)%MOD;k>>=1;}return ans;}
ll gcd(ll a, ll b){while (b) swap(b, a %= b);return a;}
inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
string yup(ll a,ll b){if(a%b==0)return to_string(a/b);string ch=to_string(a/b);ll c=a%b;ll g=gcd(c,b);c/=g;b/=g;ch+="+"+to_string(c)+"/"+to_string(b);return ch;}
                /******************Code******************/
void solve(){
    ll l,r,n;
    cin>>l>>r;
    n=r-l+1;
    ll ans=0;
    if(n%2){
        rep(i,0,n){
            ll a;
            cin>>a;
            ans^=a^(l+i);
        }
        cout<<ans<<endl;
        return;
    }
    map<ll,pi>mp;
    rep(i,0,n){
        ll a;
        cin>>a;
        for(ll j=0;j<=17;j++){
            ll b=(a>>j)&1;
            if(b)mp[j].F++;
            else mp[j].S++;
        }
    }
    for(auto x:mp){
        if(x.S.F>x.S.S)ans+=binexp(2,x.F);
    }
    cout<<ans<<endl;
}
int main()
{
     KIRA;
    //READ;
    //WRITE;
    ll test=1;
    cin>>test;
    while(test--){
        solve();
       }
    return 0;
}
