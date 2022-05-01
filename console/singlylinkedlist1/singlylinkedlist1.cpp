
// Singly Linked List - FIFO (First In First Out) 

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "queue.h"

int main()
{
    int i, ch;
    CQueue q;

    printf("\n*****************************************************\n");
    printf("         FIRST IN FIRST OUT SINGLY LINKED LIST\n");
    printf("*****************************************************\n\n");

    // magdagdag ng character mula A hangang Z 
    printf("\tAdding to linked list.\n\n\t");
    
    ch = 65;
    for (i = 0;i < 26;i++)
    {
        printf("%c", ch);

        q.Add(ch);

        ++ch;
    }
    
    // pag ito ay binawas, katulad din ito ng pagkasunud-sunod ng nasa itaas
    // mula A hangang Z
    
    printf("\n\n\tRemoving from linked list.\n\n\t");
  
    while (!q.IsEmpty())
    {
        q.Remove(&ch);

        printf("%c", ch);
    }
    
    printf("\n\n-----------------------------------------------------\n\n");

    // mag-eexit agad ito kung wala nito
    printf("Press any key to exit.\n");
    ch = _getch();
}
