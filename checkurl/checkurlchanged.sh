#!/bin/bash

export URL="http://ler.is.edu.ro/~cex_is/pregatire.html"
export MD5="0"

function get_md5 {
    export MD5=$(curl -s ${URL} | md5sum | cut -d' ' -f1)
    echo "${pipestatus[1]} ${pipestatus[2]}"
}

function gen_bip {
    echo -en "\007"
}


get_md5
export INITIAL_MD5=$MD5

echo "INITIAL_MD5=[${INITIAL_MD5}]"

while true
do
    sleep 60
    get_md5
    if [ "$MD5" != "$INITIAL_MD5" ]
    then
        echo "MD5 is different from INITIAL_MD5"
        gen_bip
    fi
    echo "MD5 = [${MD5}]"
done

