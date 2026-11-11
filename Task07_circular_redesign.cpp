#include <array>
#include <chrono>
#include <iostream>
class Shift{std::array<int,10>a{};int n=0;public:void add(int x){if(n<10)a[n++]=x;else{for(int i=1;i<10;++i)a[i-1]=a[i];a[9]=x;}}int last()const{return a[n-1];}};
class Ring{std::array<int,10>a{};int n=0,next=0;public:void add(int x){a[next]=x;next=(next+1)%10;if(n<10)++n;}int last()const{return a[(next+9)%10];}};
template<class T>double bench(T&x,int n){auto s=std::chrono::steady_clock::now();for(int i=0;i<n;++i)x.add(i);auto e=std::chrono::steady_clock::now();volatile int z=x.last();(void)z;return std::chrono::duration<double,std::milli>(e-s).count();}
int main(){Shift s;Ring r;constexpr int N=1000000;std::cout<<"Insertions: "<<N<<", capacity: 10\n"<<"Shift array ms: "<<bench(s,N)<<'\n'<<"Circular buffer ms: "<<bench(r,N)<<'\n'<<"Latest values: "<<s.last()<<' '<<r.last()<<'\n'<<"Both O(10) space; full shift O(k) per insert, ring O(1).\n";}