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
ll N,M;
ll A[100010], B[100010];
vector<ll> tree[100010];
ll d[100010];
ll check[100010] = {};
bool is_two = true;
void dfs(ll cur, ll val){
    if(!check[cur]){
        check[cur] = 1;
        d[cur] = val;
    }else{
        if(d[cur] != val){
            is_two = false;
        }
        return;
    }
    for(auto &e: tree[cur]){
        if(val == 0){
            dfs(e, 1);
        }else{
            dfs(e, 0);
        }
    }

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    rep(i,0,M){
        cin >> A[i] >> B[i];
        A[i]--; B[i]--;
        tree[A[i]].push_back(B[i]);
        tree[B[i]].push_back(A[i]);
    }
    memset(d, -1, sizeof(d));
    dfs(0, 0);
    if(!is_two){
        print(N * (N-1) / 2 - M);
    }else{
        ll cnt = 0;
        rep(i,0,N){
            if(d[i] == 1) cnt++;
        }
        print(cnt * (N - cnt) - M);
    }


}
