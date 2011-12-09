/*
ID:lc757692
TASK:job
LANG:C++
*/
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

/* when machine A is done with current job/B starts current job */
int finA[30];
int finB[30];

/* amount of time each machine takes to process a job */
int timA[30];
int timB[30];

/* number of A and B machines */
int na, nb;
/* number of tasks to do */
int ntask;

/* how long before the kth task is through the "A" machine */
int taskdone[1000];

/* the last time that a job can be put into a "B" machine and still
   be done */
/* the value is with respect to the total end time */
/* e.g., a value of 17 means 17 time steps before all task are completed */
int taskst[1000]; 

void make_times(void)
 {
  int lv, lv2;
  int min, mloc;

  for (lv = 0; lv < ntask; lv++)
   { /* for each time */
    min = 80000; /* = infinity */
    mloc = -1;

    for (lv2 = 0; lv2 < na; lv2++)
     { /* find best A machine */
      if (finA[lv2] + timA[lv2] < min)
       {
        mloc = lv2;
 min = finA[lv2] + timA[lv2];
       }
     }
    assert(mloc != -1); /* sanity check */

    /* put this job in the mloc "A" machine */
    finA[mloc] = min; 
    taskdone[lv] = min;

    min = 80000;
    mloc = -1;
    for (lv2 = 0; lv2 < nb; lv2++)
     { /* find best B machine */
      if (finB[lv2] + timB[lv2] < min)
       {
        mloc = lv2;
 min = finB[lv2] + timB[lv2];
       }
     }
    assert(mloc != -1); /* sanity */

    /* put this job through the mloc "B" machine */
    finB[mloc] = min;
    taskst[lv] = min;
   }
 }

int main(int argc, char **argv)
 {
  FILE *fout, *fin;
  int lv, lv2;
  int max, min;

  if ((fin = fopen("job.in", "r")) == NULL)
   {
    perror ("fopen fin");
    exit(1);
   }
  if ((fout = fopen("job.out", "w")) == NULL)
   {
    perror ("fopen fout");
    exit(1);
   }

  /* read in data */
  fscanf (fin, "%d %d %d", &ntask, &na, &nb);
  for (lv = 0; lv < na; lv++)
    fscanf (fin, "%d", &timA[lv]);
  for (lv = 0; lv < nb; lv++)
    fscanf (fin, "%d", &timB[lv]);

  /* create taskdone & taskst */
  make_times();

  /* determine time that we are done with the "A" machines */
  min = 0;
  for (lv = 0; lv < na; lv++)
    if (finA[lv] > min) min = finA[lv];
  fprintf (fout, "%i", min); 

  /* match "A" completed jobs to "B" started jobs greedily */
  max = 0;
  for (lv = 0; lv < ntask; lv++)
    if (taskdone[lv] + taskst[ntask-lv-1] > max)
      max = taskdone[lv] + taskst[ntask-lv-1];

  fprintf (fout, " %i\n", max);
  return 0;
 }

