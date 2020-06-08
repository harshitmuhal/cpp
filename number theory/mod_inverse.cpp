int mod = 998244353;
int gcdExtended(int a, int b, int *x, int *y)
{
    if (a == 0) {
        *x = 0, *y = 1;
        return b;
    }
    int x1, y1;
    int GCD = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return GCD;
}
int modInverse(int a)
{
    int x, y;
    gcdExtended(a, mod, &x, &y);
    int res = (x % mod + mod) % mod;
    return res;
}