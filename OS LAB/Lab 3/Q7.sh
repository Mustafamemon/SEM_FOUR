echo -e "Enter the number for factorial : \c"
read number
for (( i=$number-1; i>=2; i-- ))
do
number=$(( number * i ))
done
echo Factorial : $number
