read -p "Enter the String: " name
length=$(echo -n $name | wc -m)
i=0
((length--))
while(( $i<=$length ))
do
if [ ${name:$i:1} != ${name:$length:1} ]
then		
echo "Not Palindrome"
f=1
break ;
fi
((i++))
((length--))	
done
if [[ $f -ne 1 ]]
then 
echo "Palindrome"
fi
