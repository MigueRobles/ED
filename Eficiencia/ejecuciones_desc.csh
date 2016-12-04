#!/bin/csh
@ inicio = 100
@ fin = 10000
@ incremento = 100
set ejecutable = desc
set salida = tiempos_desc.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i` >> $salida
  @ i += $incremento
end
