#!/usr/bin/perl
=begin comment
Fecha: 23 Agosto 2022
Autor: Juan Pablo Barrios Suarez
Tema: Ejecucion Automatizada de Benchmarks
=cut

#Se crean vectores para los ejecutables 
@Benchmarks = ("mm_main_double","mm_main_double_rnd");

#Se crean vectores para los ejecutables 
@Cargas = ("900","1200","1500");

#Numero de repeticiones
$n = 2;
$Path = "/home/juanpablo_b/Documentos/Parallel_Computation/Benchmarks/Bench_Pthreads/";
=begin comment
Se itera sobre la cantidad de ejecutables, cargas y repeticiones
=cut

foreach $exes (@Benchmarks){
    foreach $carga (@Cargas){
        #Se crea un fichero para almacenar los datos
        $file = "Soluciones/".$exes."-size-".$carga.".txt";
        for ($i=0;$i<$n;$i++){
            system("$Path$exes $carga >> $file");
        }
        close($file);
    }
}
