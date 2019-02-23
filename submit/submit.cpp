#include <iostream>
#include <fstream>
using namespace std;
ifstream fin ("submit.in");
ofstream fout ("submit.out");
int v[103][103], w[103];
int main()
{
    int n, m, p, smax = 0;
    fin >> n;
    for ( int i = 1 ; i <= n ; i++ )
        fin >> w[i];
    fin >> p >> m;
    for ( int i = 1 ; i <= m ; i++ )
        for ( int j = 1 ; j <= n ; j++ )
            fin >> v[i][j];
    int a = 0;
    for ( int i = 1 ; i <= m ; i++ )
    {
        int s = p;
        for ( int j = 1 ; j <= n ; j++ )
        {
            if ( v[i][j] == 1 )
                s = s + w[j];
        }
        s = s - a;
        a = a + 2;
        if ( s > smax )
            smax = s;
    }
    fout << smax;
    return 0;
}
