#include <iostream>
#include <vector>
using namespace std;

typedef std::vector<std::vector<long long>> Matrix;

// 矩阵乘法
Matrix multiply(const Matrix& a, const Matrix& b) {
    int size = a.size();
    Matrix result(size, std::vector<long long>(size, 0));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < size; ++k) {
                result[i][j] += a[i][k] * b[k][j];
            }
            result[i][j] %= 10000;
        }
    }
    return result;
}

// 矩阵快速幂
Matrix matrixPower(Matrix base, long long exp) {
    Matrix result(base.size(), std::vector<long long>(base.size(), 0));
    for (int i = 0; i < base.size(); ++i) {
        result[i][i] = 1; // 初始化为单位矩阵
    }
    
    while (exp > 0) {
        if (exp % 2 == 1) { // 如果指数是奇数，则直接乘上
            result = multiply(result, base);
        }
        exp /= 2; // 指数除以2
        base = multiply(base, base); // 平方基数
    }
    return result;
}

long long fibonacci(long long n) {
    if (n <= 1) return n;
    
    Matrix base = {{1, 1}, {1, 0}};
    Matrix res = matrixPower(base, n - 1);
    return res[0][0]; // 返回F(n)
}

int main() {
    int input;
    cin >> input;
    while (input >= 0) {

        cout << fibonacci(input) << endl;

        cin >> input;
    }

    return 0;
}