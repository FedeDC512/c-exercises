// libro es427

#include <stdio.h>

void main()
//a*a+b*b=c

{
    int a, b, c;
    printf("%15s%15s%15s\n", "Cateto", "Cateto", "Ipotenusa");

    for(c=1; c<100; c++){
        for(b=1; b<100; b++){
            for(a=1; a<100; a++){
                if ((a+b>c) && ((a*a)+(b*b)==(c*c))){
                printf("%10d%10d%10d\n", a, b, c);
                }
            }
        }
    }
}