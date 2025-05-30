#include <iostream>

double t_line = 0.00483;//ms
double t_pix = 0.004;//ms

using namespace std;
double get_exposure_time(int line)
{
    double time = 0.0;
    time = line * t_line + t_pix;
    return time;
}

int main()
{
    cout << get_exposure_time(4070);
}