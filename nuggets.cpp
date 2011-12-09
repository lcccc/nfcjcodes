/*
ID:lc757692
TASK:nuggets
LANG:C++
*/


#include <fstream>
#include <string>
#include <string.h>
using namespace std;
int 
main ()
{

    int     n;
    int     sizes[10];

    ifstream filein ("nuggets.in");
    filein >> n;
    for (int in = 0; in < n; ++in) {
 filein >> sizes[in];
    }
    filein.close ();

    bool    cando[67000];
    memset (cando, 0, 67000);

    for (int loop = 0; loop < n; ++loop) {
 cando[sizes[loop]] = true;
 for (int loop2 = 0; loop2 < 66700; ++loop2) {
     if (cando[loop2]) {
  cando[loop2 + sizes[loop]] = true;
     }
 }
    }

    ofstream fileout ("nuggets.out");
    for (int out = 66500; out >= 0; --out) {
 if (!cando[out]) {
     if (out < 66000) {
  fileout << out << endl;
  break;
     }
     else {
  fileout << 0 << endl;
  break;
     }
 }
    }
    fileout.close ();

    return (0);
}
