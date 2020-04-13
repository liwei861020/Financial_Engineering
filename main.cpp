#include <iostream>
#include<cmath>
#include<deque>
#include<iomanip>
using namespace std;
int main()
{
    double u,X,r,d,s;
    int n;
    cout<<"請輸入期數: ";cin>>n;
    cout<<"請輸入標的物現價: ";cin>>s;
    cout<<"請輸入標的物上漲比例: ";cin>>u;
    cout<<"請輸入標的物下跌比例: ";cin>>d;
    cout<<"請輸入契約定價: ";cin>>X;
    cout<<"請輸入無風險利率(%): ";cin>>r;
    double R=exp(r/100.);
    double p;p=(R-d)/(u-d);
    deque<double> S[n+1];
    S[0].push_back(s);
    for(int i=1;i<n+1;i++){
        for(int j=0;j<i;j++){
            S[i].push_back(S[i-1][j]*u);
        }
        S[i].push_back(S[i-1][i-1]*d);
    }

    deque<double> C[n+1],P[n+1];
    for(int i=0;i<S[n].size();i++){
        if(S[n][i]>X){C[n].push_back(S[n][i]-X);P[n].push_back(0);}
        else {C[n].push_back(0);P[n].push_back(X-S[n][i]);}
    }
    for (int i=n-1;i>=0;i--){
        for(int j=0;j<S[i].size();j++){
            C[i].push_back((C[i+1][j]*p+C[i+1][j+1]*(1-p))/R);
            P[i].push_back((P[i+1][j]*p+P[i+1][j+1]*(1-p))/R);
        }
    }
    cout<<"-------------------------------------------\n";
    cout<<"標的物價:"<<"\n";
    for(int i=0;i<n+1;i++){
        for(int j=0;j<S[i].size();j++){
            cout<<S[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"-------------------------------------------\n";
    cout<<"買權現值: "<<fixed<<setprecision(2)<<C[0][0]<<"\n";
    cout<<"買權價格表:"<<"\n";
    for(int i=n;i>=0;i--){
        for(int j=0;j<C[i].size();j++){
            cout<<fixed<<setprecision(2)<<C[i][j]<<"\t";
        }
        cout<<"\n";
    }
    cout<<"-------------------------------------------\n";
    cout<<"賣權現值: "<<fixed<<setprecision(2)<<P[0][0]<<"\n";
    cout<<"賣權價格表:"<<"\n";
    for(int i=n;i>=0;i--){
        for(int j=0;j<P[i].size();j++){
            cout<<fixed<<setprecision(2)<<P[i][j]<<"\t";
        }
        cout<<"\n";
    }
    return 0;
}
