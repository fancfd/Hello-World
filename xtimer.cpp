#include <math.h>
#include <iostream>
#include "timer.h"
using namespace std;

int main(){

    //  Start Timers
    double wall0 = get_wall_time();
    double cpu0  = get_cpu_time();

    //  Perform some computation.
    double sum = 0;
#pragma omp parallel for reduction(+ : sum)
    for (long long i = 1; i < 10000000000; i++){
        sum += log((double)i);
    }

    //  Stop timers
    double wall1 = get_wall_time();
    double cpu1  = get_cpu_time();

    cout << "Wall Time = " << wall1 - wall0 << endl;
    cout << "CPU Time  = " << cpu1  - cpu0  << endl;

    //  Prevent Code Elimination
    cout << endl;
    cout << "Sum = " << sum << endl;

}
