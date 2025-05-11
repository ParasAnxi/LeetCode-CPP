# Read from the file file.txt and print its transposed content to stdout.
awk '{for (i=1; i<=NF; i++) arr[i] = (arr[i] ? arr[i] " " : "") $i} END {for (i=1; i in arr; i++) print arr[i]}' file.txt