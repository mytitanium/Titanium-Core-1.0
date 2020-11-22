FROM debian:stretch
LABEL maintainer="Ttm Developers <dev@ttm.org>"
LABEL description="Dockerised TtmCore, built from Travis"

RUN apt-get update && apt-get -y upgrade && apt-get clean && rm -fr /var/cache/apt/*

COPY bin/* /usr/bin/
