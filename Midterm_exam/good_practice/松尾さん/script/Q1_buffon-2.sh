#!/bin/bash
#円周率はウィキペディアより引用
i=100
while [ $i -le 100000000 ];do
echo $i >>./tmp.txt
i=$((i*4/3))
done
echo 100000000 >>./tmp.txt

cat <(echo "n,data,pi") <(cat ./tmp.txt|xargs -I prm -P 10 bash -c 'echo prm","$(echo prm/$(paste <(./ransu2.sh -m 0 -M 2 -i F -n prm) <(yes "-"|head -prm) <(echo prm|./maru2.out |sed -e "s/A/sqrt(1\/(1+(/g" -e "s/B/\/\(/g" -e "s/e/\*10\^/g" -e "s/C/\)\/1\)^2\)\)/g"|bc -l)|tr -d [:blank:]|bc|grep "-"|wc -l)|bc -l)","3.14159265358979323846')

rm ./tmp.txt
