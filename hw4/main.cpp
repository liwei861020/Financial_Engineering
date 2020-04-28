#include <iostream>
#include<cmath>
using namespace std;
int main()
{
    double S, sd,t,d,r,X;int nd;
    cout<<"Stock Price: ";cin>>S;
    cout<<"standard deviation: ";cin>>sd;
    cout<<"duration(month): ";cin>>t;t=t/12.;
    cout<<"number of dividends(every three months:1,4,7,....): ";cin>>nd;
    cout<<"dividend: ";cin>>d;
    cout<<"Risk-free rate(%): ";cin>>r; r=r/100.;
    cout<<"exercise price: ";cin>>X;
    //Stock price without dividends
    for(int i=0;i<nd;i++)S=S-d*exp(-r*(1.+i*3.)/12.);
    //calculate distribution and integrate it
    double d1,d2,N1,N2;
    d1=(log(S/X)+(r+0.5*pow(sd,2))*t)/(sd*sqrt(t));
    d2=d1-sd*sqrt(t);
    N1=0.5*(1+erf(-d1/(sqrt(2))));
    N2=0.5*(1+erf(-d2/(sqrt(2))));
    //計算買賣權
    double p,c;
    p=X*exp(-r*t)*N2-S*N1;
    c=p+S-X*exp(-r*t);
    cout<<"put price: "<<p<<"\n"<<"call price: "<<c;
    return 0;
}
