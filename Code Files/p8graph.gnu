#defining size of graph
set terminal svg enhanced size 800,1000

#Naming the graph and labeling the axes
set title 'Yearly Averages for Average, Maximum, and Minimum Land Temperatures from 1850 to 2015'
set xlabel 'Year'
set ylabel 'Temperature (Celsius)'

#setting ther range and increments of axes
set xtics 15
set ytics 0.5
set xrange[1850:2015]
set yrange[0:16]

set key right bottom #legend interferes with the top right, move to bottom right

#plotting all 3 lines on hte same graph where average has bigger width
plot 'problem8.txt' using 1:2 with l lw 3 title 'Average Land Temperature', 'problem8.txt' using 1:3 with l title 'Maximum Land Temperature', 'problem8.txt' using 1:4 with l title 'Minimum Land Temperature'