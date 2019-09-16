/*** author: yuji9511 ***/
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
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i==n-1];};

struct HashData {
	int h1, h2;
	bool operator==(const HashData& rhs) const {
		return h1 == rhs.h1 && h2 == rhs.h2;
	}
	bool operator!=(const HashData& rhs) const { return !(*this == rhs); }
};

class RollingHash {
	template<int B, int M>
	class RollingHashPart {
	private:
		size_t len;
		std::vector<int> pow_b, hash;
	public:
		RollingHashPart() {}
		template<typename T>
		RollingHashPart(const T& s) : len(s.size()), pow_b(s.size() + 1), hash(s.size() + 1) {
			pow_b[0] = 1;
			hash[0] = 0;
			for (int i = 0; i < len; i++) {
				pow_b[i + 1] = (ll)pow_b[i] * B % M;
				hash[i + 1] = ((ll)hash[i] * B + s[i]) % M;
			}
		}
		// [l, r)
		int get(int l, int r) const {
			int res = (hash[r] - (ll)hash[l] * pow_b[r - l]) % M;
			if (res < 0) res += M;
			return res;
		}
	};
public:
	RollingHashPart<1033, 1000000007> rh1;
	RollingHashPart<6037, 999999937> rh2;
 
	RollingHash() {}
	template<typename T> RollingHash(const T & s) : rh1(s), rh2(s) {}
	// [l, r)
	HashData get(int l, int r) const {
		return (HashData){ rh1.get(l, r), rh2.get(l, r) };
	}
	// [l1, r1), [l2, r2)
	int lcp(const RollingHash & rhs, int l1, int r1, int l2, int r2) const {
		int lb = 0, ub = std::min(r1 - l1, r2 - l2) + 1;
		while (ub - lb > 1) {
			int md = (lb + ub) >> 1;
			(get(l1, l1 + md) == rhs.get(l2, l2 + md) ? lb : ub) = md;
		}
		return lb;
	}
};


// verify: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B&lang=jp
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string T,P;
    cin >> T >> P;
    RollingHash r1(T), r2(P);
    ll nt = T.size(), np = P.size();
    rep(i,0,nt){
        if(r1.get(i, i+np) == r2.get(0, np)){
            print(i);
        }
    }
}