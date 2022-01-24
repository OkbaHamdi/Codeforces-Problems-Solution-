/*      Author :

        L_7

        OKBA HAMDI
                        */
#include<bits/stdc++.h>
using namespace std;

    /* Typedef */

typedef         long long ll;
typedef         long double ld;
typedef         vector<ll>vl;

    /* Constantes */

const           ll MOD = 1000000007;
const           ll eps=1e-9;
const           double PI=acos(-1);
const           ll N=1e+5+5;

    /*  Define  */

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
void solve()
{
    ll n;
    cin>>n;
    ll s,x;
    cin>>x;
    s=x;
    n--;
    while(n--){
        ll a;
        cin>>a;
        x^=a;
        s+=a;
    }
    cout<<2<<endl;
    cout<<x<<" "<<s+x<<endl;
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
