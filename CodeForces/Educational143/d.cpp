#include <iostream>

class ModInt {
   private: 
    int num;
    static int mod;
    static long long binpow(long long a, long long b, long long m) {
        a %= m;
        long long res = 1;
        while (b > 0) {
            if (b & 1) res = res * a % m;
            a = a * a % m;
            b >>= 1;
        }
        return res;
    }

   public:
    ModInt(int num): num(num % mod) {};

    static void setMod(int m) {
        mod = m;
    }

    ModInt operator+(const ModInt& other) const {
        return ModInt((num + other.num) % mod);
    }

    ModInt operator*(const ModInt& other) const {
        int ans = ((long long)num * other.num) % mod;
        return ModInt(ans);
    }

    ModInt operator-(const ModInt& other) const {
        int ans = (num - other.num) % mod;
        if (ans < 0) ans += mod;
        return ModInt(ans);
    }

    ModInt operator/(const ModInt& other) const {
        int inverse = binpow(other.num, mod - 2, mod);
        return ModInt(num) * ModInt(inverse);
    }

    bool operator==(const ModInt& other) const {
        return num == other.num;
    }

    friend std::ostream& operator<<(std::ostream& os, const ModInt& num);
};
int ModInt::mod; // DO NOT FORGET THIS DEFINITION!!!

std::ostream& operator<<(std::ostream& os, const ModInt& num) {
    os << num.num;
    return os;
}

ModInt fact(ModInt n) {
    if (n == 0) {
        return 1;
    }
    return n * fact(n - 1);
}

#include <algorithm>
using namespace std;

int main() {
    ModInt::setMod(998244353);

    int n;
    cin >> n;

    int e[300001];
    for (int i = 0; i < n; i++) {
        cin >> e[i];
    }

    ModInt res(1);
    for (int i = 0; i < n; i += 3) {
        int* p = e + i;
        sort(p, p + 3);
        int a = p[0];
        int b = p[1];
        int c = p[2];
        if (a == b && a == c) {
            res = res * 3;
        } else if (a == b && b < c) {
            res = res * 2;
        }
    }

    res = res * fact(n/3);
    res = res / fact(n/6);
    res = res / fact(n/6);

    cout << res << endl;

    return 0;
}