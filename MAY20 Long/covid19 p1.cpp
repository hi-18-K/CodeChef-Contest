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
    int t;
    cin >> t;
    while(t--) {
        int i,n;
        cin >> n;
        int a[n];
        for(i=0;i<n;i++)    cin >> a[i];
        sort(a,a+n);
        int cnt=1,minm=11,maxm=0;
        for(i=1;i<n;i++) {
            if(a[i]-a[i-1] <= 2) {
                cnt++;
            }
            else {
                if(cnt < minm) {
                    minm = cnt;
                }
                if(cnt > maxm) {
                    maxm = cnt;
                }
                cnt = 1;
            }
        }
        if(cnt >maxm) {
            maxm = cnt;
        }
        if(cnt < minm) {
            minm = cnt;
        }
        cout << minm << " " << maxm << ln;
    }
    return 0;
}
