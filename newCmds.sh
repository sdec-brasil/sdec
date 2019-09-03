#!/bin/sh

CHAINNAME="newcmdssh"
DIR="$HOME/.sdec/$CHAINNAME"
if [ -d "$DIR" ]; then
  echo "Removing previous ${DIR}..."
  rm -rf $DIR
fi

sleep 1
./src/sdec-util create $CHAINNAME

sleep 1
./src/sdecd $CHAINNAME -daemon

sleep 3
ADDRESS=$(./src/sdec-cli $CHAINNAME createkeypairs 1 | grep "address" | cut -d "\"" -f4)

sleep 1
./src/sdec-cli $CHAINNAME grant $ADDRESS receive

TXID=$(./src/sdec-cli $CHAINNAME newcompany $ADDRESS "15.811.232/0001-05" '{"teste": "teste"}')

./src/sdec-cli $CHAINNAME getrawtransaction $TXID true

./src/sdec-cli $CHAINNAME stop
