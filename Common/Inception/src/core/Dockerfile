# STEP 1: Get base image
FROM debian:buster

# STEP 2: Download requiered elements
RUN apt-get -y upgrade && apt-get -y update \
	&& apt-get install -y nginx openssl

# STEP 3: Duplicate configs and utilities in container
COPY nginx.conf /etc/nginx/conf.d/ssl.conf
COPY start.sh /usr/local/bin

# STEP 4: Create self-signed SSL certificates
RUN openssl req -new -newkey rsa:2048 -nodes \
	-keyout /etc/server.key -out /etc/server.csr \
	-subj "/C=FR/ST=Alsace/L=Mulhouse/CN=rosie.42.fr" \
	\
	&& openssl x509 -req \
	-in /etc/server.csr -signkey /etc/server.key \
	-out /etc/server.crt

# STEP 5: Run start.sh as entrypoint and expose the port
EXPOSE 443
ENTRYPOINT [ "start.sh" ]