#!/bin/bash

#SBATCH --nodes=1
#SBATCH --ntasks-per-core=10
#SBATCH --cpus-per-task=10
#SBATCH --partition=standard
#SBATCH --job-name=sycl
#SBATCH --error=error_files/%j.err
#SBATCH --output=output_files/%j.out
#SBATCH --time=01:00:00


ulimit -s unlimited



./a.out
