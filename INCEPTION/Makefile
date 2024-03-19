NAME = inception

all: start

start:
	@mkdir -p /home/mthea/data/mariadb
	@mkdir -p /home/mthea/data/wordpress
	@ echo "127.0.0.1 mthea.42.fr" >> /etc/hosts
	@ docker-compose -f srcs/docker-compose.yml up --build
	
stop:
	@ docker-compose -f srcs/docker-compose.yml down

clean: stop
	@rm -rf /home/mthea/data/mariadb
	@rm -rf /home/mthea/data/wordpress
	@docker system prune -f
	@docker image prune -af
	@docker volume rm srcs_wordpress
	@docker volume rm srcs_mariadb

