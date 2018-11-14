#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265358979323846264338327
#include<mpi.h>
int main (int argc, char *argv[])
{
  long n_points;
  double x, y, r;
  double gauss_1, gauss_2;
  double *list;
  float mu, sigma;
  long long i;
  int rank, size;
   MPI_Init (&argc, &argv);
   MPI_Comm_rank (MPI_COMM_WORLD, &rank);
   MPI_Comm_size (MPI_COMM_WORLD, &size);
   n_part= atoi(argv[1]);
  n_points = atoi(argv[2]);
  mu = atof(argv[3]);
  sigma = atof(argv[4]);
  


  if(!(list=malloc(n_points * sizeof(double)))){
    fprintf(stderr, "Problema con la reserva de memoria\n");
    exit(1);
  }

  
  srand48(n_points);
  for(i=0;i<n_points;i++){    
      x = drand48();
      y = drand48();
      gauss_1 = sqrt(-2.0 * log(x)) * cos(2.0* PI * y);
      gauss_2 = sqrt(-2.0 * log(x)) * sin(2.0* PI * y);
      
      gauss_1 = gauss_1*sigma + mu;
      list[i] = gauss_1;
  }


  
  for(int jj=1;jj<=n_part;jj++}
  {
    FILE *out;
    char result[50];
    sprintf(result, "%d", jj);
    getchar(); 
  if(!(out = fopen("sample_"+result+".dat", "w"))){
    fprintf(stderr, "Problema abriendo el archivo\n");
    exit(1);
  }
   /* for(i=0;i<n_points;i++) */
   /*   { */
   /*     printf("numero aleaotrio de %d of %d %f\n", rank, size,list[i]); */
   /*   } */
   for(i=0;i<n_points;i++){
     fprintf(out, "%f\n", list[i]);
   }
    fclose(out);
  }
  MPI_Finalize();
 
  

  return 0;
 
}
  

 

  
