# STEP 1: Get base image
FROM debian:buster

# STEP 2: Download requiered elements
RUN apt-get -y upgrade && apt-get -y update \
	&& apt-get install -y mariadb-server mariadb-client

# STEP 3: Duplicate configs and utilities in container
COPY start.sh /usr/local/bin
COPY init.sql /usr/local

# STEP 4: Create and setup mariadb directory
RUN mkdir -p /run/mysqld \
	&& chown -R mysql:mysql /run/mysqld \
	&& chown -R mysql:mysql /var/lib/mysql

# STEP 6: Run start.sh as entrypoint and expose the port
EXPOSE 3306
ENTRYPOINT [ "start.sh" ]