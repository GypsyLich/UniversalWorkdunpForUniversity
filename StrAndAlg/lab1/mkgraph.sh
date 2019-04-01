#!/usr/bin/gnuplot
set terminal png size 1366,768 enhanced font 'Arial, 16'
set output 'Sort.png'

set style line 1 linecolor rgb 'red' linetype 1 linewidth 2
set style line 2 linecolor rgb 'blue' linetype 1 linewidth 2
set style line 3 linecolor rgb 'green' linetype 1 linewidth 2

set border linewidth 2
set key top left
set grid
set logscale y
set mytics 1
set format y "%.4f"
set xlabel "Number of elements"
set format x "%3.0f" 
set ylabel "Execution time (sec)"
set xtics 25000
set ytics 0.1
set rmargin 4
set tmargin 2
set mxtics
plot "rad.dat" using 1:2 title "Radix Sort" with linespoints ls 1,\
 "merge.dat" using 1:2 title "Merge Sort" with linespoints ls 2,\
 "oddEven.dat" using 1:2 title "Odd-Even Sort" with linespoints ls 3
