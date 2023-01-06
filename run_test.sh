./pathfinder test/$1 > temp
diff temp test/$1_correct > correct

echo -en ''$1': '

if cat correct | grep -q '>'
then echo '\e[1;31;40mNOT PASSED\e[0m'
else echo '\e[1;32;40mPASSED\e[0m'
fi

rm correct
rm temp
