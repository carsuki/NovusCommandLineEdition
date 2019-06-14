#!/bin/bash
mkdir -p /usr/local/etc/nvs
echo "apt-get" > /usr/local/etc/nvs/nvs
nvs search hello && nvs install hello && nvs upgrade hello && nvs remove hello && nvs update && nvs upgrade && nvs autoremove && nvs clean && echo "Test passed successfully"