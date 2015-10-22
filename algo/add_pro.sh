#!/bin/sh
if [[ $1 == "" ]];then
    echo sh $0 APP_NAME
    exit 1
fi
if [ -f ${1}_unittest.cc ];then
    cp ${1}_unittest.cc ${1}_unittest.cc.bak
fi
if [ -f ${1}.cpp ];then
    cp ${1}.cpp ${1}.cpp.bak
fi
# convert foo_bar to FOO_BAR
uname=$(echo $1 | awk '{print toupper($0)}')
# convert foo_bar to FooBar
cname=$(echo $1 | awk -F_ '{for (i=1;i<=NF;++i){split($i,a,""); printf("%s", toupper(a[1])); for (k=2;k<=length(a);++k){printf("%s", a[k])}}}')
cp tpl_unittest.cc ${1}_unittest.cc
sed -i"" -e 's/AppTest/'$cname'Test/g' -e 's/APP/'$uname'/g' -e 's/app.cpp/'$1'.cpp/g' ${1}_unittest.cc
sed -i"" -e 's/APP = .*/APP = '$1'/g' Makefile

cp tpl_sol.cpp ${1}.cpp
sed -i"" -e 's/TPL_SOL/'$uname'/g' ${1}.cpp
