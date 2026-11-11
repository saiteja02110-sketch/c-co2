#include <array>
#include <iomanip>
#include <iostream>
class SavingsAccount{long long number,balance;std::array<long long,10> tx{};int count=0,next=0;void record(long long x){tx[next]=x;next=(next+1)%10;if(count<10)++count;}
public:SavingsAccount(long long n,long long b):number(n),balance(b){}void deposit(long long x){if(x>0){balance+=x;record(x);}}bool withdraw(long long x);void miniStatement()const;};
bool SavingsAccount::withdraw(long long x){if(x<=0||x>balance)return false;balance-=x;record(-x);return true;}
void SavingsAccount::miniStatement()const{std::cout<<"Mini statement account "<<number<<'\n';int first=count==10?next:0;for(int i=0;i<count;++i){auto x=tx[(first+i)%10];std::cout<<(x>=0?"Credit ":"Debit  ")<<std::fixed<<std::setprecision(2)<<(x>=0?x:-x)/100.0<<'\n';}std::cout<<"Balance Rs "<<balance/100.0<<'\n';}
int main(){SavingsAccount a(20261001,500000);a.deposit(25000);a.withdraw(10000);for(int i=1;i<=10;++i)a.deposit(i*100);a.miniStatement();}