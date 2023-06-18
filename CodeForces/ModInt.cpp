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

    friend std::ostream& operator<<(std::ostream& os, const ModInt& num);
};
int ModInt::mod;

std::ostream& operator<<(std::ostream& os, const ModInt& num) {
    os << num.num;
    return os;
}


using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    ModInt::setMod(1000000007);
    cout << ModInt(a) * ModInt(b) << endl;
    return 0;
}