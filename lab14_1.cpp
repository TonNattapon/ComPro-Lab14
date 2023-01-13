#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double x[],int N, double y[])
{
    double max = x[0],min = x[0],sum,sd,sd1,am,gm,hm,sum2,sum3 = 1;
    for (int i = 0; i < N; i++)
    {
        if(x[i]>max) max=x[i];
        if(x[i]<min) min=x[i];
        sum += x[i];
        sum2 += 1/x[i];
        sum3 *= x[i];
        sd1 += pow(x[i],2);

    }
    am = sum/N;
    sd = sqrt(((1/double(N))*sd1) - pow(am,2));
    gm = pow(sum3,1/double(N));
    hm = N/sum2;
    y[0] = am;
    y[1] = sd;
    y[2] = gm;
    y[3] = hm;
    y[4] = max;
    y[5] = min;
}
