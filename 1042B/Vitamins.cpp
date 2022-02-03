        /*********************私はキラです***********************/
#include<bits/stdc++.h>
using namespace std;
            /*****************私はキラです*****************/
typedef         long long ll;
typedef         long double ld;
typedef         vector<ll>vl;
typedef         deque<ll>dq;
typedef         pair<ll,ll>pi;
typedef         priority_queue<ll>pq;
typedef         priority_queue<ll,vector<ll>,greater<ll>>pqg;
           /******************私は偽物ではありません*************/
const           ll MOD = 1000000007;
const           ll eps=1e-9;
const           double PI=acos(-1);
const           ll N=2e5+5;
const           ll INF=1e18;
            /*******************私は私の敵です***********************/
#define         F first
#define         S second
#define         pb push_back
#define         ppb pop_back
#define         pf push_front
#define         ppf pop_front
#define         sz(x)  (ll)((x).size())
#define         rep(i,a,b) for(ll i=a;i<b;i++)
#define         KIRA ios_base::sync_with_stdio(false);cin.tie(0);
#define         aff(v) for(auto e:v) cout<<e<<endl;cout<<endl;
#define         all(v) v.begin(), v.end()
#define         rall(v) v.rbegin(), v.rend()
#define         READ freopen("d_difficult.in.txt", "r",stdin)
#define         WRITE freopen("outputd.txt", "w",stdout)

            /*****************キラは生きている*******************/

ll division(ll a, ll b) {return a % b == 0 ? a / b : a / b +1;}
ll fact(ll x){return(x<2?1:x*fact(x-1));}
ll binexp(ll a,ll k){ll ans=1;while(k){if(k&1)ans=(ans*a)%MOD;a=(a*a)%MOD;k>>=1;}return ans;}
ll gcd(ll a, ll b){while (b) swap(b, a %= b);return a;}inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }ll ext(ll a, ll b, ll& x, ll& y){x = 1, y = 0;ll x1 = 0, y1 = 1, a1 = a, b1 = b;while (b1){ll q = a1 / b1;tie(x, x1) = make_pair(x1, x - q * x1);tie(y, y1) = make_pair(y1, y - q * y1);tie(a1, b1) = make_pair(b1, a1 - q * b1);}return a1;}
string yup(ll a,ll b){if(a%b==0)return to_string(a/b);string ch=to_string(a/b);ll c=a%b;ll g=gcd(c,b);c/=g;b/=g;ch+="+"+to_string(c)+"/"+to_string(b);return ch;}

        /**********************キラはプログラミングが大好き****************************/
void solve(){
    ll n;
    cin>>n;
    vector<pair<string,ll>>v;
    v.pb({"A",MOD});
    v.pb({"B",MOD});
    v.pb({"C",MOD});
    v.pb({"AB",MOD});
    v.pb({"AC",MOD});
    v.pb({"BC",MOD});
    v.pb({"ABC",MOD});
    while(n--){
        ll a;
        string b;
        cin>>a>>b;
        if(b.size()==3)v[6].S=min(v[6].S,a);
        else if(b.size()==1)v[b[0]-'A'].S=min(a,v[b[0]-'A'].S);
        else {
            char c=min(b[0],b[1]);
            char d=max(b[0],b[1]);
            string ch="  ";
            ch[0]=c;ch[1]=d;
            for(ll i=3;i<=5;i++){
                if(v[i].F==ch){
                    v[i].S=min(a,v[i].S);
                }
            }
        }
    }
        pqg p;
        p.push(v[6].S);
        for(ll i=5;i>=2;i--){
              ll ans=v[i].S;
              set<char>s;
              for(auto x:v[i].F)s.insert(x);
              ll test=s.size();
              for (ll j=i-1;j>=0;j--){
                ans+=v[j].S;
                for(auto x:v[j].F)s.insert(x);
                if(s.size()==test){s.clear(); for(auto x:v[i].F)s.insert(x);ans-=v[j].S;}
                else if(s.size()==3){
                    s.clear();
                    for(auto x:v[i].F)s.insert(x);
                    p.push(ans);
                    ans-=v[j].S;
                }
              }
        }
        if(p.top()==MOD){cout<<-1;return;}
        cout<<p.top();
    }
int main()
{
    KIRA;
    //READ;
    //WRITE;
    //ll test;
   // cin>>test;
    //while(test--){
        solve();
     //  }
    return 0;
}
