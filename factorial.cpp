#include <thread>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <chrono>
/*sample program 28-12-2019**/
using namespace std;

int i=7;
vector<long> sum;

class first{

    public:

    void vector_sum(){
        fstream fp;
        fp.open("fact_out.csv", ios::out | ios::app);
        long push;
        push = accumulate(sum.begin(),sum.end(),0);
        fp << push << endl;
        fp.close();
    } 

    long factorial (int a){
        long var1;

        if(a>1){
            var1 = ( a * factorial(a-1));
            return var1;
        }
       else
             return 1;
          
    }
};

int main(){
 first e;
  long out;
   for(i;i>0;i--){
       out =  e.factorial(i);
        sum.push_back(out);
   }
   e.vector_sum();

  return 0;
    
}