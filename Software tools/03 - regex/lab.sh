grep "Q" words

grep -i "^r" words

grep -i 'j$' words

grep -ic 'q' words

grep -i -m 5 'cl' words

grep -i '[^c]kp' words

grep -i '^..$' words | tail -15

grep -i '^[^aeiou]\{3\}$' words

grep -i '^..e.ded' words

grep -i '^p\(.*a\)\{4\}' words



grep -i 'ay$' words | sed 's/day/week/'

colordiff -y (grep -i 'ay$' words | psub) (grep -i 'ay$' words | sed 's/day/week/' | psub)

grep -i '[wd]ay$' words | sed 's/\(.*\)\([wd]ay\)/\2 (\1)/'


set PATTERN 'hello'
set TEXT 'hello
hello2'
colordiff -y (echo "$TEXT" | grep $PATTERN | psub) (echo "$TEXT" | grep -w $PATTERN | psub)



'^[A-Z]\{1,2\}[0-9][A-Z0-9]\{0,1\} \{0,1\}[0-9][A-Z]\{2\}$'