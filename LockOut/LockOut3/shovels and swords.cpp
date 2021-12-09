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
ll solve(ll a, ll b) {
	ll sum = 0;
	while ((a > 0 && b > 0) && !(a == 1 && b == 1)) {
		if (a > b) {
			a -= 2;
			b -= 1;
		} else {
			a -= 1;
			b -= 2;
		}
		cout << a << ' ' << b << nline;
		sum++;
	}
	return sum;
}
ll sol(ll a, ll b) {
	ll sum = 0;
	while ((a > 0 && b > 0) && !(a == 1 && b == 1)) {
		if (a > b) {
			swap(a, b);
		}
		if (2 * a <= b) {
			cout << sum + a << nline;
			return sum + a;
		}
	}
	return sum;
}
void so() {
	ll a, b; cin >> a >> b;
	cout << solve(a, b) << nline; // << ' ' << sol(a, b) << nline;
}
int main() {
	fop_cl();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t; cin >> t;
	while (t--)
		so();
	return 0;
}