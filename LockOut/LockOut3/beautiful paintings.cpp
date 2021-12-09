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
	vector<ll>v;
	unordered_map<ll, ll>MP;
	for (ll i = 0; i < n; i++) {
		ll y; cin >> y;
		if (!MP[y]) {
			v.push_back(y);
		}
		MP[y]++;
	}
	sort(v.begin(), v.end());
	ll count = 0, vl = v.size();
	while (true) {
		ll sum = 0;
		for (ll i = 0; i < vl; i++) {
			if (MP[v[i]] > 0) {
				sum++;
				MP[v[i]]--;
			}
		}
		if (sum == 0)
			break;
		else
			count += (sum - 1);
	}
	cout << count << nline;
}
int main() {
	fop_cl();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
	return 0;
}