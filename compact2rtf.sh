printf "\ec\e[44;36m\n"
cat $1 | sed 's/\t/ /g' | sed 's/  / /g' | tr '\n' ' ' | tr '\r' ' '  > $1.2.rtf

