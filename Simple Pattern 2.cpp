
// Simple pattern using nested Do-while loop

#include <iostream>
using namespace std;

int main()
{   int i=5;
    do{
      int j=i ;
        do{
            cout << j ;
            j-- ;
        }while(j>=1);
      cout<<endl;
      i-- ;
    }while(i>=1);
  return 0;
}
