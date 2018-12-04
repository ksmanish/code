#include<cstdio>
#include<algorithm>
#include<utility>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<unordered_map>
#include<string>
#include<string.h>
#include<tuple>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
typedef pair<ll, ll> PL;
typedef tuple<ll, ll, ll> TL;

int main() {
    ll n;
    scanf("%lld", &n);
    if (n % 3 == 1) {
        printf("%lld 1 1", n - 2);
    }
    if (n % 3 == 2) {
        printf("%lld 2 1", n - 3);
    }
    if (n % 3 == 0) {
        printf("%lld 1 1", n - 2);
    }
}