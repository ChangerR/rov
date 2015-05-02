#! /usr/bin/bash
if [ $# -le 3 ] ;  then
	echo "Usage: start_camera [device] [resolution] [framerate] [port] [yuv]"
	exit 1
fi

VIDEO_DEVICE=$1
RESOLUTION=$2
FRAMERATE=$3
PORT=$4
YUV=$5

if [ ! -d /tmp/_openrov ] ; then
	mkdir /tmp/_openrov
fi

echo "+1" > /tmp/_openrov/status

if test "$YUV" = "yuv" ;
then
	YUV="-y"
else
	YUV=
fi

if [ ! -f $VIDEO_DEVICE ] ;
then
	VIDEO_DEVICE=/dev/video1
fi

if [ ! -f $VIDEO_DEVICE ] ;
then
	echo $YUV
	mkdir /tmp/_openrov
	echo "error" > /tmp/_openrov/status
	exit 1
fi



mjpg_stream -i "/usr/local/lib/input_uvc.so $YUV -r $RESOLUTION -d $VIDEO_DEVICE -f $FRAMERATE" -o "/usr/local/lib/output_http.so -p $PORT"