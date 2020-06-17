#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <iostream>
#include<string>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long 
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
#define fabl(i,a,b) for(i=a;i<b;i++)
#define fabe(i,a,b) for(i=a;i<=b;i++)
#define fre(i,a,b) for(i=b;i>=a;i--)
# include <cstdio> 
# include <string> 
# include <vector> 

void solve(){
    ll n,i,j,l,r;
    cin >> n;
    l=1,r=n;
    for(i=0;i<300;i++){
        ll x= rand()%(r-l+1)+l;
        cout << x << endl;
        char c,ch;
        cin >> c;
        if(c=='E') return;
        cout << x << endl;
        cin >> ch;
        if(ch==c){
            if(ch=='G') l=x+1;
            else r=x-1;
        }
    }
}
int main(){
    fastio //ll t; cin >> t; while(t--)
    srand(time(0));
    solve();
    return 0;
}
