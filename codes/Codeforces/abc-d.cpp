#include <bits/stdc++.h>
#define rep(i,m,n) for(int i = (m); i < (n); i++)
#define rrep(i,m,n) for(int i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;

bool comp(lpair l1, lpair l2){
    if(l1.second == l2.second){
        return l1.first > l2.first;
    }
    return l1.second > l2.second;
}
struct compare{
    bool operator() (lpair l1, lpair l2){
         return l1.second > l2.second;
    }
};

struct compare2{
    bool operator() (lpair l1, lpair l2){
         return l1.second < l2.second;
    }
};
ll t[100010], d[100010];
priority_queue<lpair, vector<lpair>, compare> pq_top;
priority_queue<lpair, vector<lpair>, compare2> pq_other;
ll val[100010] = {};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,K;
    cin >> N >> K;
    rep(i,0,N){
        cin >> t[i] >> d[i];
    }
    vector<lpair> lp;
    rep(i,0,N){
        lp.push_back(make_pair(t[i], d[i]));
    }
    sort(lp.begin(), lp.end(), comp);
    map<ll, ll> mp1, mp2;
    ll ans = 0;
    rep(i,0,K){
        ans += lp[i].second;
        mp1[lp[i].first]++;
        mp2[lp[i].first]++;
        // pq_top.push(lp[i]);
    }
    rrep(i,K-1,0){
        if(mp2[lp[i].first] >= 2){
            mp2[lp[i].first]--;
            pq_top.push(lp[i]);
        }
    }

    rep(i,K,N){
        pq_other.push(lp[i]);
    }
    ll kinds = mp1.size();
    ans += kinds * kinds;
    val[kinds] = ans;
    while(!pq_other.empty()){
        lpair l1 = pq_other.top();
        pq_other.pop();
        if(mp1[l1.first] != 0) continue;
        if(pq_top.empty()) break;
        lpair l2 = pq_top.top();
        pq_top.pop();
        mp1[l2.first]--;
        mp1[l1.first]++;
        ans = ans + l1.second - l2.second + 2 * kinds + 1;
        kinds++;
        val[kinds] = ans;
    }
    ll v = -INF;
    rep(i,1,N+2){
        v = max(v,val[i]);
    }
    print(v);
}
