
#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>
#include<cmath>
#include<algorithm>
#define nline '\n'
using namespace std;
using ll = long long int;
void focl() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}
vector<char>sieve(ll(1e5 + 1), true);
int main() {
	focl();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<ll>primes;
	ll SQ = sqrt(1e5) + 1;
	sieve[0] = sieve[1] = false;
	for (ll i = 2; i <= SQ; i++) {
		if (sieve[i]) {
			for (ll j = i * i; j <= ll(1e5); j += i)
				sieve[j] = false;
		}
	}
	for (ll i = 2; i <= 1e5; i++) {
		if (sieve[i])
			primes.push_back(i);
	}
	ll q; cin >> q;
	while (q--) {
		ll d; cin >> d;
		//	cout << 1 << ' ';
		vector<ll>p;
		p.push_back(1);
		for (ll i = 1; i <= 2; i++) {
			ll left = 0, right = primes.size() - 1, ind = -1;
			while (left <= right) {
				ll mid = left + (right - left) / 2;
				if (primes[mid] >= p.back() + d) {
					right = mid - 1;
					ind = mid;
				} else
					left = mid + 1;
			}
			//	cout << primes[ind] << ' ';
			p.push_back(primes[ind]);
		}
		cout << p[2]*p[1] << nline;
	}
}