#!/bin/bash

# Declare variables
file=/usr/local/init.sql
conf=/etc/mysql/mariadb.conf.d/50-server.cnf
env=(MYSQL_HOST MYSQL_BASE MYSQL_ANAME MYSQL_APASS MYSQL_UNAME MYSQL_UPASS)

# Apply env variables to the file
for i in "${env[@]}"; do
	sed -i "s/\$$i/${!i}/g" $file
done

# Setup everything if nothing is set in stone
# (Usually on first lauch of the docker structure)
if [ ! -d "/var/lib/mysql/mariadb" ]; then

	# Install MySQL
	# (Redirecting output to not have notice message)
	mysql_install_db \
		--basedir=/usr --datadir=/var/lib/mysql \
		--user=mysql --rpm > /dev/null

	# Finally apply the bootstrap
	mysqld --user=mysql --bootstrap < $file

fi

# Make MariaDB listen and respond
# to every network interfaces (for the docker structure)
# The address 0.0.0.0 will cause it to respond to any addresses
sed -i "s|skip-networking|# skip-networking|g" $conf
sed -i "s|.*bind-address\s*=.*|bind-address=0.0.0.0|g" $conf

# Run MariaDB
exec mysqld --user=mysql