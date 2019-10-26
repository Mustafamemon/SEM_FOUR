echo -e "Enter the file name with extension \c"
read 
name="$REPLY"
extension=$(echo ${name##*.})
if [ $extension == "c" ]
then
mv $name cdir
elif [ $extension == "jpg" ]
then
mv $name jpgdir
elif [ $extension == "sh" ]
then
mv $name shelldir
else 
echo "file extension not supported"
fi
