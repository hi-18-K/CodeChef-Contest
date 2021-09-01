#include<bits/stdc++.h>
using namespace std;
#define fastio 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll 				int 
#define pll 			pair<ll,ll>
#define vll 			vector<ll>
#define vs 				vector<string>
#define ff 				first
#define ss 				second
#define all(x) 			x.begin(),x.end()
#define pb 				push_back
#define ppb 			pop_back
#define ln 				cout << "\n" ;
#define maxHeapll 		priority_queue<ll>
#define minHeapll 		priority_queue <ll, vector<ll>, greater<ll> > 
#define ps(x,y)         fixed << setprecision(y) << x
#define fill(a,b)       memset(a, b, sizeof(a))

/*************************    	 CONSTANTS 		******************************/
#define mod 			1000000007
#define inf 			1e18
#define yes "YES"
#define no "NO"


void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> v(n+1, 0), pre(n+1, 0);
    for(int i = 1; i <= n; i += 1) {
    	cin >> v[i];
    	pre[i] = pre[i-1] + v[i];
    	pre[i] = pre[i] % m;
    }
    int ans = INT_MAX;
    if(pre[n] == 0) {
    	cout << 0; ln; return;
    }
    for (int suff = 1; suff < n; suff += 1) {
    	for (int pref = suff; ; pref = (pref-1) & suff) {
    		if(pref + suff >= n) {
    			if(pref == 0) break;
    			continue;
    		}
    		int sum = pre[n-suff] - pre[pref];
    		if(sum == 0) {
    			ans = min(ans, (int)__builtin_popcount(suff));
    		}
    		if(pref == 0) break;
    	}	
    }
    if(ans == INT_MAX) {cout << -1; ln; return;}
	cout << ans; ln;
}

int32_t main() 
{
	fastio;
	int t = 1; cin >> t; for(ll i=1;i<=t;i++)
	   // cout << "Case #" << i << ": ",
	    solve();
	return 0;
}
