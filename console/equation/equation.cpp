
// System of Equation

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

#define EQN_COUNT    10
#define EQN_LEN     100
#define VAR_LEN      20

bool IsNumber(char ch);
bool IsAlpha(char ch);

void GetNumber(double* number, char* str, int *i);
void GetAlpha(char* alpha, char* str, int *i);

void CollectVariable(char var[][VAR_LEN], char* str, int *k, int *n);

void ParseEquation(char str[EQN_COUNT][EQN_LEN], char var[EQN_COUNT][VAR_LEN], double a[EQN_COUNT][EQN_COUNT+1], int count);
bool FindUnknown(double a[EQN_COUNT][EQN_COUNT + 1], int count);

int main()
{
    char ch, eqn[EQN_COUNT][EQN_LEN], var[EQN_COUNT][VAR_LEN];
    int i, n;
    double a[EQN_COUNT][EQN_COUNT+1];
    bool nosoln;

    printf("System of Equations\n\n");

    ch = 'Y';

    while (ch == 'Y' || ch == 'y')
    {
        // kunin ang mga equation
        printf("Enter number of equation: ");
        gets_s(eqn[0], EQN_LEN);
   
        n = atoi(eqn[0]);

        printf("\n");
        for (i = 0;i < n;i++)
        {
            printf("Enter equation %d :", i+1);
            gets_s(eqn[i], EQN_LEN);
        }

        // hanapin ang solusyon
        ParseEquation(eqn, var, a, n);
        nosoln = FindUnknown(a, n);

        // i-display ang mga sagot
        printf("\n");
        if (nosoln)
            printf("No Solution\n");
        else
            for (i = 0; i < n; i++)
            printf("%s = %f\n", var[i], a[i][n]);

        // ulitin
        printf("\nContinue (y/n)?");
        
        do
        {
            ch = _getch();
        } while (!(ch == 'Y' || ch == 'y' || ch == 'N' || ch == 'n'));

        printf((ch == 'Y' || ch == 'y') ? "y\n\n":"n\n");
    }
}

// alamin kung number
bool IsNumber(char ch)
{
    char str[12];
    char* p;

    strcpy_s(str, 12, "0123456789.");
    p = strchr(str, ch);

    return (p != NULL);
}

// alamin kung letter
bool IsAlpha(char ch)
{
    char str[53];
    char* p;

    strcpy_s(str, 53, "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
    p = strchr(str, ch);

    return (p != NULL);
}

// kunin ang numeric character sa string str simula sa index i
void GetNumber(double* number, char* str, int* i)
{
    int k, n;
    char s[VAR_LEN];

    k = 0;

    n = strlen(str);

    while (IsNumber(str[*i]) && *i < n)
    {
        s[k] = str[*i];
        ++k;
        ++(*i);
    }

    --(*i);
        
    s[k] = '\0';

    *number = atof(s);
}

// kunin ang alpha character sa string str simula sa index i
void GetAlpha(char* alpha, char* str, int* i)
{
    int k, n;

    k = 0;

    n = strlen(str);

    while (IsAlpha(str[*i]) && *i < n)
    {
        alpha[k] = str[*i];
        ++k;
        ++(*i);
    }

    --(*i);
        
    alpha[k] = '\0';
}


// kolektahin ang mga variable na makikita sa equation str
void CollectVariable(char var[][VAR_LEN], char* str, int *k, int *n)
{
    int j;
    bool found;

    if (*n == 0)
    {
        strcpy_s(var[*n], VAR_LEN, str);
        *k = *n;
        ++(*n);
    }
    else
    {
        found = false;
        
        for (j = 0;j<(*n);j++)
        {
            found = (strcmp(str, var[j]) == 0);
            if (found)
            {
                *k = j;
                break;
            }
        }

        if (!found)
        {
            strcpy_s(var[*n], VAR_LEN, str);
            *k = *n;
            ++(*n);
        }
    }
}

// kunin ang mga variable at mga coefficient ng mga equation
void ParseEquation(char str[EQN_COUNT][EQN_LEN], char var[EQN_COUNT][VAR_LEN], double a[EQN_COUNT][EQN_COUNT + 1], int count)
{
    int i, j, k, m, n, c, l;
    double num, sign, toogle, numfound;
    char v[VAR_LEN];

    // i zero ang array
    n = count;
    m = n + 1;
    for (i = 0;i < n;i++)
        for (j = 0;j < m;j++)
            a[i][j] = 0.0;

    c = 0;

    // isa isahin ang equation
    for (k = 0;k < n;k++)
    {
        i = 0;
        l = strlen(str[k]);
        numfound = false;
        num = sign = toogle = 1.0;

        // isa isahin ang character ng equation
        while (i < l)
        {
            // kung ang character ay space, laktawan 'to
            if (str[k][i] == ' ') goto DITO;

            // kung ang character ay equal at may number, ilagay ang number sa array
            if (str[k][i] == '=')
            {
                if (numfound)
                {
                    a[k][n] = -toogle * sign * num;

                    numfound = false;
                }

                // nasa kabilang side ng equation, baliktarin ang sign
                toogle = -1.0;

                // sign ng number
                num = sign = 1.0;
            }

            // kung ang character ay plus at may number, ilagay ang number sa array
            if (str[k][i] == '+')
            {
                if (numfound)
                {
                    a[k][n] = -toogle * sign * num;

                    numfound = false;
                }

                // sign ng number
                num = sign = 1.0;
            }

            // kung ang character ay minus at may number, ilagay ang number sa array
            if (str[k][i] == '-')
            {
                if (numfound)
                {
                    a[k][n] = -toogle * sign * num;

                    numfound = false;
                }

                // sign ng number
                sign = -1.0;
                num = 1.0;
            }

            // kung ang character ay number, kunin ang number
            if (IsNumber(str[k][i]))
            {
                GetNumber(&num, str[k], &i);

                numfound = true;
            }

            // kung ang character ay letter, kunin ang letter at ilagay ang letter at number sa array
            if (IsAlpha(str[k][i]))
            {
                GetAlpha(v, str[k], &i);
                CollectVariable(var, v, &j, &c);

                a[k][j] = toogle * sign * num;

                numfound = false;
                num = 1.0;
            }

        DITO:

            ++i;
        }

        // kung may natitira pang number, ilagay to sa array
        if (numfound)
            a[k][n] = -toogle * sign * num;
    }
}

// find unknown by gauss jordan method
bool FindUnknown(double a[EQN_COUNT][EQN_COUNT + 1], int count)
{
    int i, j, k, m, n;
    bool nosoln;

    nosoln = false;
    n = count;
    m = n + 1;

    for (k = 0; k < n; k++)
    {
        if (a[k][k] == 0.0)
        {
            nosoln = true;
            break;
        }

        for (j = m - 1; j > (k - 1); j--)
            a[k][j] = a[k][j] / a[k][k];

        for (i = 0; i < n; i++)
            if (i != k)
                for (j = 0; j < m; j++)
                    if (j != k)
                        a[i][j] = a[i][j] - a[i][k] * a[k][j];

        j = k;
        for (i = 0; i < n; i++)
            if (i != k)
                a[i][j] = a[i][j] - a[i][k] * a[k][j];
    }

    return nosoln;
}
