#defining size of graph
set terminal svg enhanced size 800,1000

#naming the graph and labelling the axis
set title 'Average Land Temperatures by Month w/ Error bars'
set xlabel 'Month'
set ylabel 'Temperature (Celsius)'

#setting up scale for both axes
set xtics 1
set xrange[0:13]
set ytics 0.5
set yrange[0:16]

#renaming the x tics into the months of the year
set xtics ( \
    "Jan" 1, \
    "Feb" 2, \
    "Mar" 3, \
    "Apr" 4, \
    "May" 5, \
    "Jun" 6, \
    "Jul" 7, \
    "Aug" 8, \
    "Sep" 9, \
    "Oct" 10, \
    "Nov" 11, \
    "Dec" 12 \
)

#plotting using names in column 1, land temp in column 2 and uncertainty in column 3 as errorbars
plot 'problem10.txt' using 1:2:3 with yerrorbars title 'Average Land Temperature'