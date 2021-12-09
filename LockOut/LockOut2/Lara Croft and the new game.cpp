
#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<set>
#include<unordered_map>
#define nline '\n'
using namespace std;
using ll = long long int;
using par = pair<ll, ll>;
void fop_cl() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}
void solve() {
	ll r, c, k; cin >> r >> c >> k;
	if (k < r) {
		cout << 1 + k << ' ' << 1 << nline;
		return;
	}
	if (r * c - 1 == k) {
		cout << 1 << ' ' << 2 << nline;
		return;
	}
	ll rw_num = r - ( ((k - r) / (c - 1)) + 1 );
	//cout << rw_num + 1 << nline;
	ll col_mx = (r * c - 1) - (rw_num * (c - 1));
	cout << rw_num + 1 << ' ' <<  (rw_num % 2 == 0 ? (col_mx - k) + 2 : c - (col_mx - k));
}
int main() {
	fop_cl();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
	return 0;
}
