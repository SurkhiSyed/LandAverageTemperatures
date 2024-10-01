#setting size of the image
set terminal svg enhanced size 800,1000

#labelling and setting up all axes and title
set title 'Average Land Temperatures in 19th and 20th Centuries'
set xlabel 'Years'
set ylabel 'Average Land Temps'
set yrange [6:10] 
set xtics 5

plot 'problem7.txt' using 1:2 with lines linewidth 1.5 \
title "19th Century", \
'problem7.txt' using 1:3 with lines linewidth 1.5\
title "20th Century", \
