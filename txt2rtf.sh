printf "\ec\e[44;36m\n"
cat $1 | sed y/'{'/'['/ | sed y/'}'/']'/ | sed y/'\\'/'_'/ > $1.txt
./txt2rtf $1.txt > $1.rtf
