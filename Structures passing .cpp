#include <iostream>
using namespace std;

struct Office_data {
   char name[30];
   int age;
   char job[30];
};
int main()
{
   Office_data D[4] = { {"Ayesha" , 23 , "Assistant" } , {"Bakhtawar" , 25 , "Manager" } ,
                        {"Manal" , 24 , "CEO"} , {"Namra" , 25 , "Intern"} } ;

    int i = 0 ;
    while(i<=3){
        cout<<D[i].name << endl ;
        cout<<D[i].age << endl ;
        cout<<D[i].job << endl ;
        cout<<endl;
      i++ ;
    }
  return 0 ;
}
