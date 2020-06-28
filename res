user@light1:~/test$ 
user@light1:~/test$ 
user@light1:~/test$ gst-launch-1.0  playbin uri=rtsp://192.168.10.1:8774/vtest.mp3
Setting pipeline to PAUSED ...
Pipeline is live and does not need PREROLL ...
Progress: (open) Opening Stream
Progress: (connect) Connecting to rtsp://192.168.10.1:8774/vtest.mp3
Progress: (open) Retrieving server options
Progress: (open) Retrieving media info
ERROR: from element /GstPlayBin:playbin0/GstURIDecodeBin:uridecodebin0/GstRTSPSrc:source: Unhandled error
Additional debug info:
gstrtspsrc.c(6161): gst_rtspsrc_send (): /GstPlayBin:playbin0/GstURIDecodeBin:uridecodebin0/GstRTSPSrc:source:
Service Unavailable (503)
ERROR: pipeline doesn't want to preroll.
Setting pipeline to PAUSED ...
Setting pipeline to READY ...
Setting pipeline to NULL ...
Freeing pipeline ...
user@light1:~/test$ 

