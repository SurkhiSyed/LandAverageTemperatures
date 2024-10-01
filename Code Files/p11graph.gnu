#defining size of graph
set terminal svg enhanced size 600,480

#labelling plot and both axes
set title 'Plot of Average Land Temperature and Average Land and Ocean Temperature (1850-2015)'
set xlabel 'Years'
set ylabel 'Temperature (Celsius)'

#setting up scale for both axes
set xtics 10
set ytics 1
set xrange[1850:2015]
set yrange[5:18]

#plotting the 2 columns onto the graph 
plot 'problem11.txt' using 1:2 with lines linewidth 1.5 \
title "Land Average Temperatures", \
'problem11.txt' using 1:3 with lines linewidth 1.5\
title "Land and Ocean Average Temperatures", \
