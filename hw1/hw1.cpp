#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double P,y;
    int T;
    cout<<"請輸入本金(萬元): ";
    cin>>P; P=P*10000; double P0=P;
    cout<<"請輸入期數(年): ";
    cin>>T;
    cout<<"年利率(%): ";
    cin>>y; double y0=y; y=y/100;
    int Pm[T*12],Im[T*12],RP[T*12];
    int I=0;
    for(int i=0;i<T*12-1;i++){
        Pm[i]=ceil(P/(T*12));
    }

    Pm[T*12-1]=P-(T*12-1)*Pm[0];

    for(int i=0; i<T*12;i++){
        Im[i]=round(P*y/12);
        I+=Im[i];
        P=P-Pm[i];
    }
    RP[0]=Im[0]+Pm[0];
    for(int i=1; i<T*12;i++){
            RP[i]=RP[i-1]+Pm[i]+Im[i];
    }
    cout<<"本金: "<<P0<<"元"<<"\n"
        <<"期數: "<<T<<"年"<<"\n"
        <<"年利率: "<<y0<<"%"<<"\n"
        <<"平均每月攤還本金: "<<Pm[0]<<"元"<<"\n"
        <<"全部利息: "<<I<<"\n"
        ;
    cout<<"\t"<<"本金(元) "<<"利息(元) "<<"還款(元)"<<"\n";
    for(int i=0;i<T*12;i++){

        cout<<i+1<<"\t"<<Pm[i]<<"\t"<<Im[i]<<"\t"<<RP[i]<<"\n";
    }


    return 0;
}
