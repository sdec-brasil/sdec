#!/bin/sh

CHAINNAME="newcmdssh"
DIR="$HOME/.multichain/$CHAINNAME"
if [ -d "$DIR" ]; then
  echo "Removing previous ${DIR}..."
fi

./src/sdec-util create $CHAINNAME

./src/sdecd $CHAINNAME -daemon

./src/sdec-cli $CHAINNAME createkeypairs 1

ADDRESS=$(./src/sdec-cli $CHAINNAME createkeypairs 1 | grep "address" | cut -d "\"" -f4)

./src/sdec-cli $CHAINNAME grant $ADDRESS receive

