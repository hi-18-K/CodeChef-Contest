#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <iostream>
#include<string>
#include<map>
#include<queue>
#include<algorithm>
#include <cstdio> 
#include <string> 
#include <vector> 
#include<bits/stdc++.h>
#include<queue>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
//#define test ll t;cin >> t;while(t--)
#define ll long long int
#define  sll stack<ll>
#define  qll queue<ll>
#define  pll pair<ll,ll>
#define  vll vector<ll>
#define  vpi vector<pair<int,int>>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define ln "\n"
#define f0(i,n) for(i=0;i<n;i++)
#define f1(i,n) for(i=1;i<n;i++)
#define fab(i,a,b) for(i=a;i<b;i++)
/*class first{
public:
	string str;	int val;
private:
	string str2; int val2;
public:
	string get_private_string(){
		return str2;
	} 
	int modify_private_value(int x){
		val2=x;
	}
	int get_private_value(){
		return val2;
	}
};*/

void solve() {
	ll n,i,j,x,y;
	cin >> n;
	ll a[n+1];
	for(i=1;i<=n;i++)	cin >> a[i];
	ll prf[n+1],suf[n+1];
	for(i=0;i<=n;i++)	prf[i]=1,suf[i]=1;
	prf[1]=a[1]; suf[n]=a[n];
	for(i=2;i<=n;i++){
		prf[i]=__gcd(prf[i-1],a[i]);
	}
	for(i=n-1;i>=1;i--){
		suf[i]=__gcd(suf[i+1],a[i]);
	}
	ll ans=1;
	for(i=0;i<=n-1;i++){
		if(i==0)
			ans=suf[2];
		else if(i==n-1){
			ans= ans*prf[n-1]/(__gcd(prf[n-1],ans));
		}
		else{
			ans= ans*(__gcd(prf[i],suf[i+2]))/(__gcd(__gcd(prf[i],suf[i+2]),ans));
		}
	}
	cout << ans << ln;;
}
int main(){
	fastio
	/*ll t;
	cin >> t;
	while(t--){*/
		solve();
	//}
	return 0;
}
