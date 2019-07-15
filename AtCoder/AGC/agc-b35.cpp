#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;
ll N,M;
ll A[100010], B[100010];
vector<ll> tree[100010];
ll now[100010] = {};
stack<lpair> st[100010];
ll howmany[100010] = {}; //いくつ外に出たか
map<lpair, ll> is_use;
ll cnt[100010] = {};
vector<lpair> ans;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    rep(i,0,M){
        cin >> A[i] >> B[i];
        A[i]--; B[i]--;
        tree[A[i]].push_back(B[i]);
        tree[B[i]].push_back(A[i]);
        cnt[A[i]]++;
        cnt[B[i]]++;
    }
    if(M % 2 == 1){
        print(-1);
        return 0;
    }
    priority_queue<lpair, vector<lpair>, greater<lpair> > pq;
    rep(i,0,N){
        pq.push(make_pair(cnt[i], i));
    }
    
    
    rep(i,0,N) now[i] = cnt[i];
    rep(i,0,M){
        st[A[i]].push(make_pair(A[i], B[i]));
        st[B[i]].push(make_pair(B[i], A[i]));
    }
    // printa(cnt ,N);
    // print("solve");
    while(not pq.empty()){
        ll num = pq.top().first;
        ll cur = pq.top().second;
        pq.pop();
        // print2(cur, num);
        if(now[cur] != num) continue;
        // print2(cur, num);
        if(num % 2 == 1){
            lpair l1;
            while(1){
                l1 = st[cur].top();
                st[cur].pop();
                if(is_use[l1] == 1 || is_use[make_pair(l1.second, l1.first)] == 1){
                }else{
                    break;
                }
            }
            // cout << "a" << l1.first << " " << l1.second << endl;
            is_use[l1]++;
            if(howmany[cur] % 2 == 0){
                howmany[l1.second]++;
                ans.push_back(make_pair(l1.second, l1.first));
            }else{
                ans.push_back(make_pair(l1.first, l1.second));
                howmany[l1.first]++;
            }
            now[l1.first]--;
            now[l1.second]--;
            if(now[l1.first] != 0){
                pq.push(make_pair(now[l1.first], l1.first));
            }
            if(now[l1.second] != 0){
                pq.push(make_pair(now[l1.second], l1.second));
            }


        }else{
            lpair l1;
            while(1){
                l1 = st[cur].top();
                st[cur].pop();
                if(is_use[l1] == 1 || is_use[make_pair(l1.second, l1.first)] == 1){
                }else{
                    break;
                }
            }
            is_use[l1]++;
            ans.push_back(make_pair(l1.first, l1.second));
            howmany[l1.first]++;

            now[l1.first]--;
            now[l1.second]--;
            if(now[l1.first] != 0){
                pq.push(make_pair(now[l1.first], l1.first));
            }
            if(now[l1.second] != 0){
                pq.push(make_pair(now[l1.second], l1.second));
            }

        }


        
    }
    // print("res");
    rep(i,0,ans.size()){
        cout << ans[i].first+1 << " " << ans[i].second+1 << endl;
    }
}