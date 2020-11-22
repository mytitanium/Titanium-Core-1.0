#!/usr/bin/env bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cd $DIR/..

DOCKER_IMAGE=${DOCKER_IMAGE:-ttmpay/ttmd-develop}
DOCKER_TAG=${DOCKER_TAG:-latest}

BUILD_DIR=${BUILD_DIR:-.}

rm docker/bin/*
mkdir docker/bin
cp $BUILD_DIR/src/ttmd docker/bin/
cp $BUILD_DIR/src/ttm-cli docker/bin/
cp $BUILD_DIR/src/ttm-tx docker/bin/
strip docker/bin/ttmd
strip docker/bin/ttm-cli
strip docker/bin/ttm-tx

docker build --pull -t $DOCKER_IMAGE:$DOCKER_TAG -f docker/Dockerfile docker
