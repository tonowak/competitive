#!/bin/bash

MEM_LIMIT="1024m"

if [ $# -lt 1 ]; then
    echo "Usage: $0 <program_to_test> [args...]"
fi

SELF="$(readlink -f "$0")"
SELF_DIR="$(dirname "$SELF")"

if [ -n "$MEM_LIMIT" ]; then
  MEASURE_MEM=1
fi

OPTS=""

if [ -z "$MEASURE_MEM" ]; then
  OPTS+=" --seccomp off"
  OPTS+=" --ptrace off"
fi

OPTS+=" --mount-namespace off"
OPTS+=" --pid-namespace off"
OPTS+=" --uts-namespace off"
OPTS+=" --ipc-namespace off"
OPTS+=" --net-namespace off"
OPTS+=" --capability-drop off --user-namespace off"
OPTS+=" -s"

if [ -n "$MEM_LIMIT" ]; then
    OPTS+=" -m $MEM_LIMIT"
fi

TMPFILE="$(mktemp)"

"$SELF_DIR/sio2jail" -f 3 -o oiaug $OPTS -- "$@" 3>"$TMPFILE"

read STATUS CODE TIME NVM MEM SYSC <"$TMPFILE"

exec >&2

TIME_A="$(bc <<< "${TIME} / 1000")"
TIME_B="$(bc <<< "${TIME} % 1000")"

if [ $(bc <<< "${TIME_A}==0 && ${TIME_B}<=200") -eq 0 ]; then
	printf "${TIME_A}."
	if (( $TIME_B < 10 )); then printf '0'; fi
	if (( $TIME_B < 100 )); then printf '0'; fi
	printf "${TIME_B}s "
fi

if [ -n "$MEASURE_MEM" ]; then
	MEM_KB="$(bc <<< "${MEM} / 1024")"
	if (( $MEM_KB >= 10)); then
		printf "${MEM_KB}mB "
	fi
fi

if [ "$STATUS" != "OK" ]; then
	printf "$STATUS ("
	tail -n+2 "$TMPFILE" | tr -d '\n'
	printf ")"
fi

rm "$TMPFILE"
