cat file.txt | awk 'BEGIN{SUBSEP=":"} { for(i=1;i<=NF;++i) a[NR SUBSEP i]=$i} END{for (i=1;i<=NF;++i) {for (j=1;j<NR;++j) printf("%s ", a[j SUBSEP i]); print a[NR SUBSEP i];}}'
