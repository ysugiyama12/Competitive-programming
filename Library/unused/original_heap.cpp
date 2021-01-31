/*** author: yuji9511 ***/
#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
using namespace std;
using ll = long long;
using lpair = pair<ll, ll>;
using vll = vector<ll>;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
ostream& operator<<(ostream& os, lpair& h){ os << "(" << h.first << ", " << h.second << ")"; return os;}
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}
struct Heap {
private:
    ll MAX_N = 100000;
    ll sz = 0;
    vll heap;

public:
    Heap(){
        heap.resize(MAX_N);
    }

    void push(ll x){
        heap[sz] = x;
        ll cur = sz;
        while(cur > 0){
            ll par = (cur - 1) / 2;
            if(heap[par] > heap[cur]){
                swap(heap[par], heap[cur]);
            }
            cur = par;
        }
        sz++;
        printa(heap, 10);
    }

    ll top(){
        if(empty()){
            print("pq is empty");
            exit(1);
        }
        return heap[0];
    }

    bool empty(){
        return sz == 0;
    }

    void pop(){
        heap[0] = heap[sz-1];
        heap[sz-1] = 0;
        ll cur = 0;
        while(true){
            ll lv = cur * 2 + 1, rv = cur * 2 + 2;
            bool check = false;
            if(lv <= sz-2 && rv <= sz-2){
                ll v1 = heap[lv], v2 = heap[rv];
                if(v1 <= v2){
                    if(v1 < heap[cur]){
                        swap(heap[cur], heap[lv]);
                        cur = lv;
                        check = true;
                    }
                }else{
                    if(v2 < heap[cur]){
                        swap(heap[cur], heap[rv]);
                        cur = rv;
                        check = true;
                    }
                }
            }else if(lv <= sz-2){
                if(heap[lv] < heap[cur]){
                    swap(heap[cur], heap[lv]);
                    cur = lv;
                    check = true;
                }
            }else if(rv <= sz-2){
                if(heap[rv] < heap[cur]){
                    swap(heap[cur], heap[rv]);
                    cur = rv;
                    check = true;
                }            
            }

            if(not check) break;
        }
        sz--;
    }
};

void solve(){
    Heap heap;
    heap.push(0);
    heap.push(5);
    heap.push(3);
    heap.push(-2);
    heap.pop();
    print(heap.top());
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}