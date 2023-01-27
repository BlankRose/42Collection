# ********************************************************************* #
#          .-.                                                          #
#    __   /   \   __                                                    #
#   (  `'.\   /.'`  )   Inception - Makefile                            #
#    '-._.(;;;)._.-'                                                    #
#    .-'  ,`"`,  '-.                                                    #
#   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        #
#       //\   /         Last Updated: Fri Jan 27 19:39:30 CET 2023      #
#      ||  '-'                                                          #
# ********************************************************************* #

URL		= rosie.42.fr
TARGET	= src/docker-compose.yml
DATA	= /home/rosie/data

FLAGS	= --no-deps --build
SILENT	= > /dev/null 2>&1
NOERR	= | true
IDC		= $(SILENT) $(NOERR)

all: build
a: all

r: run
run: addhost folder
	@docker-compose -f $(TARGET) up

s: stop
stop:
	@docker-compose -f $(TARGET) down

c: clean
clean: stop folderclean
	@docker rm -f $(shell docker ps -aq) $(IDC)
	@docker rmi -f $(shell docker images -aq) $(IDC)
	@docker volume rm $(shell docker volume ls -q) $(IDC)

b: build
build: stop addhost folder
	@docker-compose -f $(TARGET) up $(FLAGS)

f: folder
folder:
	@mkdir -p $(DATA)/data
	@chmod 777 $(DATA)/data
	@mkdir -p $(DATA)/web
	@chmod 777 $(DATA)/web
	@mkdir -p $(DATA)/log
	@chmod 777 $(DATA)/log

fc: folderclean
folderclean:
	@rm -Rf $(DATA)/data
	@rm -Rf $(DATA)/web
	@rm -Rf $(DATA)/log

k: kill
kill:
	@kill -9 $(shell lsof -t -i tcp:80) $(IDC)

re: remake
remake: clean kill build

h: addhost
addhost:
	@chmod 777 /etc/hosts
	@echo "127.0.0.1 $(URL)" >> /etc/hosts
	@echo "127.0.0.1 www.$(URL)" >> /etc/hosts

.PHONY: \
	all build run \
	clean folderclean \
	stop kill \
	remake