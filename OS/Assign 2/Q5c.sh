for(( i=1; i<=999; i++ ))
do
num=$i
sum1=0
while(( $num>0 ))
do
n=$(( num%10 ))
num=$(( num/10 ))
n=$(( n * n * n ))
sum1=$(( sum1 + n ))

done
if [[ $i -eq $sum1 ]]
then
echo $i
fi
done
