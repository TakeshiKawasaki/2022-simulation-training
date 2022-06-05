#!/bin/bash

#コード引用元:
#https://qiita.com/b4b4r07/items/dcd6be0bb9c9185475bb (オプション処理)
PROGNAME=$0
Xtilde0=0
Vtilde0=1
tMAX=100
lMAX=1000
for OPT in "$@"
do
    case $OPT in
        -x | --Xtilde0)
            if expr "$2" : "-\?[0-9]\+\.\?[0-9]*$" >&/dev/null;then 
                Xtilde0=$2
            elif [[ -z "$2" ]] || [[ "$2" =~ ^-+ ]]; then
                echo "$PROGNAME: option requires an argument -- $1" 1>&2
                exit 1
            else
                echo "$PROGNAME: invalid arguments -- $1" 1>&2
                exit 1
            fi
            shift 2
            ;;
        -v | --Vtilde0)
            if expr "$2" : "-\?[0-9]\+\.\?[0-9]*$" >&/dev/null;then 
                Vtilde0=$2
            elif [[ -z "$2" ]] || [[ "$2" =~ ^-+ ]]; then
                echo "$PROGNAME: option requires an argument -- $1" 1>&2
                exit 1
            else
                echo "$PROGNAME: invalid arguments -- $1" 1>&2
                exit 1
            fi
            shift 2
            ;;
        -M | --tMAX)
            if expr "$2" : "-\?[0-9]\+\.\?[0-9]*$" >&/dev/null;then 
                tMAX=$2
            elif [[ -z "$2" ]] || [[ "$2" =~ ^-+ ]]; then
                echo "$PROGNAME: option requires an argument -- $1" 1>&2
                exit 1
            else
                echo "$PROGNAME: invalid arguments -- $1" 1>&2
                exit 1
            fi
            shift 2
            ;;
        -l | --lMAX)
            if expr "$2" : "[0-9]\+\.\?[0-9]*$" >&/dev/null;then 
                lMAX=$2
            elif [[ -z "$2" ]] || [[ "$2" =~ ^-+ ]]; then
                echo "$PROGNAME: option requires an argument -- $1" 1>&2
                exit 1
            else
                echo "$PROGNAME: invalid arguments -- $1" 1>&2
                exit 1
            fi
            shift 2
            ;;
        -- | -)
            shift 1
            param+=( "$@" )
            break
            ;;
        -[^0-9]*)
            echo "$PROGNAME: illegal option -- '$(echo $1 | sed 's/^-*//')'" 1>&2
            exit 1
            ;;

    esac
done
##########オプション処理##########

##########関数定義##########
function fx () {
bc -l << BC
l=1
x=$1
v=$2
t0td=$3
tmax=$4
lmax=$5
i=$6
ttilde=tmax/lmax
while (l<=lmax){
x+i*ttilde*l
v=v*(1-t0td*ttilde)-x*ttilde
x=x+ttilde*v
l=l+1}
BC
}
##########関数定義##########

##########出力##########
echo "T,X1,X2,X3"|cat - <(paste <(fx 0 0 0 $tMAX $lMAX 1|tr [:blank:] \n) <(fx $Xtilde0 $Vtilde0 1 $tMAX $lMAX 0|tr [:blank:] \n) <(fx $Xtilde0 $Vtilde0 2 $tMAX $lMAX 0|tr [:blank:] \n) <(fx $Xtilde0 $Vtilde0 3 $tMAX $lMAX 0|tr [:blank:] \n) |sed -e s/"\t\."/,0./g -e s/"\t-\."/,-0./g -e s/"^\."/0./g -e s/"^-\."/-0./g -e s/"\t"/,/g )
##########出力##########

exit 0
