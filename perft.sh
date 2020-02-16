#!/bin/bash
fen=$1
qfen="1r3rk1/p1ppq1b1/1n2pnpN/3P4/1p2P3/2N2Q1p/PPPB1PPP/R2BKbR1 b Q - 0 1"
cfen="r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq - 0 1"

# QPerft
~/projects/qperft/a.out 3 -2 "$qfen" | grep "2\. " | awk '{print $2 " " $5}' | sort > ./output_perft

numlines=$(~/projects/qperft/a.out 3 -2 "$qfen" | grep "2\. " | awk '{print $2 " " $5}' | sort | wc -l)

echo "Total: $numlines" >> ./output_perft



# Challenger
~/projects/challenger/build/perft_challenger "$cfen" | awk '{print $1 " " $3}' | sort > ./output_perft_challenger

numchallengerlines=$(~/projects/challenger/build/perft_challenger "$cfen" | awk '{print $1 " " $3}' | sort | wc -l)

echo "Total: $numchallengerlines" >> ./output_perft_challenger

echo "Qperft          Challenger     Move     Number"
paste ./output_perft ./output_perft_challenger > compare.txt 

cat compare.txt | while read line
do
    v1=$(echo $line | awk '{print $2}')
    v2=$(echo $line | awk '{print $4}')
    m1=$(echo $line | awk '{print $1}')
    m2=$(echo $line | awk '{print $3}')
    if [[ $v1 == $v2 ]]; then
        echo $line | awk '{print $1 " " $2 "       " $3 " "$4}'
    else
        if [[ $m1 == $m2 ]]; then
            echo "$line                ***"
        else
            echo "$line       ***      ***"
        fi
    fi
done

rm ./output_perft ./output_perft_challenger ./compare.txt
