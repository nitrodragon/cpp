#include "library.h"

#include <iostream>
#include <cmath>
#include <ctime>
#include <iomanip>

using std::setw;

using namespace std;

int main() {

    hello();
    numbers(43);
    randomNumberGen(10);
    arraysAndSuch();
    stringsAndCharArrays();
    pointers();
    references();
    dateTime();
    dateTimeFormatted();

    return 0;
}

void hello() {
    cout << "Hello, World! \n";
}

void numbers(int i) {
    short s = 2;
    i = -1000;
    long l = 10000000;
    float f = 257.87;
    double d = 200.543;

    // Math functions
    cout << "sin(d) :" << sin(d) << endl;
    cout << "abs(i)  :" << abs(i) << endl;
    cout << "floor(d) :" << floor(d) << endl;
    cout << "sqrt(f) :" << sqrt(f) << endl;
    cout << "pow(d, s) :" << pow(d, s) << endl;
    cout << "long var : " << l << endl;
    cout << "\n" << endl;
}

void randomNumberGen(int times) {
    int j;
    // Seeds the random
    srand( (unsigned) time(NULL));

    // Generates 'times' random numbers
    for (int i = 0; i < times; i++) {
        j = rand();
        cout << "Random Number : " << j << endl;
    }
    cout << "\n" << endl;
}

void arraysAndSuch() {
    // List is sized to fit data when initialized
    // int list[] = {1000, 30, 20, 40, 50};

    int n[10];
    for (int i = 0; i < 10; i++) {
        n[i] = i + 100; // Sets values for each in n
    }
    cout << "Element" << setw(13) << "Value" << endl;

    for (int j = 0; j < 10; ++j) {
        cout << setw(7) << j << setw(13) << n[j] << endl;
    }
    cout << "\n" << endl;
}

void stringsAndCharArrays() {
    string str = "Hello";
    string str1 = "World";
    string result;
    int len;

    result = str;
    cout << "result : " << result << endl;

    result = str + str1;
    cout << "result : " << result << endl;

    len = result.size();
    cout << "length of result : " << len << "\n" << endl;
}
void pointers() {
    int var = 20;
    int *ip;

    ip = &var;

    //Print address stored in ip variable
    cout << "Address stored in ip variable : ";
    cout << ip << endl;

    cout << "Value stored in ip variable : ";
    cout << *ip << "\n" << endl;
}
void references() {
    // simple variable declaration
    int i;
    double d;

    // reference variable declaration
    int& r = i;
    double& s = d;

    i = 5;
    cout << "Value of i : " << i << endl;
    cout << "Value of i reference : " << r  << endl;

    d = 11.7;
    cout << "Value of d : " << d << endl;
    cout << "Value of d reference : " << s  << "\n" << endl;
}
void dateTime() {
    // System-based time
    time_t now = time(0);

    // converting to string
    char* dt = ctime(&now);

    cout << "The local date and time is: " << dt << endl;

    // convert now to tm struct for UTC
    tm *gmtm = gmtime(&now);
    dt = asctime(gmtm);
    cout << "The UTC date and time is: " << dt << endl;
}

void dateTimeFormatted() {
    // System-based time
    time_t now = time(0);

    cout << "Number of seconds since 1/1/70: " << now << endl;

    tm *ltm = localtime(&now);

    //print components of time
    cout << "Year: " << 1900 + ltm -> tm_year << endl;
    cout << "Month: " << 1 + ltm -> tm_mon << endl;
    cout << "Day: " <<  ltm -> tm_mday << endl;
    cout << "Time: " << ltm -> tm_hour << ":";
    cout << ltm -> tm_min << ":";
    cout << ltm -> tm_sec << endl;
}