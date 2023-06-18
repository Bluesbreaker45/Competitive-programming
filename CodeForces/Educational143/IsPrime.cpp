#include <iostream>

bool isPrime(long long num) {
    for (long long i = 2; i < num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    long long n;
    std::cin >> n;
    std::cout << isPrime(n) << std::endl;
    return 0;
}