#include <iostream>
#include <string>
#include <cmath>
/*
opt - опция
x - число для оценки функции
n - количество
last_term - последнее число
result - результат
cont - строка
*/

int main(){
    setlocale(LC_ALL, "Russian");
    double x, last_term;
    long double result=0.0;
    char cont;
    int opt, n;
    do{
        std::cout << "Выберите номер от 1 до 6:\n";
        std::cout << "[1]. Введите значение переменной «x» для оценки в функции и количество членов «n» для ряда МакЛорена.. La variable n [2, 20]\n";
        std::cout << "[2]. Рассчитать Ряд Маклорена для показательной функции (e^x):\n";
        std::cout << "[3]. Рассчитать Ряд Маклорена для функции натурального логарифма (ln (1 + x)):\n";
        std::cout << "[4]. Рассчитать Ряд Маклорена для синусоидальной функции (sin (x)):\n";
        std::cout << "[5]. Рассчитать Ряд Маклорена для функции косинуса (cos (x)):\n";
        std::cout << "[6]. Рассчитать Ряд Маклорена для рациональной функции:\n";
        std::cout << "---------------------------------------------------\n";
        std::cout << "выберите номер: \n";
        std::cin>> opt;
        switch(opt){
            case 1: 
                std::cout << "введите x: \n";
                std::cin >> x;
                std::cout << "введите n: \n";
                std::cin >> n;
                break;
            case 2:
                result = 1.0;
                last_term = 1.0;
                for(int i = 1; i <= n; i++){
                    result += last_term * x / i;
                    last_term = last_term * x / i;
                }
                std::cout << result << "\n";
                break;
            case 3:
                result = 0.0;
                for(int i = 1; i <= n; i++){
                    result += pow((-1), i + 1) * x / i;
                }
                std::cout << result << "\n";
                break;
            case 4:                
                last_term = x;
                result = last_term;
                for(int i=1; i<=n; i++){
                    last_term *= -1 * (x*x) / ((2*i+1)*(2*i));
                    result += last_term;
                }
                std::cout << result << "\n";
                break;
            case 5: 
                last_term = 1;
                result = last_term;
                for(int i=1; i<=n; i++){
                    last_term *= -1 * (x*x) / ((2*i-1)*(2*i));
                    result += last_term;
                }
                std::cout << result << "\n";
                break;
            case 6:
                while (x >= 1 || x <= -1){
                    std::cout << "значение вне домена \n";
                    std::cout << "введите x \n";
                    std::cin >> x;
                }
                result = 1;
                for(int i=1; i<=n; i++){
                    result += (i + 1) * pow(x, i);
                }
                std::cout << result << "\n";
                break;
        }
        std::cout << "хотите продолждить [Y|N]?\n";
        std::cin >> cont;            
    } while(cont == 'y' || cont == 'Y');
    std::cout << "всё!\n";
    return 0;
}