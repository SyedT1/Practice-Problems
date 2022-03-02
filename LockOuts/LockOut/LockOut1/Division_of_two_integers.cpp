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
	ll n, mx = -1; cin >> n;
	vector<ll>v(n);
	vector<bool>mk(n);
	for (ll &i : v) {
		cin >> i;
		if (mx < 0) {
			mx = i;
		}
		mx = max(mx, i);
	}
	unordered_map<ll, ll>MP;
	stable_sort(v.begin(), v.end());
	for (ll i = 0; i < n; i++) {
		if (mx % v[i] == 0 && MP[v[i]] < 1) {
			mk[i] = true;
			MP[v[i]]++;
		}
	}
	for (ll i = n - 1; i >= 0; i--) {
		if (mk[i] == false) {
			cout << mx << ' ' << v[i] << nline;
			return;
		}
	}
}
int main() {
	fop_cl();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
	return 0;
}