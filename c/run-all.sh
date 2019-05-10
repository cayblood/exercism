#!/bin/bash

for filename in **/Makefile; do
  pushd $(dirname $filename)
  make
  popd
done
