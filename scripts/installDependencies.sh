#!/bin/bash

apt-get update
apt-get install -y \
	pkg-config \
	libcurl4-gnutls-dev \
	libssl-dev \
	libjsoncpp-dev
