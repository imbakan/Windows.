
// program na pang-sort ng data

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
//#include <sysinfoapi.h>

int main()
{
    const int n = 20;
    int ch, seed, i, j, x, data[n], index[n];
    
    seed = 123456789;
    srand(seed);

    // Gumawa ng random data. Ito ay array ng integer.
    for (i = 0;i < n;i++)
        data[i] = rand();

    // I-sort ang mga data na ginawa.
    // Hindi natin babaguhin ang mismong data.
    // Gagawa tayo ng array ng index at ito ang ating babaguhin.
    for (i = 0;i < n;i++)
		index[i] = i;

    for (i = 0;i < (n-1);i++)
    {
        for (j = (i + 1);j < n;j++)
        {
            if (data[index[i]] > data[index[j]])
            {
                x = index[i];
                index[i] = index[j];
                index[j] = x;
            }
        }
    }

    // i-output sa screen
    printf("\nAng mga sumusunod ay ang mga data na isosort.\n\n");

    for (i = 0;i < n;i++)
        printf("%10d\n", data[i]);
    
    printf("\nAng mga sumusunod ay ang mga data na nasort na.\n\n");

    for (i = 0;i < n;i++)
        printf("%10d\n", data[index[i]]);

    // para de mag-exit agad.
    printf("\nPress any key to exit.\n");
    ch = _getch();
}
