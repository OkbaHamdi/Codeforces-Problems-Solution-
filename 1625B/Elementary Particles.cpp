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
const           ll N=1e+9+5;

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
void solve()
{
    ll n;
    cin>>n;
    map<ll,vector<ll>>mp;
    vector<ll>v;
    priority_queue<ll>pq;
    for(ll i=0;i<n;i++){
        ll a;
        cin>>a;
        v.pb(a);
        mp[a].pb(i);
    }
    for(auto x:mp){
        if(x.S.size()>1){
            for(ll i=0;i<x.S.size()-1;i++){
                ll a=x.S[i];
                ll b=x.S[i+1];
                pq.push(n-b+a);
            }
        }
    }
    if(pq.size()==0){cout<<-1<<endl;return;}
    cout<<pq.top()<<endl;
}

int main()
{
    L_Headshot_7;
    ll test;
    cin>>test;
    while(test--){
        solve();
        }
    return 0;
}
