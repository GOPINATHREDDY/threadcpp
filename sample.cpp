#include<thread>
#include<iostream>
/*sample program 28-12-2019*/
using namespace std;

class first{
    public:
       long var1;

    int factorial (int a){
        if(a>1){
         var1=( a * factorial(a-1));
         return var1;
         }
       else
          return 1;
          
    }
};

int main(){

  first e ;
  long out;
  out = e.factorial(5);
  cout << out;
  return 0;
    
}