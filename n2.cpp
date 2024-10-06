#include <iostream>
#include <string>
#include <cmath>
#include <cstdint>
/*
opt - опция
cont - строка
kolvo - количество цифр
n - число
sum - сумма цифр
pr - произведение нечетных цифр.
str - для преревернутой версии числа
*/

int main(){
    int opt;
    char cont;
    do{
        std::cout << "Select an option from [1-8] according to the menu:\n";
        std::cout << "[1]. Enter a number in the range between 1000 and 999999\n";
        std::cout << "[2]. Print the digits of the number\n";
        std::cout << "[3]. Count how many digits the number has\n";
        std::cout << "[4]. Return the lowest and highest digits of the number\n";
        std::cout << "[5]. Return the sum of the digits of the number\n";
        std::cout << "[6]. Return the product of the odd digits\n";
        std::cout << "[7]. Calculate the inverted version of the number\n";
        std::cout << "---------------------------------------------------\n";
        std::cout << "Enter option: \n";
        std::cin>> opt;
        uint32_t n;
        int kolvo = 0;
        unsigned int max = 0, min = 9;
        int sum = 0;
        int pr = 1;
        std::string str;
        switch(opt){
            case 1: 
                 do{
                    std::cout << "Enter number: \n";
                    std::cin >> n;
                    if (n < 1000 || n > 999999999)
                    {
                        std::cout << "wrong number\n";
                    }
                    
                 } while (n < 1000 || n > 999999999);

                break;
            case 2:
                do{
                    std::cout << n % 10 << " ";
                    n = n / 10;
                }while (n % 10 > 0 || n / 10 > 0);
                std::cout << "\n";
                break;
            case 3:
                do{
                    kolvo++;
                    n = n / 10;
                }while (n % 10 > 0 || n / 10 > 0);
                std::cout << kolvo << "\n";
                break;
            case 4:
                do{
                    if (n % 10 > max){
                        max = n % 10;
                    }
                    if (n % 10 < min){
                        min = n % 10;
                    }
                    n = n / 10;
                }while (n % 10 > 0 || n / 10 > 0);
                std::cout << "max = " << max << ", min = " << min << "\n";
                break;
            case 5:
                do{
                    sum += n % 10;
                    n = n / 10;
                }while (n % 10 > 0 || n / 10 > 0);
                std::cout << sum << "\n";
                break;
            case 6:
                do{
                    if ((n % 10) % 2 == 1){
                        pr *= n % 10;
                    }
                    n = n / 10;
                }while (n % 10 > 0 || n / 10 > 0);
                std::cout << pr << "\n";
                break;
            case 7:
                do{
                    str = str + std::to_string(n % 10);
                    n = n / 10;
                }while (n % 10 > 0 || n / 10 > 0);
                std::cout << str << "\n";
                break;
        }
        std::cout << "Do you want continue [Y|N]?\n";
        std::cin >> cont;
    }while(cont == 'y' || cont == 'Y');
    std::cout << "The program is over!\n";
    return 0;
}
