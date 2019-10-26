read -p "Enter the source name : " name1
read -p "Enter the destination name : " name2
[ -r $name1 ] && W=1 || W=0

if [[ $W -eq 0 ]]
then
	echo "Source file not have Read Permission"
	exit
fi

[ -e $name2 ] && W=1 || W=0

if [[ $W -eq 1 ]]
then
	read -p "Do you Want to overwrite it ?y/n : " ans
fi

[ -w $name2 ] && W=1 || W=0

if [ "$ans" ==  "y" ]
then
	if [[ $W -eq 0 ]]
	then
		chmod +w $name2
	fi
	cat $name1 >> $name2 
elif [ "$ans" == "n" ]
then
	rm $name2	
	if [[ $W -eq 0 ]]
	then
		touch $name2
		chmod +w $name2
	fi
	cat $name1 >> $name2 
fi

