#include <iostream>
struct Parcel{double kg;bool express=false;bool insured=false;};
double charge(double kg,bool express=false,bool insured=false){double x=kg*40;if(express)x+=50;if(insured)x+=20;return x;}
double charge(int grams){return charge(static_cast<double>(grams)/1000.0);}
double charge(const Parcel&p){return charge(p.kg,p.express,p.insured);}
int main(){Parcel p{2.0,true,false};std::cout<<"charge(2) [int grams] = "<<charge(2)<<'\n'<<"charge(2.0) [double kg] = "<<charge(2.0)<<'\n'<<"charge(2.0f) [float promotion] = "<<charge(2.0f)<<'\n'<<"charge(2.0,true) = "<<charge(2.0,true)<<'\n'<<"charge(2.0,true,true) = "<<charge(2.0,true,true)<<'\n'<<"charge(Parcel) = "<<charge(p)<<'\n';}