#!/usr/bin/env bash

for f in include/*.h src/*.c; do
    echo -e "\n\n// ===== $f =====\n"
    cat "$f"
done > all.txt
