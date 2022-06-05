#!/bin/bash

#コード引用元:
#https://qiita.com/b4b4r07/items/dcd6be0bb9c9185475bb (オプション処理)
#コマンド参考:
#https://rcmdnk.com/blog/2018/09/05/computer-bash-zsh/#-x--0-9- (数字判定)

#memo:変数にコマンド代入は、$や|の扱い難しい、echoしてbashに渡すと良さそう、<-shell変数関係の異常動作あり?sourceのほうがいいかも
#memo: ; や \ などを変数内に入れる時は最後まで""で囲う
PROGNAME=$0
min=0
MAX=255
integer=T
protocol=M
number=1
scale=20
##########オプション処理##########
for OPT in "$@"
do
    case $OPT in
        -m | --min)
            if expr "$2" : "-\?[0-9]\+\.\?[0-9]*$" >&/dev/null;then 
                min=$2
            elif [[ -z "$2" ]] || [[ "$2" =~ ^-+ ]]; then
                echo "$PROGNAME: option requires an argument -- $1" 1>&2
                exit 1
            else
                echo "$PROGNAME: invalid arguments -- $1" 1>&2
                 exit 1
            fi
            shift 2
            ;;
        -M | --MAX)
            if expr "$2" : "-\?[0-9]\+\.\?[0-9]*$" >&/dev/null;then 
                MAX=$2
            elif [[ -z "$2" ]] || [[ "$2" =~ ^-+ ]]; then
                echo "$PROGNAME: option requires an argument -- $1" 1>&2
                exit 1
            else
                echo "$PROGNAME: invalid arguments -- $1" 1>&2
                exit 1
            fi
            shift 2
            ;;
        -i | --integer)
            if [[ -z "$2" ]] || [[ "$2" =~ ^-+ ]]; then
                echo "$PROGNAME: option requires an argument -- $1" 1>&2
                exit 1
            elif [[ $2 == T ]]; then
                integer=T
            elif [[ $2 == F ]]; then    
                integer=F
            else
                echo "$PROGNAME: invalid arguments -- $1" 1>&2
                exit 1
            fi
            shift 2
            ;;
        -p | --protocol)
            if [[ -z "$2" ]] || [[ "$2" =~ ^-+ ]]; then
                echo "$PROGNAME: option requires an argument -- $1" 1>&2
                exit 1
            elif [[ $2 == M ]]; then
                protocol=M
            elif [[ $2 == U ]]; then
                protocol=U
            elif [[ $2 == R ]]; then
                protocol=R
            else
                echo "$PROGNAME: invalid arguments -- $1" 1>&2
                exit 1
            fi
            shift 2
            ;;
        -n | --number)
            if [[ -z "$2" ]] || [[ "$2" =~ ^-+ ]]; then
                echo "$PROGNAME: option requires an argument -- $1" 1>&2
                exit 1
            elif expr "$2" : "[0-9]\+$" >&/dev/null;then 
                number=$2
            else
                echo "$PROGNAME: invalid arguments -- $1" 1>&2
                exit 1 
            fi
            shift 2
            ;;   
         -s | --scale)
            if [[ -z "$2" ]] || [[ "$2" =~ ^-+ ]]; then
                echo "$PROGNAME: option requires an argument -- $1" 1>&2
                exit 1
            elif expr "$2" : "[0-9]*$" >&/dev/null;then
                scale=$2
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

##########エラー##########
if [[ $(echo "if ($min >= $MAX) 1"|bc -l) -eq 1 ]];then
    echo "$PROGNAME: error1!" 1>&2
    exit 1
elif [[ $(echo "if ($MAX-($min) > 4294967295) 1"|bc -l) -eq 1 ]];then
    echo "$PROGNAME: error2!" 1>&2
    exit 1
fi
##########エラー##########

##########乱数生成方法指定##########
if [[ $protocol = M ]];then
    tmp1='echo $number|./ransu2.out'
elif [[ $protocol = U ]]; then
    tmp1='od -An -tu4 -N$((4*$number)) /dev/urandom|tr -s [:blank:] "\n"|grep -G ^[1-9]'
elif [[ $protocol = R ]]; then
    tmp1='od -An -tu4 -N$((4*$number)) /dev/random|tr -s [:blank:] "\n"|grep -G ^[1-9]'
else
    echo "$PROGNAME: error3!" 1>&2
    exit 1
fi
##########乱数生成方法指定##########

##########出力##########
if [[ $integer = T ]];then
    range=$(echo "$MAX-($min)"|bc)
        if expr "$range" : ".[0-9]\+$">&/dev/null;then 
            range=0$range    
        elif expr "$range" : "-.[0-9]\+$">&/dev/null;then 
            range=-0${range#-}
        fi
    tmp2='yes scale=0";"'
    tmp3='yes "%("$range+1")+("$MAX-$range")"'
    paste <(source <(echo $tmp2)|head -$number) <(source <(echo $tmp1)) <(source <(echo $tmp3)|head -$number)|tr -d [:blank:]|bc
elif [[ $integer = F ]]; then
    range=$(echo "scale=$(($scale+1));$MAX-($min)"|bc)
        if expr "$range" : ".[0-9]\+$">&/dev/null;then 
            range=0$range    
        elif expr "$range" : "-.[0-9]\+$">&/dev/null;then 
            range=-0${range#-}
        fi
    tmp2='yes "scale=$scale"";""("'
    tmp3='yes "*$range/4294967295+$min)/1"'
    paste <(source <(echo $tmp2)|head -$number) <(source <(echo $tmp1)) <(source <(echo $tmp3)|head -$number)|tr -d [:blank:]|bc|sed -e s/"^\."/0./g -e s/"^-\."/-0./g
fi
##########出力##########

exit 0
