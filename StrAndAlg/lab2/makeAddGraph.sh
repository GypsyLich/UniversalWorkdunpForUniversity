#!/usr/bin/gnuplot
set terminal png size 1366,768 enhanced font 'Arial, 16'
set output 'Add.png'

set style line 1 linecolor rgb 'red' linetype 1 linewidth 2
set style line 2 linecolor rgb 'green' linetype 1 linewidth 2

set border linewidth 2
set key top left
set grid
set logscale y
set mytics 1
set format y "%.6f"
set xlabel "Number of elements"
set format x "%3.0f" 
set ylabel "Execution time (mSec)"
set xtics 12000
set ytics 0.5
set rmargin 4
set tmargin 2
set mxtics
plot "bstreeAdd.dat" using 1:2 title "bsTree Add" with linespoints ls 1,\
 "hashtabAdd.dat" using 1:2 title "hashtab Add" with linespoints ls 2
