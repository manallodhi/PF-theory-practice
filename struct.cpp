#include <iostream>
using namespace std;

struct apply {
   int salary;
   char company[30];
};
int main()
{
   apply sum[2] = { { 23 , "Assistant" } , { 25 , "Manager" } } ;

  //  int i = 0 ;
    //while(i<=1){
        cout<<sum[1].salary << endl ;
        cout<<sum[1].company << endl ;
        cout<<endl;
     // i++ ;
   // }
  return 0 ;
}
