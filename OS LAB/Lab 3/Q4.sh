read -p "Enter the Number " number
f=0
for (( i=2; i<$number; i++ ))
do
n=$number%$i

if [[ $n -eq 0 ]]
then
echo "Not a prime number"
f=1
break
fi
done

if [[ $f -eq 0 ]]
then
echo "Prime Number"
fi
