#include <iostream>
#include<cmath>
#include<deque>
#include<stdio.h>
#include<iomanip>
using namespace std;
double spot_rate(double x,double y,double z){
    return pow(y/x,1/z)-1;
}
int main()
{
    //輸入
    deque<double> Price;
    deque<double> Par;
    deque<double> t;
    double n;
    //輸入
    cout<<"請輸入一組債券市價: ";
    while(cin>>n){
        Price.push_back(n);
        char ch= getchar();
        if(ch=='\n')break;
    }
    cout<<"請輸入對應面額: ";
     while(cin>>n){
        Par.push_back(n);
        char ch= getchar();
        if(ch=='\n')break;
    }
    cout<<"請輸入對應期長: ";
     while(cin>>n){
        t.push_back(n);
        char ch= getchar();
        if(ch=='\n')break;
    }
    deque<double> Spot;
    for(int i=0;i<Price.size();i++){
        Spot[i]=spot_rate(Price[i],Par[i],t[i]);
        cout<<"S"<<i+1<<"="<<Spot[i]<<"\t";
    }
    //做遠端利率
    double fr[Price.size()][Price.size()] ;
    for(int i=0;i<Price.size();i++){
        for(int j =i+1;j<Price.size();j++){
            fr[i][j]=pow(pow(1+Spot[j],j+1)/pow(1+Spot[i],i+1),1./(j-i))-1;
        }
    }
    cout<<"\n"<<"\t";
    for(int i=0;i<Price.size();i++)cout<<"第"<<i+1<<"期\t";
    cout<<"\n";
    for(int i=0;i<Price.size();i++){
        for(int j=0;j<=Price.size();j++){
            if(j==0)cout<<"第"<<i+1<<"期"<<"\t";
            else if(j<=i)cout<<"X"<<"\t";
            else if(j-1==i)cout<<0<<"\t";
            else cout<<fixed<<setprecision(4)<<fr[i][j-1]<<"\t";
        }
        cout<<"\n";
    }
    return 0;
}
