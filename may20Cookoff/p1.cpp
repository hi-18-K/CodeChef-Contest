#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <iostream>
#include<string>
#include<map>
#include<queue>
#include<algorithm>
#include<stack>
#include<limits>
#include<math.h>
#include<vector>
#include<assert.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll unsigned long long int 
#define  sll stack<ll>
#define  qll queue<ll>
#define  pll pair<ll,ll>
#define  vll vector<ll>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define test ll t;cin >>t; while(t--)
#define ln "\n"
#define fabl(i,a,b) for(i=a;i<b;i++)
#define fabe(i,a,b) for(i=a;i<=b;i++)
#define fre(i,a,b) for(i=b;i>=a;i--)
#define mod 1000000007
void solve(){
    ll n,i,j,x,y;
    cin >> n;
    ll a[n+1];
    for(i=1;i<=n;i++){
        cin >> a[i];
    }
    bool mark[n+1]={0}; bool flag=0;
    map<ll,ll> mp , mp2;  
    for(i=1;i<=n;){
            x=a[i];
            ll cnt=0;
            while(a[i]==x){
                cnt++;
                i++;
            }
            mp[x]++;
            mp2[cnt]++;
    }
    for( auto itr:mp){
        if(itr.second >1){
            flag=1; break;
        }
    }
    for(auto itr: mp2){
        if(itr.second > 1){
            flag=1; break;
        }
    }
    end:
    if(flag==1){
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
    }
}
int main()
{
    fastio
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
