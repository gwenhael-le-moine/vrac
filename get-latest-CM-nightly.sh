#!/bin/sh

MODEL=${MODEL:=p990}
MIRROR=${MIRROR:=http://mirror.dal.tdrevolution.net/cm/nightly}

FILENAME=$(lftp $MIRROR/$MODEL/ -e "cls --date * ; quit" | awk '{print $4}' | tail -n1)

OUTPUT=/tmp

wget -c $MIRROR/$MODEL/$FILENAME -O $OUTPUT/$FILENAME
