#! /bin/bash
g++ $1 -o "$1.out"
wait $! 
echo "FILE $1 -> compiled! & output:"
./"$1.out"
wait $!
rm "$1.out"