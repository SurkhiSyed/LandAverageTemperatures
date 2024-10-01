# defining the size of the graph
set terminal svg enhanced size 600,480

# Naming the graph and labelin the axes
set title 'Average Temperatures Per Year (1760-2015)'
set xlabel 'Years'
set ylabel 'Temperature (C)'

#creating the range and increments for the axes
set xtics 15
set ytics 1
set xrange[1760:2015]
set yrange[6:10]

#plotting the data with a line
plot 'problem6.txt' with lines linewidth 1 \
title 'Average Temperatures Per Year(1760-2015)' 