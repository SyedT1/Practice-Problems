#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <queue>
#define nline '\n'
#define len(s) ll((s).size())
#define pb push_back
#define pp pop_back
#define loop(x, n) for(int x = 0; x < n; ++ x)
using namespace std;
using ll = long long int;
using par = pair<ll, ll>;

template <typename T>
ostream &operator<<(ostream &out, pair<T, T>p) {
	out << p.first << ' ' << p.second;
	return out;
}
template <typename T>
ostream &operator<<(ostream &out, vector<T> v)
{
	for (T i : v)
	{
		out << i << ' ';
	}
	return out;
}
istream &operator>>(istream &in, vector<ll> &v)
{
	for (ll &i : v)
	{
		cin >> i;
	}
	return in;
}
void fop_cl()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}
void solve() {
	ll n; cin >> n;
	string s; cin >> s;
	set<ll>tA, tA_;
	priority_queue<ll>M;
	queue<ll>Q;
	for (ll i = 0; i < n; i++) {
		if (s[i] == 'M') {
			M.push(i + 1);
			Q.push(i + 1);
		} else {
			tA.insert(i + 1);
		}
	}
	tA_ = tA;
	while (!M.empty()) {
		set<ll>::iterator it = tA.lower_bound(M.top()), lt = tA.upper_bound(M.top());
		if (it != tA.begin() && lt != tA.end()) {
			it--;
			tA.erase(it);
			tA.erase(lt);
		}
		M.pop();
	}
	while (!Q.empty()) {
		set<ll>::iterator it = tA_.lower_bound(Q.front()), lt = tA_.upper_bound(Q.front());
		if (it != tA_.begin() && lt != tA_.end()) {
			it--;
			tA_.erase(it);
			tA_.erase(lt);
		}
		Q.pop();
	}
	cout << (tA.size() == 0  || tA_.size() == 0 ? "YES" : "NO") << nline;
}
int main()
{
	fop_cl();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}