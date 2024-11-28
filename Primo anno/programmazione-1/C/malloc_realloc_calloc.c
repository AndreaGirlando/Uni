#include <stdio.h>
#include <stdlib.h>

int main (int argc, char ** argv) {

  int n, i, j;

  if (argc != 2) {
    fprintf (stderr, "usage: %s N\n", argv[0]);
    return EXIT_FAILURE;
  } 

  if ( (n = atoi (argv[1])) < 0) {
    fprintf (stderr, "N must be gt 0\n");
    return EXIT_FAILURE;
  }

  /* primo modo */
  {
    double ** d;

    srand (10);

    if ( (d = (double **) malloc (sizeof (double *) * n)) == NULL) {
      fprintf (stderr, "Memory allocation error\n");
      return EXIT_FAILURE;
    }
    else {
      for (i=0; i<n; i++) {
        if ( (d[i] = (double *) malloc (sizeof (double) * n)) == NULL) {
          fprintf (stderr, "Memory allocation error\n");
          return EXIT_FAILURE;
        }
      }
    }

    for (i=0; i<n; i++) 
      for (j=0; j<n; j++)
       d[i][j] = 1.0e0 + (double) (1.0e0 * n * (rand() / (RAND_MAX + 1.0e0))); 

    fprintf (stdout, "\n");
    for (i=0; i<n; i++) {
      for (j=0; j<n; j++) {
        fprintf (stdout, "%10.5f ", d[i][j]);
      }
      fprintf (stdout, "\n");
    }

    for (i=0; i<n; i++)
      free (d[i]);
    free (d);
  }

  /* secondo */
  {
    double ** d, * temp;

    srand (10);

    if ( (d = (double **) malloc (sizeof (double *) * n)) == NULL) {
      fprintf (stderr, "Memory allocation error\n");
      return EXIT_FAILURE;
    }
    else {
      if ( (temp = (double *) malloc (sizeof (double) * n * n)) == NULL) {
        fprintf (stderr, "Memory allocation error\n");
        return EXIT_FAILURE;
      }
      else {
        for (i=0; i<n; i++) 
          d[i] = &temp[i*n]; 
      }
    }

    for (i=0; i<n; i++) 
      for (j=0; j<n; j++)
        d[i][j] = 1.0e0 + (double) (1.0e0 * n * (rand() / (RAND_MAX + 1.0e0))); 

    fprintf (stdout, "\n");
    for (i=0; i<n; i++) {
      for (j=0; j<n; j++) {
        fprintf (stdout, "%10.5f ", d[i][j]);
      }
      fprintf (stdout, "\n");
    }

    free (d);
    free (temp);
  }

  /* ancora */
  {
    double * d;

    srand (10);

    if ( (d = (double *) malloc (sizeof (double) * n * n)) == NULL) {
      fprintf (stderr, "Memory allocation error\n");
      return EXIT_FAILURE;
    }

    for (i=0; i<n; i++)
      for (j=0; j<n; j++)
        d[(i*n) + j] = 1.0e0 + (double) (1.0e0 * n * (rand() / (RAND_MAX + 1.0e0)));   

    fprintf (stdout, "\n");
    for (i=0; i<n; i++) {
      for (j=0; j<n; j++) {
        fprintf (stdout, "%10.5f ", d[(i*n) + j]);
      }
      fprintf (stdout, "\n");
    }
  }

  return EXIT_SUCCESS;
}
