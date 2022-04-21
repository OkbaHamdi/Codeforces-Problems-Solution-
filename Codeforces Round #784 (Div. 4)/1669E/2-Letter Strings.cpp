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
   map<char,map<string,ll>>mp1,mp2;
   rep(i,0,n){
       string ch;
       cin>>ch;
       mp1[ch[0]][ch]++;
       mp2[ch[1]][ch]++;
   }
   ll ans=0;
   for(auto x:mp1){
         ll sum=0;
        for(auto y:x.S)sum+=y.S;
        for(auto y:x.S){sum-=y.S;ans+=sum*y.S;}
   }
   for(auto x:mp2){
         ll sum=0;
        for(auto y:x.S)sum+=y.S;
        for(auto y:x.S){sum-=y.S;ans+=sum*y.S;}
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
