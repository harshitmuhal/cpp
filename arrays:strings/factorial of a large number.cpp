#include<iostream>

using namespace std;

void factorial(int n){
    int fact[(int)1e5];
    fact[0] = 1;
    int l = 1;
    while (n > 1) {
        int c = 0, i = 0;
        for (; i < l; i++) {
            int value = (c + n * fact[i]);
            fact[i] = value % 10;
            c = value / 10;
        }
        while (c > 0) {
            fact[i++] = c % 10;
            l++;
            c /= 10;
        }
        n--;
    }
    for (int i = l - 1; i >= 0; i--) {
        cout << fact[i];
    }
    cout << "\n";
}
int main(){
    int n;
    cin>>n;
    factorial(n);
    return 0;
}
