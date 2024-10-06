#include <iostream>
#include <string>
#include <cmath>
/*
summa - сумма делителей А
summb - сумма делителей B
kolvoa - количество делителей А
kolvob - количество делителей B
chetb - сумма четных делителей В (условия и пример противоречят друг другу)
necheta - произведение нечетных делителей А
nod - НОД
*/

int main(){
    setlocale(LC_ALL, "Russian");
    int a, b;
    int summa = 0, kolvoa = 0;
    int summb = 0, kolvob = 0;
    int necheta = 1, chetb = 1;
    std::cout << "Введите числа А и В\n";
    std::cin >> a >> b;
    for (int i = 1; i <= a; i++){
        if (a % i == 0){
            summa = summa + i;
            kolvoa++;
            if (i % 2 == 1){
                necheta = necheta * i;
            }
        }
    }
    for (int i = 1; i <= b; i++){
        if (b % i == 0){
            summb = summb + i;
            kolvob++;
            if (i % 2 == 0){
                chetb = chetb + i;
            }
        }
    }
    int nod;
    for (int i = a; i > 0; i--){
        if (a % i == 0 && b % i == 0){
            nod = i;
            break;
        }
    }
    

    std::cout << "[1] сумма делителей: " << summa + summb << "\n";
    std::cout << "[2]. Произведение количества делителей A и B: " << kolvoa * kolvob << "\n";
    std::cout << "[3]. Сумма произведения нечетных делителей числа А на произведение четных делителей числа В: " << necheta + chetb << "\n";
    if (nod == 1){
        std::cout << "«Числа простые вместе».";
    } else {
        std::cout << "[4] наибольший общий делитель A и B: " << nod;
    }
}
