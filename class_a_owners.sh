#Check ownhers of class A domain

#!/bin/bash

for x in `seq 1 255`; do
	whois $x.0.0.0 | egrep '(CIDR|OrgName)' >> temp
              echo >> temp
done
egrep -v '(%|No address)' temp > temp2
cat -s temp2 > info.txt
rm temp*
