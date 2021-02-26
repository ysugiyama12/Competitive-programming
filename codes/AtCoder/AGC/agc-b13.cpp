#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define INF (1e18)
ll N,M;
ll A[100010], B[100010];
vector<ll> tree[100010];
ll is_visit[100010] = {};
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
    is_visit[A[0]] = 1;
    is_visit[B[0]] = 1;
    deque<ll> dq;
    dq.push_front(A[0]);
    dq.push_back(B[0]);
    while(1){
        ll p1 = dq.front();
        ll p2 = dq.back();
        bool ok = true;
        for(auto &e: tree[p1]){
            if(is_visit[e] == 0) ok = false;
        }
        for(auto &e: tree[p2]){
            if(is_visit[e] == 0) ok = false;
        }
        if(ok){
            print(dq.size());
            for(auto &e: dq){
                cout << e+1 << " ";
            }
            cout << endl;
            return 0;
        }else{
            bool change = false;
            for(auto &e: tree[p1]){
                if(is_visit[e] == 0){
                    change = true;
                    dq.push_front(e);
                    is_visit[e] = 1;
                    break;
                }
            }
            if(change) continue;
            for(auto &e: tree[p2]){
                if(is_visit[e] == 0){
                    dq.push_back(e);
                    is_visit[e] = 1;
                    break;
                }
            }
        }

    }
    

}
