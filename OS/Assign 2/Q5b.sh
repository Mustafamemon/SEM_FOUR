ls
echo
read -p "Ente the file Name with extension to change  extenesion to exe : " Name 
IFS='.'
read -ra ADDR <<<"$Name"
mv ${ADDR[0]}.${ADDR[1]} ${ADDR[0]}.exe
echo
ls
echo
