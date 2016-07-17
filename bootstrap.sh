#!/usr/bin/env bash

##
# Author:   Dave Smith-Hayes <me@davesmithhayes.com>
# License:  BSD 3.0
#
# This script will provision the Vagrant box to server Bastard over NGiNX. The
# basic installation runs on Debian 8 and includes the repository right from
# Facebook for HHVM.
##

##
# Add repositories for the HHVM
##
echo "Adding the HHVM repositories..."

wget -O - http://dl.hhvm.com/conf/hhvm.gpg.key | apt-key add -
echo deb http://dl.hhvm.com/debian jessie main | tee /etc/apt/sources.list.d/hhvm.list

apt-get update
apt-get upgrade -y
apt-get autoremove -y

##
# Install the packages
##
echo "Installing the HHVM and NGiNX..."
apt-get install -y hhvm nginx

##
# Get composer and set it up with HHVM
##
echo "Installing Composer..."
wget -q https://getcomposer.org/composer.phar
chmod +x composer.phar
mv composer.phar /usr/local/bin/composer
