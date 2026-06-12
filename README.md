# Resolución de sudokus con SA

El sudoku es un juego de lógica que consiste en llenar una cuadrícula de 9x9 con números del 1 al 9, de tal manera que cada fila, cada columna y cada una de las nueve subcuadrículas de 3x3 contengan todos los números del 1 al 9 sin repetirse.

Para este problema, utilizaremos como guion los puntos proporcionados por Alfonso Tarancón en el tema de Simulated Annealing de sus apuntes. Comenzamos con la construcción del modelo (Sección 13.2.1, página 223).

**1. Espacio de configuración:** Para este problema, será el espacio generado por todas las matrices cuadradas de dimensión NxN, (9x9 normalmente), si no tenemos en cuenta los números fijos en el problema. Con esto, podemos ver que tenemos $$\scriptsize{9^{N \times N}}$$ configuraciones distintas, que sería un número del orden de $$\scriptsize{10^{77}}$$.

**2. Configuración inicial:** Por lo general, pondremos que todas las componentes de la matriz sean 1 (menos los fijos, que serán los que tengan que ser).

**3- Definición de la Energía:** Para este problema, utilizaremos como energía al número de números repetidos por fila y columna, de tal forma que dicha función tiene un mínimo, que es nulo y único, y que además está justo con la configuración solución.

**4- Función de Partición:** Ni idea, física estadística es una asignatura del segundo cuatri de tercero y estoy haciendo esto en junio, por lo que podemos decir que es un problema para el yo futuro.

**5- Cambios tentativos:** Para cada paso, cambiaremos una componente random de la matriz (si no es un número fijo) por un número random plano entre 1 y 9.


