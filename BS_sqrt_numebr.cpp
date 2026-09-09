#include<bits/stdc++.h>
using namespace std;

double brute_BS_sqrt(double num){
    double ans;
    for (double  i = 0; i <=num; i++)
    {
        if(i*i==num){
            ans=i;
            break;
        }
    }
    return ans;   
}//t.c-O(n);s.c->O(1)


double optimal_BS_sqrt(double num){
    double ans;
    double l=0;
    double h=num-1;
    while (l<h)
    {
        double mid=l+(h-l)/2;
        if(mid*mid<=num){
            ans=mid;
            l=mid+1;
        }
        else h=mid-1;
    }
    return ans;
    
}//t.c->O(logn);s.c->O(1)

int main(){
    double num=37;
    cout<<"The number is :"<<setprecision(3)<<brute_BS_sqrt(num)<<endl;
    cout<<"The number is :"<<setprecision(3)<<optimal_BS_sqrt(num)<<endl;
    
    return 0 ;
}