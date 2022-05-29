//
// Pag-compute ng inverse trigonometric function gamit ang power series.
// 

#define _USE_MATH_DEFINES // para M_PI

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

#define ULC 0xc9
#define URC 0xbb
#define LLC 0xc8
#define LRC 0xbc

#define VER1 0xf5

#define HOR2 0xcd
#define VER2 0xba

#define LFD 0xcc
#define RTD 0xb9

#define CRS 0xd8

#define UPD 0xd1
#define LOD 0xcf

double arcsine(double x);
double arctan(double x);

int main()
{
    int i, ch, n;
    double x, c, s, t, d;

    printf("\n%62s\n\n", "INVERSE TRIGONOMETRIC FUNCTIONS");

    // upper border
    printf("%10c", ULC);
    for (i = 0;i < 7;i++)
        printf("%c", HOR2);
    printf("%c", UPD);
    for (i = 0;i < 22;i++)
        printf("%c", HOR2);
    printf("%c", UPD);
    for (i = 0;i < 22;i++)
        printf("%c", HOR2);
    printf("%c", UPD);
    for (i = 0;i < 22;i++)
        printf("%c", HOR2);
    printf("%c\n", URC);

    // header
    printf("%10c", VER2);
    printf("%3c%-2s", ' ', "x");
    printf("%3c", VER1);
    printf("%3c%-17s", ' ', "Arccos(x)");
    printf("%3c", VER1);
    printf("%3c%-17s", ' ', "Arcsin(x)");
    printf("%3c", VER1);
    printf("%3c%-17s", ' ', "Arctan(x)");
    printf("%3c\n", VER2);

    // divider
    printf("%10c", LFD);
    for (i = 0;i < 7;i++)
        printf("%c", HOR2);
    printf("%c", CRS);
    for (i = 0;i < 22;i++)
        printf("%c", HOR2);
    printf("%c", CRS);
    for (i = 0;i < 22;i++)
        printf("%c", HOR2);
    printf("%c", CRS);
    for (i = 0;i < 22;i++)
        printf("%c", HOR2);
    printf("%c\n", RTD);

    // cell
    x = 0.0;
    n = 1000;
    d = 1.0 / (double) n;

    for (i = 0;i < n;i++)
    {      
        s = (arcsine(x) / M_PI) * 180.0;
        c = 90.0 - s;
        t = (arctan(x) / M_PI) * 180.0;
        
        printf("%10c", VER2);
        printf("%5.3f", x);
        printf("%3c", VER1);
        printf("%20.15f", c);
        printf("%3c", VER1);
        printf("%20.15f", s);
        printf("%3c", VER1);
        printf("%20.15f", t);
        printf("%3c\n", VER2);

        x += d;
    }

    // lower border
    printf("%10c", LLC);
    for (i = 0;i < 7;i++)
        printf("%c", HOR2);
    printf("%c", LOD);
    for (i = 0;i < 22;i++)
        printf("%c", HOR2);
    printf("%c", LOD);
    for (i = 0;i < 22;i++)
        printf("%c", HOR2);
    printf("%c", LOD);
    for (i = 0;i < 22;i++)
        printf("%c", HOR2);
    printf("%c\n", LRC);  

    // para de mag-exit agad.
    printf("\n          Press any key to exit.\n");
    ch = _getch();
}

//              oo
//             -----
//             \        (2n)! x^(2n + 1)           1 * z^3    1 * 3 * x^5    1 * 3 * 5 * x^7
// arcsin(x) =  >     ---------------------  = x + -------- + ------------ + ----------------- + ....
//             /       (2^n n!)^2 (2n + 1)         2 * 3      2 * 4 * 5      2 * 4 * 6 * 7
//             -----
//             n = 0

double arcsine(double x)
{
    double y1, y2, odd, even, deno, prodeven, prododd, nume, n, exp;

    nume = 1.0;
    deno = 1.0;

    odd = 1.0;
    even = 2.0;
 
    prododd = 1.0;
    prodeven = 1.0;

    exp = 3.0;

    y1 = y2 = x;

    n = 0.0;

    do
    {
        y1 = y2;

        prododd *= odd;
        prodeven *= even;

        nume = prododd * pow(x, exp);
        deno = prodeven * exp;

        y2 += (nume / deno);

        odd += 2.0;
        even += 2.0;
        exp += 2.0;

    } while (fabs(y2-y1) > 1.0e-20);
  
    return y2;
}

//              oo
//             -----
//             \        (-1)^n (2n + 1)        x^3   x^5   x^7
// arctan(x) =  >      ----------------- = x - --- + --- - --- + ....
//             /            2n + 1              3     5     7
//             -----
//             n = 0

double arctan(double x)
{
    double y1, y2, num, sign;

    num = 3.0;
    sign = -1;

    y1 = y2 = x;

    do
    {
        y1 = y2;

        y2 += (sign * pow(x, num) / num);

        num += 2.0;
        sign *= -1;

    } while (fabs(y2-y1) > 1.0e-20);
  
    return y2;
}
