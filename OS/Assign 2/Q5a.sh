read -p "Enter the email Address : " username
read -sp "Enter the password : " password
curl -u $username:$password --silent "https://mail.google.com/mail/feed/atom" |  grep -oPm1 "(?<=<title>)[^<]+" | sed '1d'
