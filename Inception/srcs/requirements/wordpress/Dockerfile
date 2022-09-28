FROM debian:buster

EXPOSE 9000

RUN apt-get update && apt-get install -y \
	php7.3-fpm \
	php7.3-mysql \
	mariadb-client \
	wget \
	curl && \
	wget -O /usr/bin/dumb-init https://github.com/Yelp/dumb-init/releases/download/v1.2.5/dumb-init_1.2.5_x86_64 && \
    chmod +x /usr/bin/dumb-init && \
	rm -rf /var/lib/apt/lists/*

ADD https://wordpress.org/latest.tar.gz /var/www/latest.tar.gz

RUN cd /var/www && tar -xvf latest.tar.gz && \
	rm -rf latest.tar.gz

RUN curl https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar --output /usr/bin/wp --silent

COPY ./conf/www.conf /etc/php/7.3/fpm/pool.d

RUN chmod +x ./usr/bin/wp

RUN mkdir /run/php

ENTRYPOINT  [ "/usr/bin/dumb-init", "--" ]

COPY ./tools/run.sh /var/www/wordpress/run.sh
RUN chmod +x /var/www/wordpress/run.sh
CMD ["bash", "/var/www/wordpress/run.sh"]