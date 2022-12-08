#include <iostream>
#include <cmath>
using namespace std;

int gcd(int x, int y) // проверка взаимно простые ли числа
{
    return y ? gcd(y,x % y) : x;
}

int random(int a,int b) // рандомное число, генерация s
{
    srand(time(NULL));
    if (a > 0) return a + rand() % (b - a);
    else return a + rand() % (abs(a) + b);
}


long int power (long int s, long int e, int n) {
    if (e == 0) {
        return 1; // возводим число в 0 степень, получим всегда единицу
    }
    else return (s * s) % n; // возводим число v = s * s mod n в первую степень, не изменяется число
}

bool basicStages(long int s, long int n) {
    long int r = random(0, n - 1);
    long int x = (r * r) % n;
    cout<<"x: " << x << endl;

    cout << "A отсылает доказательство B: "<< endl;
    int e = random(0,2); // B выбирает бит e = 0 or 1
    cout <<"B выбирает е: " << e << " и отсылает его А (вызов)" << endl;
    long int y = 0;

    if (e == 0) y = r;
    else if (e == 1) y = (r * s) % n;
    cout << "А вычисляет у: " << y << " и отправляет его В" << endl;

    long int y_2 = (y * y) % n ;
    long int check = (x * power(s, e,n)) % n;
    cout << "y^2: " << y_2 << endl;
    cout << "x * v^e: " << check << endl;
    if (y_2 == check) return true;

    return false;
}

int generatePrime(int min) {
    srand(time(NULL));
    int number;
    bool flag = true;
    while(flag) {
        flag = false;
        number = min + rand() % 1000;
        for(int i = 2; i < number/2; i++) {
          if(number % i == 0) flag = true;

      }
    }
    //cout << number;
    return number;
}

int main() {
    long int p = generatePrime(0);
    cout << "simple p: " << p << endl;


    long int q = generatePrime(1);
    cout << "simple q: " << q << endl;

    long int n = p * q;
    cout << "n: " << n << endl;


    long int s;
    long int chek = 0;

    while (chek != 1) {
        s = random(0, (n - 1)); // объявляем s
        chek = gcd (s, n); // оно должно быть взаимно простым с n
    }

    cout << "s: " << s << endl;
    long int v = (s * s) % n; // открытый ключ А
    cout << "v: " << v << endl;

    int t;
    cout << "Введите количество t - раундов: ";
    cin >> t;
    for (int i = 1; i <= t; i ++) {
        if(basicStages(s, n)) {
            cout << "Раунд " << + i << "-ый пройден успешно" << endl;
        }
    }

    return 0;
}
