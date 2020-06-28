#include <stdio.h>
#include <string.h>
#include <gst/gst.h>
#include <gst/rtsp-server/rtsp-server.h>


#define MAX_MEDIA                 100
#define DEFAULT_RTSP_PORT         "8774"
#define DEFAULT_RTSP_ADDRESS      "127.0.0.1"
#define DEFAULT_RTSP_MEDIA_DIR    "~/Videos"

int main (int argc, char *argv[])
{
static char *port = (char *) DEFAULT_RTSP_PORT;
static char *address = (char *) DEFAULT_RTSP_ADDRESS;

  GMainLoop *loop;
  GstRTSPServer *server;
  GstRTSPMountPoints *mounts;
  GstRTSPMediaFactory *factory1, *factory2;
  GError *error = NULL;
  gchar *str1, *str2;





  gst_init (NULL,NULL);
  loop = g_main_loop_new (NULL, FALSE);

  server = gst_rtsp_server_new ();
  factory1 = gst_rtsp_media_factory_new ();
  factory2 = gst_rtsp_media_factory_new ();
  g_object_set (server, "service", port, NULL);
  g_object_set (server, "address", address, NULL);
//===============================================================================================================

  mounts = gst_rtsp_server_get_mount_points (server);


  str1 = g_strdup_printf ("( "
      "filesrc location=\"%s\" ! qtdemux name=d "
      "d. ! queue ! rtph264pay pt=96 name=pay0 "
      "d. ! queue ! rtpmp4apay pt=97 name=pay1 " ")", "/home/dawod/Videos/vtest.mp4");

  /*
  str2 = g_strdup_printf (
		  "(" "filesrc location=\"%s\" !" "mad ! audioconvert !  rtpL16pay name=pay0 pt=96 "")","/home/dawod/Videos/vtest.mp3");

  */

/*
 rtpL16pay
 rtpL24pay
 rtpamrpay
 rtpg722pay
 rtpg723pay
 rtpg729pay
 rtpvorbispay

 rtpopuspay
 * */


  str2 = g_strdup_printf (
		  "(" "filesrc location=\"%s\" !" "mad ! audioconvert !  rtpL16pay name=pay0 pt=96 "")","/home/dawod/Videos/out.wav");

  /* 
  str2 = g_strdup_printf ("( "
      "filesrc location=\"%s\" ! qtdemux name=d "
      "d. ! queue ! rtph263ppay pt=96 name=pay0 "
      "d. ! queue ! rtpL16pay name=pay1 pt=97 " ")", "/home/dawod/Videos/vtest.mp3");
 */
  



  gst_rtsp_media_factory_set_launch (factory1, str1);
  gst_rtsp_media_factory_set_launch (factory2, str2);

  gst_rtsp_mount_points_add_factory (mounts, "/vtest.mp4", factory1);
  gst_rtsp_mount_points_add_factory (mounts, "/vtest.mp3", factory2);


//===============================================================================================================
  // / don't need the ref to the mapper anymore
  g_object_unref (mounts);
  g_free (str1);
  g_free (str2);

  // / attach the server to the default maincontext
  gst_rtsp_server_attach (server, NULL);

  // / start serving
  g_print ("stream ready at rtsp://127.0.0.1:%s/film\n", port);
  g_main_loop_run (loop);

  return 0;
}
