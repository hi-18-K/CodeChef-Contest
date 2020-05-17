#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <iostream>
#include<string>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
#include<iterator>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long 
#define  sll stack<ll>
#define  qll queue<ll>
#define  pll pair<ll,ll>
#define  vll vector<ll>
#define mpll map<ll,ll>
#define  vpi vector<pair<int,int>>
//#define f first
#define s second
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define ppb pop_back
#define f0(i,n) for(i=0;i<n;i++)
#define f1(i,n) for(i=1;i<n;i++)
#define fab(i,a,b) for(i=a;i<b;i++)
#define ln "\n"
//#define mod 1e9+7

int main() {
    //fastio
    /*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
     #endif*/
    fastio
    int t;
    cin >> t;
    while(t--) {
      string s ;
      ll n,q,i,j,maxm=0;
      cin >> n >> q;
      cin >> s;
      ll f[26] = {0};
      for(i=0;i<n;i++) {
        f[s[i]-97]++;
        if(f[s[i]-97] > maxm) {
            maxm = f[s[i]-97];
        }
      }
      while(q--) {
        ll x,cnt=0;
        cin >> x;
        if(x>maxm) {
            cout << "0\n";
        }
        else {
            for(j=0;j<26;j++) {
                if(f[j] > x)
                    cnt+=(f[j]-x);
            }
            cout << cnt << ln;
        }
      }
    }
    return 0;
}
