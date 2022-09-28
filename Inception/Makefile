.PHONY: all, clean, fclean, re, ps, log, down

YML_LOCATE = ./srcs/docker-compose.yml
DATA_LOCATE = /home/young-ch/data

all:
	sudo mkdir -p $(DATA_LOCATE)/wordpress
	sudo mkdir -p $(DATA_LOCATE)/mariadb
	sudo docker-compose -f $(YML_LOCATE) up --build -d

down:
	sudo docker-compose -f $(YML_LOCATE) down -v

clean:
	sudo docker-compose -f $(YML_LOCATE) down --rmi all -v

fclean: clean
	sudo rm -rf $(DATA_LOCATE)

re: fclean all

ps:
	sudo docker-compose -f $(YML_LOCATE) ps

log:
	sudo docker-compose -f $(YML_LOCATE) logs -f