#defining a size for graph
set terminal svg enhanced size 800,1000

#setting up multiplot to be 1 row with 3 graphs
set multiplot layout 1,3 title 'Average, Maximum and Minimum Tempartures per Century'

#setting up y-axis titles and scale
set ylabel 'Temperature (C)'
set ytics 0.5
set yrange[0:18]
unset xtics

#setting style of the graph to be bar graph/histograms
set style data histogram
set style fill solid
set boxwidth 1

#plotting the first graph, where each piece of data is placed one by one to assign colour
set x2label 'Average'
plot "problem9.txt" every ::0::0 using 1 linestyle 7 title "19th Century", \
"problem9.txt" every ::1::1 using 1 linestyle 2 title "20th Century", \
"problem9.txt" every ::2::2 using 1 linestyle 3 title "21th Century"

#plotting the second graph, exact same scheme as first
set x2label 'Maximum'
plot "problem9.txt" every ::0::0 using 2 linestyle 7 title "19th Century", \
"problem9.txt" every ::1::1 using 2 linestyle 2 title "20th Century", \
"problem9.txt" every ::2::2 using 2 linestyle 3 title "21th Century"

#plotting the third graph, using the third column of data
set x2label 'Minimum'
plot "problem9.txt" every ::0::0 using 3 linestyle 7 title "19th Century", \
"problem9.txt" every ::1::1 using 3 linestyle 2 title "20th Century", \
"problem9.txt" every ::2::2 using 3 linestyle 3 title "21th Century"