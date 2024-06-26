USE mysql;
FLUSH PRIVILEGES;

GRANT ALL ON *.* TO '$MYSQL_ANAME'@'%' identified by '$MYSQL_APASS' WITH GRANT OPTION;
GRANT ALL ON *.* TO '$MYSQL_ANAME'@'localhost' identified by '$MYSQL_APASS' WITH GRANT OPTION;
SET PASSWORD FOR '$MYSQL_ANAME'@'localhost'=PASSWORD('$MYSQL_APASS');

DROP DATABASE IF EXISTS test;
FLUSH PRIVILEGES;

CREATE DATABASE $MYSQL_BASE CHARACTER SET utf8 COLLATE utf8_general_ci;
CREATE USER '$MYSQL_UNAME'@'%' IDENTIFIED by '$MYSQL_UPASS';
CREATE USER '$MYSQL_UNAME'@'localhost' IDENTIFIED by '$MYSQL_UPASS';

GRANT ALL PRIVILEGES ON $MYSQL_BASE.* TO '$MYSQL_UNAME'@'%';
GRANT ALL PRIVILEGES ON $MYSQL_BASE.* TO '$MYSQL_UNAME'@'localhost';
FLUSH PRIVILEGES;