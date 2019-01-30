#include <bits/stdc++.h>

using namespace std;
ifstream fin ("accesibil.in");
ofstream fout ("accesibil.out");
int v[100003], w[25000];

int esteaccesibil(int n)
{
    int b = 0;
    while ( n > 0 )
    {
        int c = n % 10;
        if ( c == b )
            return 0;
        b = c;
        n = n / 10;
    }
    return 1;
}

int pow10(int n)
{
    int p = 1;
    for ( int i = 1 ; i <= n ; i++ )
    {
        p = p * 10;
    }
    return p;
}

int main()
{
    int c, k, n, j = 0;
    fin >> c;
    fin >> k >> n;
    for ( int i = 1 ; i <= n ; i++ )
        fin >> v[i];
    if ( c == 1 )
    {
        for ( int i = 1 ; i <= n ; i++ )
        {
            if ( esteaccesibil(v[i]) == 1 )
            {
                w[j] = v[i];
                j++;
            }
        }
        sort (w+1, w+1+j);
        for ( int i = j - 2  ; i <= j; i++  )
            fout << w[i] << " ";
    }
    else if ( c == 2 )
    {
        int c = 0;
        for ( int i = 1 ; i <= n ; i++ )
        {
            c++;
        }
        fout << c;
    }
    else if ( c == 3 )
    {
        for ( int i = 1 ; i <= k ; i++ )
            fout << i;
        fout << " ";
        for ( int i = 10 - k ; i <= 9 ; i++ )
            fout << i;
    }
    else
    {
        int p = 0, ip = 0;
        for ( int i = 1 ; i <= 10 - k ; i++ )
        {
            if ( ( i + k - 1 ) % 2 == 0 )
                p++;
            else
                ip++;
        }
        fout << p << " " << ip;
    }
    return 0;
}

