touch file1.txt
touch file2.txt
echo "Some text here" >file1.txt
echo "And Some text here" >file2.txt  
cat file1.txt file2.txt >file3.txt
mv file3.txt  ../file3.txt
tree $(cd..) 
