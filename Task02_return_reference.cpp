#include <iostream>
#include <vector>
int& highest(int a[],int n){int k=0;for(int i=1;i<n;++i)if(a[i]>a[k])k=i;return a[k];}
const int& highestConst(const int a[],int n){int k=0;for(int i=1;i<n;++i)if(a[i]>a[k])k=i;return a[k];}
int highestCopy(const int a[],int n){int k=0;for(int i=1;i<n;++i)if(a[i]>a[k])k=i;return a[k];}
int main(){int m[]={78,92,85,88};highest(m,4)+=2;std::cout<<"Moderated highest mark: "<<highest(m,4)<<'\n';std::cout<<"Const reference: "<<highestConst(m,4)<<", copy: "<<highestCopy(m,4)<<'\n';std::vector<int> v={10,20,30};v.reserve(100);std::cout<<"Vector size after reserve: "<<v.size()<<"; reacquire references after growth\n";}