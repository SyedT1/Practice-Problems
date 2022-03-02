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
void gen_substr() {
	ll n, k; cin >> n >> k;
	ll i = 1, l = 0;
	for (; i <= k; i++) {
		cout << 'a';
	}
	l++;
	for (; i <= n; i++) {
		cout << char('a' + (l % 3));
		l++;
	}
	cout << nline;
}
int main() {
	fop_cl();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t; cin >> t;
	while (t--)
		gen_substr();
	return 0;
}