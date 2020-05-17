
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
#define f first
#define s second
//#define mp make_pair
#define pb push_back
#define ppb pop_back
#define test ll t;cin >>t; while(t--)
#define ln "\n"
#define f0(i,n) for(i=0;i<n;i++)
#define f1(i,n) for(i=1;i<n;i++)
#define fab(i,a,b) for(i=a;i<b;i++)
map<ll,ll> couple;   vector<pair<ll,pair<ll,ll>>> v; bool mark[200005]={0}; 
ll n,i,j,x,y,k;
ll solvecouple() {
    if((couple.size()/2)%2 ==1)
        return -1;
    else{
        ll ans=0,i=1;
        while(couple.size() > 2){
            ll xf,xs,yf,ys,zf,zs;
            xf = (couple.begin())->first;   mark[xf]=1;
            xs = couple[xf];
            yf = xs;    mark[yf]=1;
            ys = couple[yf];
            i=1;
            while(mark[i] == 1) {
                    i++;
            }
            zf=i;   mark[i]=1;
            zs=couple[zf];
            ll temp = ys; ys=xs; xs=zs; zs=temp;
            couple[xf]=xs; couple[yf]=ys; couple[zf]=zs;
            v.pb({xf,{yf,zf}});
            couple.erase(yf);
            yf = xs;    mark[yf]=1;
            ys = couple[yf];
            temp = ys; ys=xs; xs=zs; zs=temp;
            couple[xf]=xs; couple[yf]=ys; couple[zf]=zs;
            v.pb({xf,{yf,zf}});
            couple.erase(xf);
            couple.erase(yf);
            couple.erase(zf);
            ans+=2;
        }
        return ans;
    }
}
void solve() {
    cin >> n >> k;
    for(i=0;i<=n+2;i++)    mark[i]=0;
    ll a[n+1];
    map<ll,ll> mp;  
    for(i=1;i<=n;i++) {
        cin >> a[i];
        if(a[i] != i)   {mp[i] = a[i];}
        else {mark[i] = 1;}
    }
    bool flag=0; ll cnt=0,cntx=0;  i=1;
    while(mp.size()>0){
        if(mp.size()==1) {cntx=-1;break;}
        ll xf,xs,yf,ys,zf,zs;
        xf = (mp.begin())->first;   mark[xf]=1;
        xs = mp[xf];
        yf = xs;    mark[yf]=1;
        ys = mp[yf];
        if(ys != xf) {
            zf = ys;    mark[zf]=1;
            zs = mp[zf];
            ll temp = ys; ys=xs; xs=zs; zs=temp;
            mp[xf]=xs; mp[yf]=ys; mp[zf]=zs;
            v.pb({xf,{yf,zf}}); mp.erase(zf);
            mp.erase(yf);
            if(xs == xf) {
                mp.erase(xf);
            } 
            cnt++;
        }
        else {       // create couple st xf-xs,yf-ys are:-mp[xf]=xs=yf & mp[yf]=ys=xf
            mark[xf]=0;mark[yf]=0;
            couple[xf]=xs;  couple[yf]=ys;
            mp.erase(xf);   mp.erase(yf);
        }
    }
    cntx = solvecouple();   // solve all the couples togather
    if(cntx == -1 || cnt+cntx > k) {
        cout << "-1\n";
    }
    else {
        cout << cnt+cntx << ln;
        for(i=0;i<v.size();i++) {
            cout << v[i].f << " " << v[i].s.f << " " << v[i].s.s << ln;
        }
    }
}
int main()
{
    fastio
    int t;
    cin >> t;
    while(t--) {
        couple.clear(); v.clear();
        solve();
    }
    return 0;
}
