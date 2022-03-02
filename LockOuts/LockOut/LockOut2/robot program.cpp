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
	ll mn, mx; cin >> mn >> mx;
	if (mn > mx)
		swap(mn, mx);
	if (mn == 0 && mx == 0) {
		cout << 0 << nline;
		return;
	}
	cout << 2 * mn + (mx - mn) + (mx - mn - 1 > 0 ? mx - mn - 1 : 0) << nline;
}
int main() {
	fop_cl();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t; cin >> t;
	while (t--)
		solve();
}