for i in *
do
if [ -r $i ] && [ -x $i ] && [ -w $i ]
then
	echo $i
fi
done
