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
	ll n; cin >> n;
	vector<ll>v(n);
	vector<ll> prefix(n, 0);
	for (ll i = 0; i < n; i++) {
		ll sy; cin >> sy;
		if (!i) {
			prefix[i] = sy;
		} else
			prefix[i] = prefix[i - 1] + sy;
	}
	ll q; cin >> q;
	while (q--) {
		ll look, left = 0, right = n - 1, ans = -1; cin >> look;
		while (left <= right)
		{
			int middle = left + (right - left) / 2;
			if (prefix[middle] >= look)
			{
				ans = middle;
				right = middle - 1;
			}
			else
			{
				left = middle + 1;
			}
		}
		cout << ans + 1 << nline;
	}
}
int main() {
	fop_cl();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
	return 0;
}