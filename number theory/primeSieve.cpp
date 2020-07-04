#include <iostream>
using namespace std;
vector<int> psieve() {
    vector<int> primes;
    int p[1000001] = {0};
    p[0] = p[1] = 0;
    p[2] = 1;
    for (int i = 3; i <= n; i += 2) {
        p[i] = 1;
    }
    primes.push_back(2);
    for (int i = 3; i <= n; i += 2) {
        if (p[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= n; j += 2 * i) {
                p[j] = 0;
            }
        }
    }
    return primes;
}
int main() {

    int t;
    cin >> t;
    primeSieve(p, t);
    return 0;
}