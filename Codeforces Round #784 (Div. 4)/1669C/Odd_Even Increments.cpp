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

const           ll MOD = /*998244353;//*/1000000007;
const           ll eps=1e-9;
const           double PI=acos(-1);
const           ll N=1e6+5;
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
ll C(ll n,ll k){return (fact(n)/(fact(k)*fact(n-k)));}
string yup(ll a,ll b){if(a%b==0)return to_string(a/b);string ch=to_string(a/b);ll c=a%b;ll g=gcd(c,b);c/=g;b/=g;ch+="+"+to_string(c)+"/"+to_string(b);return ch;}
                /******************Code******************/
void solve(){
    ll n;
    cin>>n;
    vl v(n);
    rep(i,0,n)cin>>v[i];
    bool odd=1,even=1;
    ll cur=v[0]%2;
    for(ll i=2;i<n;i+=2){
        if(v[i]%2!=cur){odd=0;break;}
    }
    cur=v[1]%2;
    for(ll i=1;i<n;i+=2){
        if(v[i]%2!=cur){even=0;break;}
    }
    if(odd&&even){cout<<"YES"<<endl;return;}
    cout<<"NO"<<endl;
}

    int main()
    {
        KIRA;
        //READ;
        //WRITE;
        ll tests = 1;
        cin >> tests;
        while(tests--)solve();
    }
