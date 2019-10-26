echo -e "Enter the Ending Point : \c"
read number
a=0
b=1
echo -e $a , $b , "\c"
for (( i=0; i<number; i++ ))
do
c=$(( a + b ))
echo -e $c ", \c " 
a=$b
b=$c
done
