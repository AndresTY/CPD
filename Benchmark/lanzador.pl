#!/usr/bin/perl
#perl el encabezado debe ir de ese forma para ser detectado por el inerpreste perl
#Asunto: programa que permite hace el lanzamiento automatico de una bateria de experimentos

$path = `pwd`;
chomp($path);
$repeticiones = 5000; #numero de repeticiones
@ejecutables = ("mmClassic"); #nombre de los ejeutables
#@cargas = ("100","250","500","750"); #dimension de la matriz (hasta donde aguante el PC)
#@cargas = ("100","250","500","750","1000","1250","1500","2000","2500","3000","3500","4000"); #dimension de la matriz (hasta donde aguante el PC)
@cargas = ("100");

#system("make all");
foreach $e (@ejecutables){
	foreach $c (@cargas){
		$file = "$path/"."results/".$e."-carga-".$c.".txt";
		#$file = "$path/"."soluciones/"."$e"."-size-"."$c";
		#print "$file \n";	
		for($i=0;$i<$repeticiones;$i++){
			print "carga $c - rep $i\n";
			#system("./$e $c ");
			system("$path/$e $c >> $file");
		}
		#my $output = system "./mmClassic 3";
		#$output = `./$e $c`;
		#open (fh,">>",$file) or warn "Couldn-t open log file; discarding input";
		#print fh $c."-> ".$output;
		close($file);
	}
}
#system("make clean");
exit(1);
