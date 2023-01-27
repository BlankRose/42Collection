# STEP 1: Get base image
FROM debian:buster

# STEP 2: Download requiered elements
RUN apt-get -y upgrade && apt-get -y update \
	&& apt-get install -y php7.3 php7.3-mysql php7.3-fpm php7.3-gd php7.3-mbstring php7.3-zip \
	&& apt-get install -y mariadb-client wget

# STEP 3: Duplicate configs and utilities in container
COPY start.sh /usr/local/bin
COPY php-fpm.conf /etc/php/7.3/fpm/
COPY www.conf /etc/php/7.3/fpm/pool.d/

# STEP 4: Create and setup wordpress user and directory
RUN mkdir -p /var/www/html \
	&& chown -R www-data:www-data /var/www/html \
	&& userdel -f www-data && useradd -u 82 www-data

# STEP 5: Install WP-CLI (Helps with automated wordpress tasks)
RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
	&& chmod +x wp-cli.phar && mv wp-cli.phar /usr/local/bin/wp

# STEP 6: Run start.sh as entrypoint and expose the port
EXPOSE 9000
WORKDIR /var/www/html/wordpress
ENTRYPOINT [ "start.sh" ]