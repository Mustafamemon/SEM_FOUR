echo -e "Enter the 5 number : \c "
read -a number
max=0
for (( i=0; i<5 ;i++ ))
do
if (( $max <  ${number[$i]} ))
then
max=${number[$i]}
fi
done
echo MAXIMUM NUMBER :$max
min=$max
for (( i=0; i<5 ;i++ ))
do
if (( $min >  ${number[$i]} ))
then
min=${number[$i]}
fi
done
echo MINIMUM NUMBER :$min

