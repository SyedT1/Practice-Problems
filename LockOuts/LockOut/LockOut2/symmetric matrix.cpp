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
	ll n, m; cin >> n >> m;
	string out[] = {"NO", "YES"};
	ll counter = 0;
//	cout << "For n = " << n << nline;
	while (n--) {
		ll arr[2][2];
		for (ll i = 0; i < 2; i++)
			for (ll j = 0; j < 2; j++)
				cin >> arr[i][j];
		counter += (arr[0][1] == arr[1][0]);
	}
	cout << out[counter > 0 && m % 2 == 0] << nline;
}
int main() {
	fop_cl();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t; cin >> t;
	while (t--)
		solve();
	return 0;
}