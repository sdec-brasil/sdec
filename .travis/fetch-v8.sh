#!/bin/bash

set -x

# fetch V8 if necessary
if [ ! -d "./v8build/v8" ]; then

  cd ./v8build
  fileid="1Ic7yQQGzkJrp3c42L-0Z6SM5bqfyGx9S"
  filename="macos-v8.tar.gz"
  curl -c ./cookie -s -L "https://drive.google.com/uc?export=download&id=${fileid}" > /dev/null
  curl -Lb ./cookie "https://drive.google.com/uc?export=download&confirm=`awk '/download/ {print $NF}' ./cookie`&id=${fileid}" -o ${filename}
  gunzip -c ${filename} | tar -xv

fi
