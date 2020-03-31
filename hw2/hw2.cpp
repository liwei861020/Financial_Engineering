#include <iostream>
#include<cmath>
using namespace std;

int main()
{
    //Yield
    double Price, Par, Cr, yr, Y,m;
    char Pay;
    //輸入
    cout<<"Bond price(元): ";cin>>Price;
    cout<<"Par Value(元): ";cin>>Par;
    cout<<"Coupon Rate(%): ";cin>>Cr;
    Cr=Cr/100;
    cout<<"Years to Maturity(年): ";cin>>yr;
    cout<<"Payment(A,S,Q): ";cin>>Pay;
    if(Pay=='A'||Pay=='a')m=1.;else if(Pay=='S'||Pay=='s')m=2;else m=4;
    Cr=Cr/m;yr=yr*m;
    //計算
    double hi=100., lo=-0.99;
    double delta=1;
    while(delta>0.00001||delta<-0.00001){
        delta=Par*Cr*(1-pow(1+(hi+lo)/2,-floor(yr)))/((hi+lo)/2)+Par/pow(1+(hi+lo)/2,floor(yr))-Price;
        if (delta>0)lo=(hi+lo)/2;
        else hi=(hi+lo)/2;
        cout<<hi<<"\t"<<lo<<"\t"<<delta<<"\n";
    }
    cout<<lo;
    //完成Yield
    //Spot Rate

    return 0;


}
