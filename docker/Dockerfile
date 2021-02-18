FROM phusion/baseimage:bionic-1.0.0
LABEL maintainer="Ttm Developers <dev@ttm.org>"
LABEL description="Dockerised TtmCore, built from Travis"

ARG USER_ID
ARG GROUP_ID

ENV HOME /ttm

# add user with specified (or default) user/group ids
ENV USER_ID ${USER_ID:-1000}
ENV GROUP_ID ${GROUP_ID:-1000}
RUN groupadd -g ${GROUP_ID} ttm
RUN useradd -u ${USER_ID} -g ttm -s /bin/bash -m -d /ttm ttm
RUN mkdir /ttm/.ttmcore
RUN chown ttm:ttm -R /ttm

COPY bin/* /usr/local/bin/

RUN chmod a+x /usr/local/bin/*

USER ttm

VOLUME ["/ttm"]

EXPOSE 9998 9999 19998 19999

WORKDIR /ttm
