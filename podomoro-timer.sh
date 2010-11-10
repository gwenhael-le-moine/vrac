#!/bin/sh

# in minutes
WORKING_TIME=42 #Podomoro Technique™'s default is 25
RELAX_TIME=18 #Podomoro Technique™'s default is 5

function notify() {
    DELAY=5 # in seconds
    ICON=/usr/share/icons/Tango/32x32/actions/appointment.png

    notify-send \
        --urgency=critical \
        --expire-time=$(( $DELAY * 1000)) \
        --icon=$ICON \
        "Podomoro says" \
        $1
}

while true; do
    sleep $(( $WORKING_TIME * 60 ))
    notify "Time to go for a walk"
    sleep $(( $RELAX_TIME * 60 ))
    notify "Back to work"
done
