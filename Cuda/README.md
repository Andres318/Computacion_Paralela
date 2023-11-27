# CUDA GPU Enumeration Project

Este proyecto consiste en un programa CUDA llamado `enum_gpu`, diseñado para enumerar y proporcionar información detallada sobre las GPU disponibles en el sistema. El proyecto incluye varios archivos esenciales y un script de ejecución (pasiva) para facilitar la compilación y la ejecución del programa en un entorno de Slurm con GPUs NVIDIA. A continuación, se proporciona una descripción de cada archivo del proyecto:

## Archivo `book.h`

Este archivo contiene funciones y definiciones comunes utilizadas en varios programas CUDA. Algunas de las funciones importantes incluyen `HandleError`, que maneja errores de CUDA, y funciones para trabajar con hilos en sistemas Windows y POSIX (Estandar UNIX). También incluye funciones para generar bloques de datos aleatorios y convertir valores flotantes en colores.

## Archivo `enum_gpu.cu`

Este es el programa principal que utiliza CUDA para enumerar y proporcionar información detallada sobre las GPUs disponibles en el sistema. Utiliza la API de CUDA para obtener información como el nombre, la capacidad de cálculo, la velocidad del reloj y la memoria de cada GPU. La información recopilada se imprime en la consola.

## Archivo `Makefile`

El archivo Makefile define las reglas para compilar el programa CUDA. Utiliza el compilador `nvcc` con opciones específicas, como el estándar C++11 y la supresión de advertencias obsoletas. También especifica las bibliotecas y rutas de CUDA necesarias. El objetivo principal es `enum_gpu`.

## Archivo `run_enum_gpu.sh`

Este script de shell facilita la ejecución del programa CUDA en un entorno de Slurm. Carga el entorno de CUDA, navega al directorio de trabajo actual, compila el programa usando `make` y luego ejecuta el programa con `srun`. Asegúrate de que el script tenga permisos de ejecución antes de usarlo.

## Instrucciones de Uso

1. Ejecuta el script con `bash run_enum_gpu.sh`

Si el comando anterior no funciona correctamente, tambien puedes ejecutar los comandos alternativos:

1. Asegúrate de que el script tenga permisos de ejecución con `chmod +x run_enum_gpu.sh`.
2. Ejecuta el script con `./run_enum_gpu.sh`.

Este proyecto asume que estás utilizando un entorno con Slurm y CUDA en su version 8.0 el cual está instalado correctamente. Ajusta según la configuración específica de tu sistema.

**Nota:** Asegúrate de tener las bibliotecas y herramientas de CUDA instaladas y configuradas correctamente en tu sistema antes de compilar y ejecutar el programa.

## Respuesta del programa

Un ejemplo de la salida del programa ese el siguiente:

```plaintext
   --- General Information for device 1 ---
Name:  Tesla M2075
Compute capability:  2.0
Clock rate:  1147000
Device copy overlap:  Enabled
Kernel execution timeout :  Disabled
   --- Memory Information for device 1 ---
Total global mem:  5559156736
Total constant Mem:  65536
Max mem pitch:  2147483647
Texture Alignment:  512
   --- MP Information for device 1 ---
Multiprocessor count:  14
Shared mem per mp:  49152
Registers per mp:  32768
Threads in warp:  32
Max threads per block:  1024
Max thread dimensions:  (1024, 1024, 64)
Max grid dimensions:  (65535, 65535, 65535)
```

A continuacion se presenta una pequeña descripcion de cada uno de los parametros de la respuesta para entender mejor la informacion proporcionada.

### General Information:
  Name: Nombre de la GPU.   
  - Compute capability: Capacidad de cálculo de la GPU. En este caso, 2.0.
  - Clock rate: Frecuencia del reloj de la GPU.
  - Device copy overlap: Si la GPU permite la superposición de copia de dispositivo.
  - Kernel execution timeout: Si hay un límite de tiempo para la ejecución de kernels.

### Memory Information:
  - Total global mem: Memoria global total disponible en bytes.
  - Total constant Mem: Memoria constante total disponible en bytes.
  - Max mem pitch: Máximo paso de memoria en bytes.
  - Texture Alignment: Alineación de textura en bytes.

### MP Information (Multiprocessor):
  - Multiprocessor count: Número de multiprocesadores en la GPU.
  - Shared mem per mp: Memoria compartida por multiprocesador en bytes.
  - Registers per mp: Número de registros por multiprocesador.
  - Threads in warp: Número de hilos en un warp.
  - Max threads per block: Número máximo de hilos por bloque.
  - Max thread dimensions: Dimensiones máximas de los hilos por bloque.
  - Max grid dimensions: Dimensiones máximas de los bloques en la malla.


En resumen, estos parámetros proporcionan información detallada sobre la GPU, como su capacidad de cálculo, velocidad de reloj, capacidad de memoria y características de multiprocesador. Esta información es útil para optimizar y ajustar el rendimiento de los programas CUDA para aprovechar al máximo la capacidad de la GPU.
