#include <chrono>
#include <iostream>
class Time{int h,m;public:Time(int hh,int mm):h(hh),m(mm){}friend int minutesBetween(const Time&,const Time&);friend bool earlier(const Time&,const Time&);};
int minutesBetween(const Time&a,const Time&b){int x=a.h*60+a.m,y=b.h*60+b.m;return x>y?x-y:y-x;}
bool earlier(const Time&a,const Time&b){return a.h<b.h||(a.h==b.h&&a.m<b.m);}
int main(){Time d(9,45),a(13,10);std::cout<<minutesBetween(d,a)<<' '<<std::boolalpha<<earlier(a,d)<<'\n';Time x(12,0),y(12,0),n(11,55),p(12,5);std::cout<<"same time difference="<<minutesBetween(x,y)<<'\n'<<"cross noon difference="<<minutesBetween(n,p)<<", earlier="<<earlier(n,p)<<'\n';volatile int sum=0;auto s=std::chrono::steady_clock::now();for(int i=0;i<10000000;++i)sum+=minutesBetween(d,a);auto e=std::chrono::steady_clock::now();std::cout<<"10M calls ms="<<std::chrono::duration<double,std::milli>(e-s).count()<<" checksum="<<sum<<'\n';}