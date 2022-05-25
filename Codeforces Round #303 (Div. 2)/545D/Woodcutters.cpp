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

const             ll MOD = LLONG_MAX;
//const           ll MOD = 998244353;
//const           ll MOD = 1000000007;
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
#define         rep(i,a,b) for(ll i=a;i<b;i++)
#define         KIRA ios_base::sync_with_stdio(false);cin.tie(0);
#define         aff(v) for(auto e:v) cout<<e<<" ";cout<<endl;
#define         all(v) v.begin(), v.end()
#define         rall(v) v.rbegin(), v.rend()
#define         READ freopen("input.txt", "r",stdin)
#define         WRITE freopen("output.txt", "w",stdout)

            /***************** Useful Functions *********************/

/**Factorial**/
ll fact(ll x){return(x<2?1:x*(fact(x-1))%MOD);}

/**Combination**/
ll C(ll n, ll r){
    ll p = 1, k = 1;
    if (n - r < r)r = n - r;
    if (r != 0) {
            while (r) {
                p *= n;k *= r;
                ll m = __gcd(p, k);
                p /= m;k /= m;n--;r--;
                }
            }
    else p = 1;
    return p;
    }

/**Permutation**/
ll A(ll n,ll k){
    ll P = 1;
    for (ll i = 0; i < k; i++)P *= (n-i) ;
    return P;
}

/**Power**/
ll binexp(ll a, ll k){
    ll ans = 1;
    while (k){
        if (k & 1) ans = (ans * a) % MOD;
        a = (a * a) % MOD;k >>= 1;
        }
    return ans;
    }
/**Least Common Multiple**/
inline ll lcm(ll a, ll b) { return a / __gcd(a, b) * b; }

/**Float with String**/
string yup(ll a,ll b){
    if(a%b==0)return to_string(a/b);
    string ch=to_string(a/b);
    ll c=a%b;
    ll g=__gcd(c,b);
    c/=g;b/=g;
    ch+="+"+to_string(c)+"/"+to_string(b);
    return ch;
}

/**Binary Conversion**/
string to_bin(ll n)
{
    string ch="";
    ll i = 0;
    while (n>0) {
        char a=n%2+'0';
        ch=a+ch;
        n = n / 2;
        i++;
    }
    return ch;
}

/**Decimal Conversion**/
ll to_dec(string ch){
    ll res=0;
    for (ll i=ch.size()-1;i>=0;i--){
        ll a=ch[i]-'0';
        ll p=ch.size()-i-1;
        if(a)res+=binexp(2,p);
        //DONT'T FORGET THE MOD
    }
    return res;
}

/**Segment Tree**/
ll tree[N*2];
void make_tree(ll tab[],ll n){
    for(ll i=0;i<n;i++)tree[n+i]=tab[i];
    for(ll i=n-1;i>0;i--)tree[i]=tree[i<<1]+tree[i<<1|1];
}
void update_tree(ll ind,ll val,ll n){
    tree[n+ind]=val;
    for(ll i=n+ind;i>1;i>>=1)tree[i>>1]=tree[i]+tree[i^1];
}
ll seg_query(ll l, ll r,ll n){
    ll res=0;
    l+=n;r+=n;
    for (; l < r; l >>= 1, r >>= 1){
            cout<<l<<" "<<r<<endl;
        if (l&1)
        {cout<<l<<" l"<<endl;
            res += tree[l++];}

        if (r&1)
            {res += tree[--r];cout<<r<<" r"<<endl;}
    }
    return res;
}

                /******************Code******************/
ll dp[N][3];
void solve(){
    ll n;
    cin>>n;
    vector<pl>v;
    rep(i,0,n){
        ll a,b;
        cin>>a>>b;
        v.pb({a,b});
    }
    dp[0][0]=1;
    if(n==1){cout<<1<<endl;return;}
    if(v[0].F+v[0].S<v[1].F)dp[0][2]=1;
    for(ll i=1;i<n;i++){
        dp[i][1]=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
        if(v[i].F-v[i].S>v[i-1].F){
            if(v[i].F-v[i].S>v[i-1].F+v[i-1].S){
                dp[i][0]=1+max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
                continue;
            }
            dp[i][0]=1+max(dp[i-1][0],dp[i-1][1]);
        }
        if(i==n-1||v[i].F+v[i].S<v[i+1].F)dp[i][2]=1+max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
    }
    cout<<max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]))<<endl;
}
int main()
    {
        KIRA;
        cout.tie(0);
        //READ;
        //WRITE;
        ll _=1;
        //cin >>_;
        //cout<< setprecision(5);
        while(_--)solve();
    }

                /** NEVERMIND MY CODE **/
