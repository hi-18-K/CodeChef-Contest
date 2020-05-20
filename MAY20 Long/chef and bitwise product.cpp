/*राधे कृष्णा*//*राधे कृष्णा*//*राधे कृष्णा*//*राधे कृष्णा*/
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
// bitmask
//codechef may long p4-upsolve
ll x,y,l,r;
ll sol=LLONG_MAX, tmp_sol=0;
ll setbit(ll b , ll i){
	b = b|(1LL<<i);
	return b;
}
ll unsetbit(ll b , ll i){
	b = b&(~(1LL<<i));
	return b;
}
bool check(ll b , ll i){
	if(b&(1LL<<i))
		return 1;
	else return 0;
}
ll func(ll z){
	return ((x&z) * (y&z));
}
ll get_pre(){
	tmp_sol=0; ll k=0;
	for(ll i=42;i>=0;i--){
		if(check(r,i) == check(l,i)){
			if(check(r,i)){
				tmp_sol = setbit(tmp_sol,i);
			}
		}
		else{
			k=i;
			break;
		}
	}
	return k;
}
void solve() {
	cin >> x >> y >> l >> r;
	ll _or=x|y; ll mx=func(l), t_sol=tmp_sol;
	if(x==0 || y==0){
		sol = l;
	}
	else {	
		sol = l;
		ll k=get_pre();
		//cout << k << " ";
		for(ll i=k;i>=0;i--){
			//initialize container with prefied value
			t_sol=tmp_sol;
			//taking all possible prefix of R
			for(ll j=k; j>=i+1;j--){
				if(check(r,j)){
					t_sol = setbit(t_sol,j);
				}
			}
			//switching ith bit as z should be smaller than R(not needed as already OFF)
			t_sol=unsetbit(t_sol,i);
			//copying next bit of X|Y 
			for(ll j=i-1;j>=0;j--){
				if(check(_or,j)){
					t_sol = setbit(t_sol,j);
				}
			}
			//checking for validatins
			if(t_sol <=r && t_sol >= l){
				//selecting optimal solution 
				if(mx < func(t_sol)){
					mx = func(t_sol);
					sol = t_sol;
				}
				//taking minimal possible z
				if(mx==func(t_sol))
					sol = min(t_sol,sol);
			}			
		}
		//cout << sol << "  ";
		for(ll i=k;i>=0;i--){
			//initializing container with prefix value
			t_sol = tmp_sol;
			//taking all prefix of R
			for(ll j=k;j>=i+1;j--){
				if(check(l,j)){
					t_sol = setbit(t_sol,j);
				}
			}
			//turning ith bit as z shoud be greater than L
			t_sol=setbit(t_sol,i);
			//copying next bits of X|Y for maximizing F
			for(ll j=i-1;j>=0;j--){
				if(check(_or,j)){
					t_sol = setbit(t_sol,j);
				}
			}
			//checking for validations
			if(t_sol <= r && t_sol >= l){
				//selecting optimal solution
				if(mx < func(t_sol)){
					mx = func(t_sol);
					sol = t_sol;
				}
				if(mx==func(t_sol))
					sol = min(t_sol,sol);
			}
		}
		//cout << sol << "  ";
		if(func(r) > mx){
			sol = r;
		}
		if(func(l) > mx){
			sol = l;
		}
		//cout << sol << "  ";
	}
	cout << sol << ln;
	sol = LLONG_MAX;
}
int main(){
	fastio
	ll t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
