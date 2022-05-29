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
const           ll N=2e5+2;
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
#define         aff(v) for(auto e:v) cout<<e<<endl;cout<<endl;
#define         all(v) v.begin(), v.end()
#define         rall(v) v.rbegin(), v.rend()
#define         READ freopen("input.txt", "r",stdin)
#define         WRITE freopen("output.txt", "w",stdout)

            /***************** Useful *********************/
ll  dx[]={1,-1,0,0,1,1,-1,-1};
ll  dy[]={0,0,1,-1,1,-1,-1,1};

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



                /******************Code******************/
vl BiTree(N);
void update(ll pos,ll val,ll n){
    while(pos<=n){
        BiTree[pos]+=val;
        pos+=(pos)&(-pos);
    }
}
ll get_range(ll pos){
    ll res=0;
    while(pos>0){
        res+=BiTree[pos];
        pos-=(pos)&(-pos);
    }
    return res;
}
void solve(){
    ll n;
    cin>>n;
    vl v(n+1);
    rep(i,1,n+1)cin>>v[i];
    ll ans=0;
    for(ll i=n;i>0;i--){
        ans+=get_range(v[i]);
        update(v[i],1,n);
    }
    cout<<ans<<endl;
    for(ll i=n;i>0;i--)update(v[i],-1,n);
}
int main()
    {
        KIRA;
        //READ;
        //WRITE;
        ll _=1;
        cin >>_;
        //cout<< setprecision(5);
        while(_--)solve();
    }

                /** NEVERMIND MY CODE **/
