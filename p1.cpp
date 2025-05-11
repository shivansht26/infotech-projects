#include <iostream>
using namespace std;

int main() {
   int c,f,k;
   cout<<"Enter temprature in celcius: ";
   cin>>c;
   f=(c*9/5)+32;
   cout<<"Temprature in Fahrenheit is : "<<f;
   k=c+273.15;
   cout<<"\nTemprature in Kelvin is : "<<k;
   
    return 0;
}