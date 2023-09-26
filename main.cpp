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
//Minor fixes in Euclid's algorithm
// Расширенный алгоритм Евклида для нахождения обратного элемента по модулю
long long modInverse(long long num, long long mod) {
    // Сохраняем исходное значение модуля для восстановления результата
    long long original_mod = mod;

    // Инициализируем переменные для коэффициентов x0 и x1
    long long x1 = 1, x0 = 0;

    // Начинаем цикл, используя расширенный алгоритм Евклида
    while (mod) {
        // Вычисляем частное и остаток от деления num на mod
        long long quotient = num / mod;
        num %= mod;

        // Обмениваем значения num и mod для следующей итерации
        std::swap(num, mod);

        // Обновляем коэффициенты x0 и x1
        x1 -= quotient * x0;
        std::swap(x1, x0);
    }

    // Если x0 отрицательное, добавляем исходный модуль, чтобы получить положительный результат
    if (x1 < 0) {
        x1 += original_mod;
    }

    // Возвращаем модульное обратное значение
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