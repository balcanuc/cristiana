#include <iostream>
#include <fstream>
using namespace std;
ifstream fin ("submit.in");
ofstream fout ("submit.out");
int w[103]; // punctaje
int main()
{
    int smax = 0;
    int n; // nr teste
    int m; // nr de 
    int p; // bonus 
    fin >> n;
    for ( int i = 1 ; i <= n ; i++ )
        fin >> w[i];
    fin >> p >> m;
    int a = 0; // penalizare
    for ( int i = 1 ; i <= m ; i++ )
    {

        int s = 0; 
        bool corect = true; // true daca toate sunt corecte, false altfel
        for ( int j = 1 ; j <= n ; j++ )
        {
            int v;
            fin >> v;
            if ( v == 1 )
                s = s + w[j];
            else 
                corect = false;
        }
        if(corect)
            s = p; 
        s = s - a;
        a = a + 2;
        if ( s > smax )
            smax = s;
    }
    fout << smax;
    return 0;
}
