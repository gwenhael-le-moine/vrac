#!/bin/sh

SYSPATH=/sys/class/backlight/intel_backlight

KNOB=$SYSPATH/brightness

CURRENT=$(cat $SYSPATH/actual_brightness)
MAX=$(cat $SYSPATH/max_brightness)
MIN=100
VALUE=$CURRENT

STEP=100

case "$1" in
	"up")
	VALUE=$(expr $CURRENT + $STEP)
	[[ $VALUE > $MAX ]] && VALUE=$MAX
	;;
	"down")
	VALUE=$(expr $CURRENT - $STEP)
	[[ $VALUE < $MIN ]] && VALUE=$MIN
	;;
esac

echo $VALUE > $KNOB
