#include <iostream>
#include <string>
#include <cmath>
/*
opt - �����
x - ����� ��� ������ �������
n - ����������
last_term - ��������� �����
result - ���������
cont - ������
*/

int main(){
    setlocale(LC_ALL, "Russian");
    double x, last_term;
    long double result=0.0;
    char cont;
    int opt, n;
    do{
        std::cout << "�������� ����� �� 1 �� 6:\n";
        std::cout << "[1]. ������� �������� ���������� �x� ��� ������ � ������� � ���������� ������ �n� ��� ���� ���������.. La variable n [2, 20]\n";
        std::cout << "[2]. ���������� ��� ��������� ��� ������������� ������� (e^x):\n";
        std::cout << "[3]. ���������� ��� ��������� ��� ������� ������������ ��������� (ln (1 + x)):\n";
        std::cout << "[4]. ���������� ��� ��������� ��� �������������� ������� (sin (x)):\n";
        std::cout << "[5]. ���������� ��� ��������� ��� ������� �������� (cos (x)):\n";
        std::cout << "[6]. ���������� ��� ��������� ��� ������������ �������:\n";
        std::cout << "---------------------------------------------------\n";
        std::cout << "�������� �����: \n";
        std::cin>> opt;
        switch(opt){
            case 1: 
                std::cout << "������� x: \n";
                std::cin >> x;
                std::cout << "������� n: \n";
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
                    std::cout << "�������� ��� ������ \n";
                    std::cout << "������� x \n";
                    std::cin >> x;
                }
                result = 1;
                for(int i=1; i<=n; i++){
                    result += (i + 1) * pow(x, i);
                }
                std::cout << result << "\n";
                break;
        }
        std::cout << "������ ����������� [Y|N]?\n";
        std::cin >> cont;            
    } while(cont == 'y' || cont == 'Y');
    std::cout << "��!\n";
    return 0;
}