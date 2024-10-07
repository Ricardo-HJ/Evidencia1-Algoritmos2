# Análisis de Transmisiones

## Descripción
Este proyecto realiza un análisis de tres archivos de transmisión (Transmission1.txt, Transmission2.txt, Transmission3.txt) y un archivo de códigos (mcode.txt). El programa busca subsecuencias, palíndromos y substrings comunes entre las transmisiones.

## Repositorio GitHub
[https://github.com/Ricardo-HJ/Evidencia1-Algoritmos2](https://github.com/Ricardo-HJ/Evidencia1-Algoritmos2)

## Archivos del Proyecto
- `Evidencia1.cpp`: Archivo principal que contiene la función `main()`.
- `Code.h`: Contiene funciones para el análisis de subsecuencias.
- `Palindromo.h`: Implementa el algoritmo de Manacher para encontrar palíndromos.
- `Substring.h`: Contiene funciones para encontrar substrings comunes.

## Funcionalidades
1. **Análisis de Subsecuencias**: 
   - Busca subsecuencias específicas en las transmisiones.
   - Encuentra la subsecuencia más común para cada código en mcode.txt.

2. **Búsqueda de Palíndromos**: 
   - Encuentra el palíndromo más largo en cada transmisión.

3. **Substrings Comunes**: 
   - Identifica los substrings más largos comunes entre pares de transmisiones.

## Cómo Usar
1. Clone el repositorio:
   ```
   git clone https://github.com/Ricardo-HJ/Evidencia1-Algoritmos2.git
   ```

2. Asegúrese de tener los siguientes archivos en el mismo directorio que el ejecutable:
   - transmission1.txt
   - transmission2.txt
   - transmission3.txt
   - mcode.txt

3. Compile el programa:
   ```
   g++ Evidencia1.cpp -o Evidencia1
   ```

4. Ejecute el programa:
   ```
   ./Evidencia1
   ```

5. El programa generará un archivo de salida llamado `checking1.txt` con los resultados del análisis.

## Complejidad Temporal
- La complejidad temporal general del programa es O(n^3) en el peor caso, donde n es la longitud de la transmisión más larga.

## Autor
Ricardo Hernandez - A00837337

## Última Edición
06/10/24

## Notas Adicionales
- El programa utiliza algoritmos eficientes como el algoritmo de Manacher para la búsqueda de palíndromos.
- Se implementan varias optimizaciones para mejorar el rendimiento en el análisis de grandes volúmenes de datos.