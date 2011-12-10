/*
ID:lc757692
PROG:spin
LANG:C++
*/
 
#include <cstdio>
 
FILE *fin = fopen("spin.in", "r");
FILE *fout = fopen("spin.out", "w");
 
bool f[6][360];
int s[6], g[6];
 
bool can(int d)
{
  for (int i = 1; i <= 5; i++)
    if (!f[i][(g[i] + d) % 360]) return false;
  return true;
}
 
int main()
{
int t, a, b;
  for (int i = 1; i <= 5; i++)
    {
      fscanf(fin, "%d%d", &s[i], &t);
      s[i] = 360 - s[i];
      for (int j = 1; j <= t; j++)
        {
          fscanf(fin, "%d%d", &a, &b);
          for (int k = 0; k <= b; k++)
            f[i][(a + k) % 360] = true;
        }
    }
bool key = false;
  for (t = 0; t < 360; t++)
    if (key) break;
      else
        {
          for (int i = 0; i < 360; i++)
            if (can(i)) {key = true; break;}
          for (int i = 1; i <= 5; i++)
            g[i] += s[i];
        }
  if (key) fprintf(fout, "%d\n", t - 1);
    else fprintf(fout, "none\n", t);
  return 0;
}
