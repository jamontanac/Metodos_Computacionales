#!/bin/bash
#PBS -l nodes=1:ppn=8,mem=1gb,walltime=00:10:00
#PBS -M ja.montana@uniandes.edu.co
#PBS -m abe
#PBS -N Ejercicio30

# module load anaconda/python2
# module load gcc/4.9.4 
export OMP_NUM_THREADS=20
# cd $PBS_O_WORKDIR
gcc-8 -fopenmp Non_linear_advection.c -o Non_linear.x
rm -r Parallel_Non_linear
mkdir Parallel_Non_linear
cd Parallel_Non_linear
rm *.txt
../Non_linear.x
cd ..
rm *.x
gcc-8 Non_linear_advection.c -o Non_linear.x
rm - r Serial_Non_linear
mkdir Serial_Non_linear
cd Serial_Non_linear
rm *.txt
../Non_linear.x
cd ..
rm *.x
python Graficar.py
gcc-8 -fopenmp walk.c -o walk.x
./walk.x > Walk_serial.txt
rm *.x
gcc-8 walk.c -o walk.x
./walk.x > Walk_parallel.txt
python Graficar_2.py
