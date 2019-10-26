echo $1
n=$1
if [[ -z $1 ]]
then
	n=10
fi
sudo du -a | sort -n -r | head -n $n

