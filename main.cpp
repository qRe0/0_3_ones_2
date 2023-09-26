#include <iostream>

const int MOD = 1000000007;

using namespace std;

//Подсчет факториала числа n с учетом модуля MOD
long long factorial(int n) {
    // Если n равно 0 или 1, возвращаем 1
    long long result = 1;
    // Иначе вычисляем факториал при помощи цикла
    for (int i = 2; i <= n; i++) {
        result = (result * i) % MOD;
    }
    return result; // Возвращаем результат по модулю MOD
}

// Расширенный алгоритм Евклида для нахождения обратного элемента по модулю
long long modInverse(long long num, long long mod) {
    // Исходное значение mod (для восстановления результата)
    long long original_m = mod;

    // Инициализируем две переменные для коэффициентов x0 и x1
    long long x0 = 0, x1 = 1;

    while (num > 1) {
        // Вычисляем частное и остаток от деления num на mod
        long long quotient = num / mod;
        long long temp = mod;

        // Обновляем mod и num для следующей итерации
        mod = num % mod;
        num = temp;

        // Сохраняем временное значение x0 и обновляем x0 и x1
        temp = x0;
        x0 = x1 - quotient * x0;
        x1 = temp;
    }

    // Если x1 отрицательное, добавляем mod (исходный модуль) для получения положительного результата
    if (x1 < 0) {
        x1 += original_m;
    }

    return x1;
}

int main() {
    int n, k;
    cin >> n >> k;

    long long numerator = factorial(n); // Вычисляем числитель по модулю MOD (модуль определен в ф-ции factorial)
    long long denominator = (factorial(k) * factorial(n - k)) % MOD;    // Вычисляем знаменатель по модулю MOD

    long long inverse_denominator = modInverse(denominator, MOD);   // Вычисляем обратный элемент по модулю MOD, используя расширенный алгоритм Евклида

    long long answer = (numerator * inverse_denominator) % MOD; // Вычисляем ответ по модулю MOD

    cout << answer << endl;

    return 0;
}