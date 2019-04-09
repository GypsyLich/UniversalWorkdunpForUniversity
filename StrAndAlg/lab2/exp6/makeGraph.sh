#!/usr/bin/gnuplot
set terminal png size 1366,768 enhanced font 'Arial, 16'
set output 'Lookup.png'

set style line 1 linecolor rgb 'red' linetype 1 linewidth 2
set style line 2 linecolor rgb 'green' linetype 1 linewidth 2

set border linewidth 2
set key top left
set grid
set logscale y
set mytics 1
set format y "%d"
set xlabel "Number of elements"
set format x "%d" 
set ylabel "Collisions"
set xtics 12000
set ytics 100
set rmargin 4
set tmargin 2
set mxtics
plot "AddhashtabLookup.dat" using 1:2 title "addHashtab Lookup" with linespoints ls 1,\
 "KRhashtabLookup.dat" using 1:2 title "KRHashtab Lookup" with linespoints ls 2
