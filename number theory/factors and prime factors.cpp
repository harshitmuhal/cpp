vector<int> primes;
void psieve() {
    int n = 1000001;
    int p[n];
    fill(p, p + n, 0);
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
}
vector<pair<int, int>> p_factorize (int N) {
    vector<pair<int, int>>primeFactors;
    for (int i = 0; i < primes.size(); i++) {
        int Count = 0;
        while (N % primes[i] == 0) {
            N /= primes[i];
            Count++;
        }
        if (Count) {
            primeFactors.pb({primes[i], Count});
        }
    }
    if (N != 1) {
        primeFactors.pb({N, 1});
    }
    return primeFactors;
}

void factor(vector<int> &v, int n) {
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (i * i == n) {
                v.push_back(i);
            }
            else {
                v.push_back(i);
                v.push_back(n / i);
            }
        }
    }
}
