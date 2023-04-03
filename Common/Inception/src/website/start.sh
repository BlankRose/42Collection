#!/bin/bash

# Setup everything if nothing is set in stone
# (Usually on first lauch of the docker structure)
if [ ! -f "/var/www/html/wordpress/index.php" ]; then

	# Download the core elements
	# (Neccessary before doing anything)
	wp core download --allow-root

	# Initializes configs and add it to the database
	wp config create \
		--dbname=$MYSQL_BASE --dbhost=$MYSQL_HOST \
		--dbuser=$MYSQL_UNAME --dbpass=$MYSQL_UPASS \
		--dbcharset="utf8" --allow-root

	# Install and setup core elements of WordPress
	wp core install --url=rosie.42.fr --title=$WORDPRESS_TITLE \
		--admin_user=$WORDPRESS_ANAME --admin_password=$WORDPRESS_APASS --admin_email=$WORDPRESS_AMAIL \
		--skip-email --allow-root

	# Set a theme and create an base user
	wp theme install popularfx --activate --allow-root
	wp user create $WORDPRESS_UNAME $WORDPRESS_UMAIL --user_pass=$WORDPRESS_UPASS \
		--role=author --allow-root

	# Create a new published post
	wp post create --post_type=post --post_title="Inception!" --post_status=publish --allow-root

fi

# Run PHP FPM in foreground (FastCGI Process Manager)
# (Prevents from returning, thus preserves the container's lifespan)
exec php-fpm7.3 -F