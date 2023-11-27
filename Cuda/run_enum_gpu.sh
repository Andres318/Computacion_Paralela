#!/bin/bash

# Cargar el entorno de CUDA
module load devtools/cuda/8.0

# Navegar al directorio de trabajo
cd $PWD

# Compilar el programa CUDA
make

# Ejecutar el programa
srun ./enum_gpu