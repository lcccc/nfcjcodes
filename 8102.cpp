#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
int primelist[100000];
int nprimes;

int isPrime(int num);
int reverse2(int i, int j);

int compare(const void *p, const void *q) { return *(int *)p-*(int *)q; }

 main (void) {
//    ifstream infile("pprime.in");
 //   ofstream outfile("pprime.out"); 
    int i, j, begin, end, num;
   while( cin>>begin>>end){
    if (begin <= 11 && 11 <=end)
        primelist[nprimes++] = 11;
    for (j = 0; j <= 999; j++)
        for (i = 0; i <= 9; i++)  {
	    num = reverse2(j,i);
	    if (num >= begin && num <=end && isPrime(num)) 
  	        primelist[nprimes++] = num;
        }
    qsort(primelist, nprimes, sizeof(int), compare);
    for (i = 0; i < nprimes; i++)
	cout << primelist[i] << "\n";
    cout<<endl;
}
}
int
reverse2(int num, int middle) {
    int i, save=num, digit, combino = 1;
    for (i = 0; num; num /= 10) {
	digit = num % 10;
	i = 10 * i + digit;
	combino *= 10;
    }
    return i+10*combino*save+combino*middle;
}
	
int isPrime(int num) {
    int i;
    if (num <= 3) return 1;
    if (num%2 == 0 || num%3 ==0) return 0;
    for (i = 5; i*i <= num; i++)
	if (num %i ==0)
	    return 0;
    return 1;
}
