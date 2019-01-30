#include <bits/stdc++.h>

using namespace std;

ifstream fin ("accesibil.in");
ofstream fout ("accesibil.out");
int v[100003];
int w[5];

int esteaccesibil(int n)
{
    // un numar este accesibil daca are cel putin 2 cifre sau altfel spus este >= 10
    if(n < 10)
        return 0;

    int c = n % 10; // este ultima cifra
    n = n / 10; // n este numarul n din care tot taiam cate o cifra. 
    // pentru ca mergem de la cap la coada, cifrele care au ramas 
    // trebuie sa fie in ordine descrescatoare
    while ( n > 0 )
    {
        if( n % 10 != (c - 1) ) 
        {
            return 0;
        }
        c = n % 10;
        n = n / 10;
    }
    return 1;
}

int devineaccesibil(int n) 
{
    if(esteaccesibil(n))
        return 0;
    int p10 = 1; // puterea lui 10 ce corespunde cifrei pe care vrem sa o eliminam
    while(true) 
    {
        int m1 = n % p10; // partea de dupa cifra pe care vrem sa o eliminam
        int m2 = n / (p10 * 10); // partea de dinaintea cifrei pe care o eliminam
        int m = m1 + m2 * p10; // construim numarul 
        if(esteaccesibil(m))
            return 1;
        p10 = p10 * 10;
        if(m2 == 0)
            return 0; // iesim daca partea de dinainte este 0
        // cu alte cuvinte la iteratia curenta am eliminat  prima cifra

    }        

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

int mai_mic(int a, int b) 
{
    if(a > b)
        return 1;
    return 0;
}

int main()
{
    int c, k, n, j = 0;

    // cout << "esteaccesibil(123) = " << esteaccesibil(123) << endl;
    // cout << "esteaccesibil(1235) = " << esteaccesibil(1235) << endl;
    // cout << "esteaccesibil(1) = " << esteaccesibil(1) << endl;
    // cout << "esteaccesibil(234) = " << esteaccesibil(234) << endl;
    // cout << "esteaccesibil(32756) = " << esteaccesibil(32756) << endl;

    // cout << "devineaccesibil(123) = " << devineaccesibil(123) << endl;
    // cout << "devineaccesibil(1233) = " << devineaccesibil(1233) << endl;
    // cout << "devineaccesibil(12333) = " << devineaccesibil(12333) << endl;
    // cout << "devineaccesibil(2123456789) = " << devineaccesibil(2123456789) << endl;


    fin >> c;
    fin >> k >> n;
    for ( int i = 1 ; i <= n ; i++ )
        fin >> v[i];
    if ( c == 1 )
    {
        j = 1;
        for ( int i = 1 ; i <= n ; i++ )
        {
            if ( esteaccesibil(v[i]) == 1 )
            {
                // tinem maxim 4 elemente in w
                // adaugam in ultima pozitie
                // le sortam de fiecare data in ordine descrescatore
                // la sfarsit vor fi pe primele 3 pozitii cele mai mari numere.

                w[j] = v[i];
                if(j < 4)
                {
                    j++;
                }
                sort(w + 1, w + 1 + j, mai_mic);
            }
        }
        if(j > 3)
            j = 3;
        sort(w + 1, w + 1 + j);
        for ( int i = 1  ; i <= j; i++  )
            fout << w[i] << " ";
    }
    else if ( c == 2 )
    {
        int c = 0; // nu este bine sa folosesti aceasi variabila ca sa nu te incurci. 
        for ( int i = 1 ; i <= n ; i++ )
        {
            if(devineaccesibil(v[i]))
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

