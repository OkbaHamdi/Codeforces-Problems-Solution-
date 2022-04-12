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
    map<ll,ll>mp;
    ll n;
    cin>>n;
    rep(i,0,n-1){
        ll a;
        cin>>a;
        mp[a]++;
    }
    pqg q,qq;
    ll ans=1;
    for(auto x:mp){
        q.push(x.S);
    }
    ll cur=2;
    while(q.size()){
        ll a=q.top();
        q.pop();
        a-=cur;
        cur++;
        ans++;
        if(a>0)qq.push(a);
    }
    bool b=0;
    while(q.size()||qq.size()){
        if(b==0){
            while(qq.size()>1){
                ll a=qq.top();
                qq.pop();
                a--;
                if(a>0)q.push(a);
                //ans++;
                //cout<<ans<<' '<<a<<endl;
            }
            ll a=qq.top();
                qq.pop();
                a-=2;
                if(a>0)q.push(a);
                ans++;
                //cout<<ans<<' '<<a<<endl;
        }
        else{
            while(q.size()>1){
                ll a=q.top();
                q.pop();
                a--;
                if(a>0)qq.push(a);
                //ans++;
                //cout<<ans<<' '<<a<<endl;
            }
            ll a=q.top();
                q.pop();
                a-=2;
                if(a>0)qq.push(a);
                ans++;
                //cout<<ans<<' '<<a<<endl;
        }
        b^=1;
    }
    cout<<ans<<endl;
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
