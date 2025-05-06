#include <iostream>
#include <cmath>
#include <chrono>

using namespace std;

double middle(double a, double b, int n);
double trapez(double a, double b, int n);
double gaus_2(double a, double b, int n);
double gaus_3(double a, double b, int n);
void output(double);
void input(double&, double&, int&);

int main()
{
    double a, b;
    int n;
    int choice;
    bool sd = true;
    while (sd) {
        cout << "===============MENU================" << endl;
        cout << "\n1: Middle Rectangles Method"
            << "\n2: Trapezoidal Method"
            << "\n3: Gauss 2nd Order"
            << "\n4: Gauss 3rd Order"
            << "\n0: Exit"
            << endl;
        cout << "===================================" << endl;
        cout << "Input your choice: ";
        cin >> choice;
        cout << endl;
        switch (choice) {
        case 1: {
            input(a, b, n);
            double rezult = middle(a, b, n);
            output(rezult);
            double  rezult2 = trapez(a, b, n);
            output(rezult2);
            double rezult3 = gaus_3(a, b, n);
            output(rezult3);
            double  rezult4 = gaus_2(a, b, n);
            output(rezult4);
            break;
        };
        case 2: {
            input(a, b, n);
            double  rezult = trapez(a, b, n);
            output(rezult);
            break;
        };
        case 3: {
            input(a, b, n);
            double rezult = gaus_2(a, b, n);
            output(rezult);
            break;
        };
        case 4: {
            input(a, b, n);
            double rezult = rezult = gaus_3(a, b, n);
            output(rezult);
            break;
        };
        case 0: {
            sd = false;
            break;
        }
        default: {
            cout << "Input only 1, 2, 3, 4 or 0";
            break;
        };
        }
    } 
    return 0;
}

void input(double&a, double&b, int&n) {
    cout << "Input the limits of integration and amount of attempts" << endl;
    cout << "a: ";
    cin >> a;
    cout<< "b: ";
    cin >> b;
    cout<< "n: ";
    cin >> n;
}

double f_Example(double x) {
   /* return pow(x, 3) + 5 * pow(x, 2) + 0.01 * exp(x);*/
   /* return pow(x, 3) + 20 * pow(x, 2) - sin(x);*/
   /* return pow(x, 3) - 3 * pow(x, 2);*/
    return  pow(x, 2) - 10 * cos(x);
}

double middle(double a, double b, int n) {
    auto start_time1 = std::chrono::high_resolution_clock::now();
    double h = (b - a) / n;
    double summ = 0;

    for (int i = 0; i < n; i++) {
        summ += f_Example(a + h * (i + 0.5));

    }
    auto end_time1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time1 - start_time1);
    cout << "\n\n" << duration1.count() << endl;
    return summ * h;
}

double trapez(double a, double b, int n) {
    auto start_time1 = std::chrono::high_resolution_clock::now();
    double h = (b - a) / n;
    double summ = (f_Example(a) + f_Example(b)) / 2;

    for (int i = 1; i < n; i++) {
        summ += f_Example(a+h*i);
    }
    auto end_time1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time1 - start_time1);
    cout << "\n\n" << duration1.count() << endl;
    return summ * h;
}

double gaus_2(double a, double b, int n) {
    auto start_time1 = std::chrono::high_resolution_clock::now();
    double h = (b - a) / n;
    double Xi = a + h / 2;
    double summ = 0;
    for (int i = 0; i < n; i++) {
        double Xi1 = Xi - h / 2 * 0.5773502692;
        double Xi2 = Xi + h / 2 * 0.5773502692;
        summ += f_Example(Xi1) + f_Example(Xi2);
        Xi += h;
    }
    auto end_time1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time1 - start_time1);
    cout << "\n\n" << duration1.count() << endl;
    return summ * h / 2;
}

double gaus_3(double a, double b, int n) {
    auto start_time1 = std::chrono::high_resolution_clock::now();
    double h = (b - a) / n;
    double Xi=a+h/2;
    double summ = 0;
    for (int i = 0; i < n; i++) {
        double Xi0=Xi;
        double Xi1=Xi-h/2* 0.7745966692;
        double Xi2=Xi-h/2* 0.7745966692;
        summ += f_Example(Xi1)*5/9 + f_Example(Xi0)*8/9 + f_Example(Xi2)*5/9;
        Xi += h;
    }
    auto end_time1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time1 - start_time1);
    cout << "\n\n" << duration1.count() << endl;
    return summ*h/2;
}

void output(double rez) {
    cout << "Rezult: " << rez<<endl;
}