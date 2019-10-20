/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> lpair;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}

typedef struct {
    ll d;
    ll idx;
    ll amari;
} P;

struct compare{
    bool operator() (P l1, P l2){
         if(l1.d == l2.d){
             return l1.amari < l2.amari;
         }
         return l1.d > l2.d;
    }
};
ll A[100010], B[100010], C[100010];
ll s[100010], t[100010];
vector<lpair> tree[310];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M,L;
    cin >> N >> M >> L;
    rep(i,0,M){
        cin >> A[i] >> B[i] >> C[i];
        A[i]--; B[i]--;
        if(C[i] > L) continue;
        tree[A[i]].push_back({B[i], C[i]});
        tree[B[i]].push_back({A[i], C[i]});
    }

    ll Q;
    cin >> Q;
    vector<lpair> lp[310];
    rep(q,0,Q){
        cin >> s[q] >> t[q];
        s[q]--; t[q]--;
        lp[s[q]].push_back({t[q], q});
    }
    ll ans[100010] = {};
    rep(q,0,N){
        priority_queue<P, vector<P>, compare > pq;
        ll dist[310] = {};
        ll amari[310] = {};
        rep(i,0,N){
            amari[i] = 0;
        }
        rep(i,0,N) dist[i] = INF;
        dist[q] = 0;
        amari[q] = L;
        rep(i,0,N){
            if(i == q){
                pq.push((P){dist[i], i, amari[i]});
            }else{
                pq.push((P){dist[i], i, amari[i]});
            }
        }
        while(!pq.empty()){
            P l1 = pq.top();
            pq.pop();
            if(l1.d > dist[l1.idx]) continue;
            for(auto &e: tree[l1.idx]){
                if(l1.amari >= e.second){
                    ll d = l1.d;
                    ll ama = l1.amari - e.second;
                    if(dist[e.first] > d){
                        dist[e.first] = d;
                        amari[e.first] = ama;
                        pq.push((P){dist[e.first], e.first, amari[e.first]});
                    }else if(dist[e.first] == d){
                        if(amari[e.first] < ama){
                            amari[e.first] = ama;
                            pq.push((P){dist[e.first], e.first, amari[e.first]});
                        }
                    }
                }else{
                    ll d = l1.d + 1;
                    ll ama = L - e.second;
                    if(dist[e.first] > d){
                        dist[e.first] = d;
                        amari[e.first] = ama;
                        pq.push((P){dist[e.first], e.first, amari[e.first]});
                    }else if(dist[e.first] == d){
                        if(amari[e.first] < ama){
                            amari[e.first] = ama;
                            pq.push((P){dist[e.first], e.first, amari[e.first]});
                        }
                    }       

                }
            }
        }
        for(auto &e: lp[q]){
            if(dist[e.first] == INF){
                ans[e.second] = -1;
            }else{
                ans[e.second] = dist[e.first];
            }
        }

    }
    rep(i,0,Q) print(ans[i]);
}
