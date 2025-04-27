//18. gcd of two number

#include <stdio.h>

int main(){
    
    int a =48, b =60;
    
    while(b != 0){
      int temp = b;
      b = a %b;
      a =temp;
    }
    printf("%d ", a);
    
    return 0;
}