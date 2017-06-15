reset 
set terminal pngcairo dashed enhanced size 640,480 font 'arial,12' fontscale 1.0 
set termoption dashed
set encoding utf8 
set output 'Q3straddlevega.png'

set title 'Straddle Vega vs Stock Price' font 'Arial-Bold,12' 
set xrange [60:140]
set yrange [0:80]
set xlabel 'Stock Price' font 'Arial-Bold,12'
set ylabel 'Straddle Vega' font 'Arial-Bold,12'
set key bmargin center horizontal height 1.5 width 1.5 font 'Arial,12'

set style line 99 lc rgb 'black' lt 1
set border 3 back ls 99
set tics nomirror

unset colorbox 
set for [i=1:5] linetype i dt i 
set style line 1 lt 1 lc rgb "black" lw 3
set style line 2 lt 3 lc rgb "black" lw 2

plot 'Q3straddle.txt' using 1:3 w l ls 1 title '1 month',\
		 'Q3straddle.txt' using 1:6 w l ls 2 title '1 year'
	
