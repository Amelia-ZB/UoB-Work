#! /usr/bin/env bash
# How long til christmas?

echo 'Hello!'

CURRENT_DAY=$(date +%d)
CURRENT_MONTH=$(date +%_m)

TARGET_DAY=25
TARGET_MONTH=12

echo "$(($TARGET_MONTH - $CURRENT_MONTH)) months and $(($TARGET_DAY - $CURRENT_DAY)) days untill Christmas"