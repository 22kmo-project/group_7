# group_7
Tietokannan ER-kaavio
<br><img src="er_kaavio.png" width="600"><br>

SQL-komennot

CREATE USER 'group_7'@'localhost' 
IDENTIFIED WITH mysql_native_password BY 'netpass';

GRANT ALL on group_7.* to 'group_7'@'localhost';