
// Singly Linked List - LIFO (Last In First Out) 

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "stack.h"

int main()
{
    int i, ch;
    CStack s;

    printf("\n*****************************************************\n");
    printf("          LAST IN FIRST OUT SINGLY LINKED LIST\n");
    printf("*****************************************************\n\n");

    // magdagdag ng character mula A hangang Z 
    printf("\tAdding to linked list.\n\n\t");
    
    ch = 65;
    for (i = 0;i < 26;i++)
    {
        printf("%c", ch);

        s.Push(ch);

        ++ch;
    }
    
    // pag ito ay binawas, kabaligtaran ito ng pagkasunud-sunod ng nasa itaas
    // mula Z hangang A
    
    printf("\n\n\tRemoving from linked list.\n\n\t");
  
    while (!s.IsEmpty())
    {
        s.Pop(&ch);

        printf("%c", ch);
    }
    
    printf("\n\n-----------------------------------------------------\n\n");

    // mag-eexit agad ito kung wala nito
    printf("Press any key to exit.\n");
    ch = _getch();
}
