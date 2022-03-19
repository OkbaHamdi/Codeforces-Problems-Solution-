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
typedef         priority_queue<ll>pq;
typedef         priority_queue<ll,vector<ll>,greater<ll>>pqg;


    /********** Constantes **************/

const           ll MOD = 1000000007;
const           ll eps=1e-9;
const           double PI=acos(-1);
const           ll N=1e4+5;

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


void solve()
{
    ll n,nn;
    cin>>n;
    deque<ll>q,ans;
    nn=n;
    while(nn--){
        ll a;
        cin>>a;
        q.pb(a);
    }
    if(n%2==0){
        for(ll i=0;i<q.size()-1;i+=2){
            ans.pb(-q[i+1]);ans.pb(q[i]);
        }
    }
    else{
        if(q.size()>3){
        for(ll i=0;i<q.size()-4;i+=2){
          ans.pb(-q[i+1]);ans.pb(q[i]);
        }
        ll a=q[q.size()-3];
        ll b=q[q.size()-2];
        ll c=q[q.size()-1];
        if(a+b){
            ans.pb(c);
            ans.pb(c);
            ans.pb(-a-b);
            }
        else if(a+c){
            ans.pb(b);
            ans.pb(-a-c);
            ans.pb(b);
            }
        else if (c+b){
            ans.pb(-b-c);
            ans.pb(a);
            ans.pb(a);
            }
        }
        else{
        ll a=q[q.size()-3];
        ll b=q[q.size()-2];
        ll c=q[q.size()-1];
        if(a+b){
            ans.pb(c);
            ans.pb(c);
            ans.pb(-a-b);
            }
        else if(a+c){
            ans.pb(b);
            ans.pb(-a-c);
            ans.pb(b);
            }
        else if (c+b){
            ans.pb(-b-c);
            ans.pb(a);
            ans.pb(a);
            }
        }
    }
    aff(ans);
}
int main()
{
    L_Headshot_7;
    //READ;
    //WRITE;
    ll test;
    cin>>test;
    while(test--){
        solve();
       }
    return 0;
}
