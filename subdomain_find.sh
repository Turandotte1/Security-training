#!/bin/bash

echo -n "Domain searched "
read domain

if [[ -z $domain ]]; then
    echo "Wrong input"
sslyze $domain --resum --certinfo=basic --compression --reneg --sslv2 --sslv3 --hide_rejected_ciphers > tmp

grep 'X509v3 Subject Alternative Name:' tmp \
    | sed 's/      X509v3 Subject Alternative Name:   //g' \
    | sed 's/, DNS:/\n/g' \
    | sed 's/www.//g' \
    | sed 's/DNS://g' > tmp2 \

sed 's/[ \t]*$//' tmp2 | sort -u > tmp3
cat tmp3
rm tmp*

