#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<long long int, long long int>> p, o;
    long long int ans = 0;
    for (int i = 0; i < n; i++) {
        int x, t;
        cin >> x >> t;
        if (x < 0) o.push_back({x, t});
        else p.push_back({x, t});
    }
    sort(p.begin(), p.end());
    sort(o.begin(), o.end(), greater<>());
    if (p.size() != 0) {
        ans += p[0].first;
    }
    int ip = 0;
    int io = 0;
    while ((p.size() != ip) and (o.size() != io)) {
        cout << ip << ' ' << io  << ' ' << ans << '\n';
        if (p[ip].second <= o[io].second) {
            ans += (((p[ip].first - o[io].first) % 998244353) * (p[ip].second % 998244353)) % 998244353;
            ans %= 998244353;
            o[io].second -= p[ip].second;
            ip++;
        }
        else {
            cout << p[ip].first << ' ' << o[io].first << '\n';
            ans += (((p[ip].first - o[io].first) % 998244353) * (o[io].second % 998244353)) % 998244353;
            ans %= 998244353;
            p[ip].second -= o[io].second;
            io++;
        }
    }
    cout << ans;

}