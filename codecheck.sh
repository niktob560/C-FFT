#!/bin/bash

if [[ -z "$1" ]]; then
    CERT=$(cppcheck cppcheck --addon=cert -q ./main.c 2>&1)
    INFO="Checked all"
else
    CERT=$(cppcheck cppcheck --addon=cert -q $1 2>&1)
    INFO="Checked $1"
fi

echo -e "\033[1;33mCERT CHECK:\033[0m"

if [[ -z "$CERT" ]]; then
    printf '\033[1;32m'
    CERT="OK"
else
    printf '\033[1;34m'
fi

echo -e "$INFO\n"$CERT'\033[0m'
