#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;
template<class T> bool chmin(T& a,T b){if(a>b) {a = b; return true;} return false;}
template<class T> bool chmax(T& a,T b){if(a<b) {a = b; return true;} return false;}
#define rep(i,n) for(int i=0;i<(n);i++)
#define drep(i,n) for(int i=(n)-1;i>=0;i--)
#define all(x) (x).begin(),(x).end()
#define debug(x)  cerr << #x << " = " << (x) << endl;

constexpr ll inf = 1e18;

template<class T,int MAX_LOG>
class BinaryTrie{
private:
    BinaryTrie *ne[2];
    T lazy;
    ll val;
    int child_num;
    bool fill;
    vec<int> accept;

    void insert(const T &bit,int bit_id,int id,ll x){
//        cerr << bit_id << " " << bit << " " << x << "\n";
        propagate(bit_id);
        if(bit_id==-1){
            child_num++;
            accept.push_back(id);
        }else{
            auto &to = ne[(bit>>bit_id)&1];
            if(!to) to = new BinaryTrie();
            to -> insert(bit,bit_id-1,id,x);
            child_num++;
            chmax(val,x);
            if(ne[0]) chmax(val,ne[0]->val);
            if(ne[1]) chmax(val,ne[1]->val);
        }
    }

    void insert(const T &bit,int id,ll x){
        insert(bit,MAX_LOG,id,x);
    }

    void erase(const T &bit,int bit_id){
        propagate(bit_id);
        if(bit_id==-1){
            child_num--;
        }else{
            assert(ne[(bit>>bit_id)&1]);
            ne[(bit>>bit_id)&1]->erase(bit,bit_id-1);
            child_num--;
        }
    }

    pair<T,BinaryTrie*> max_element(const T& x,int bit_id){
        propagate(bit_id);
        if(bit_id==-1) return {0,this};
        bool f = (x>>bit_id)&1;
        f ^= 1;
        f ^= !(ne[f] && ne[f]->size());
        auto res = ne[f]->max_element(x,bit_id-1);
        res.first |= T(f)<<bit_id;
        return res;
    }

    pair<T,BinaryTrie*> min_element(const T &x,int bit_id){
        propagate(bit_id);
        if(bit_id==-1) return {0,this};
        bool f = (x>>bit_id)&1;
        f ^= !(ne[f] && ne[f]->size());
        auto res = ne[f]->min_element(x,bit_id-1);
        res.first |= T(f)<<bit_id;
        return res;
    }

    pair<T,BinaryTrie*> kth_element(ll k,int bit_id){
        propagate(bit_id);
        if(bit_id==-1) return {0,this};
        ll small = (ne[0]? ne[0]->size():0);
        if(small<k){
            auto res = ne[1]->kth_element(k-small,bit_id-1);
            res.first |= T(1)<<bit_id;
            return res;
        }else{
            return ne[0]->kth_element(k,bit_id-1);
        }
    }

public:
    BinaryTrie():child_num(0),lazy(0),val(-inf),ne{nullptr,nullptr}{}

    void insert(const T &bit,ll x){
        insert(bit,child_num,x);
    }

    void erase(const T &bit){
        erase(bit,MAX_LOG);
    }

    T max_element(const T x=0){
        assert(child_num);
        return max_element(x,MAX_LOG).first;
    }

    T min_element(const T x=0){
        assert(child_num);
        return min_element(x,MAX_LOG).first;
    }

    //k is 1-indexed
    T kth_element(ll k){
        assert(0<k && k<=size());
        return kth_element(k,MAX_LOG).first;
    }

    int size() const{
        return child_num;
    }

    void search(T bit,int bit_id,ll &ma){
        if(bit_id==-1) return ;
        propagate(bit_id);
        if(bit_id==0){
            if(!(bit>>bit_id&1)) chmax(ma,val);
        }
        if(bit>>bit_id&1){
            if(ne[0]) chmax(ma,ne[0]->val);
            if(ne[1]) ne[1]->search(bit,bit_id-1,ma);
        }else{
            if(ne[0]) ne[0]->search(bit,bit_id-1,ma);
        }
    }

    void search(T bit,ll &ma){
        search(bit,MAX_LOG,ma);
    }

    void xorpush(const T &bit){
        lazy ^= bit;
    }

    void propagate(int bit_id){
        if((lazy>>bit_id)&1) swap(ne[0],ne[1]);
        if(ne[0]) ne[0]->lazy ^= lazy;
        if(ne[1]) ne[1]->lazy ^= lazy;
        lazy = 0;
    }
    
};



int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,M;
    cin >> N >> M;
    vec<int> A(N),B(N);
    rep(i,N) cin >> A[i];
    rep(i,N) cin >> B[i];
    int n = N/2;
    int n2 = N-n;
    vec<ll> table(1<<n,-inf);
    ll ans = -inf;
    rep(S,1<<n){
        ll b = 0;
        int x = 0;
        rep(i,n) if(S>>i&1) b += B[i],x ^= A[i];
        chmax(table[x],b);
        if(x<=M) chmax(ans,b);
    }
    BinaryTrie<ll,60> trie;
    rep(i,1<<n){
        trie.insert(i,table[i]);
    }
    rep(S,1<<n2){
        ll b = 0;
        int x = 0;
        rep(i,n2) if(S>>i&1) b += B[n+i],x ^= A[n+i];
        if(x<=M) chmax(ans,b);
        ll ma = -inf;
        trie.xorpush(x);
        trie.search(M,ma);
//        cerr << S << " " << b << " " << ma << " " << x << "\n";
        chmax(ans,b+ma);
        trie.xorpush(x);
    }
    cout << ans << "\n";
}