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
	ll arr[101] = {};
	set<ll>S;
	for (ll i = 0; i < n; i++) {
		ll y; cin >> y;
		S.insert(y);
		arr[y]++;
	}
	ll pair = 0;
	for (ll i : S) {
		pair += (arr[i] / 2);
	}
	return;
}
int main() {
	fop_cl();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
	return 0;
}