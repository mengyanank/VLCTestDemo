/*
 * VISCA(tm) Camera Control Library
 * Copyright (C) 2002 Damien Douxchamps 
 *
 * Written by Damien Douxchamps <ddouxchamps@users.sf.net>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/*
Commands without parameter:
===========================
set_zoom_tele            (set the zoom to maximum)
set_zoom_wide            (set the zoom to minimum)
set_zoom_stop            (stop zooming)
set_focus_far            (set the focus to far)
set_focus_near           (set the focus to near)
set_focus_stop           (stop focusing)
set_focus_one_push       (not for D30)
set_focus_infinity       (not for D30)
set_focus_autosense_high (not for D30)
set_focus_autosense_low  (not for D30)
set_whitebal_one_push    (push trigger for whitebalance in OnePush mode)
set_rgain_up             (not for D30)
set_rgain_down           (not for D30)
set_rgain_reset          (not for D30)
set_bgain_up             (not for D30)
set_bgain_down           (not for D30)
set_bgain_reset          (not for D30)
set_shutter_up           (increase the shutter speed, available only with shutter_priority or AE_Manual)
set_shutter_down         (decrease the shutter speed, available only with shutter_priority or AE_Manual)
set_shutter_reset        (reset the shutter speed, available only with shutter_priority or AE_Manual)
set_iris_up              (open up the iris, available only with iris_priority or AE_Manual)
set_iris_down            (close the iris, available only with iris_priority or AE_Manual)
set_iris_reset           (reset the iris, available only with iris_priority or AE_Manual)
set_gain_up              (increase the gain, available only with AE_Manual)
set_gain_down            (decrease the gain, available only with AE_Manual)
set_gain_reset					 (reset the gain, available only with AE_Manual)
set_bright_up					 (brighten the image, available only with bright_mode)
set_bright_down					 (darken the image, available only with bright_mode)
set_bright_reset				 (reset the image brightness, available only with bright_mode)
set_aperture_up					 (not for D30)
set_aperture_down				 (not for D30)
set_aperture_reset				 (not for D30)
set_exp_comp_up					 (not for D30)
set_exp_comp_down				 (not for D30)
set_exp_comp_reset				 (not for D30)
set_title_clear					 (not for D30)
set_irreceive_on				 (enable IR remote controller)
set_irreceive_off				 (disable IR remote controller)
set_irreceive_onoff				 (toggle IR remote controller)
set_pantilt_home				 (set pan/tilt position to center)
set_pantilt_reset				 (initialize pan/tilt motors)
set_pantilt_limit_downleft_clear (remove pan/tilt limits for lower left position)
set_pantilt_limit_upright_clear  (remove pan/tilt limits for upper right position)
set_datascreen_on				 (show data display)
set_datascreen_off				 (hide data display)
set_datascreen_onoff			 (toggle data display)

Commands with one boolean parameter (0|1):
==========================================
set_power             (set standby power state)
set_keylock           (set or release keylock)
set_dzoom             (not for D30)
set_focus_auto        (turn autofocus on or off)
set_exp_comp_power    (not for D30)
set_slow_shutter_auto (not for D30)
set_backlight_comp    (turn backlight compensation on or off)
set_zero_lux_shot     (not for D30)
set_ir_led            (not for D30)
set_mirror            (not for D30)
set_freeze            (not for D30)
set_display           (not for D30)
set_date_display      (not for D30)
set_time_display      (not for D30)
set_title_display     (not for D30)

Commands with one integer parameter:
====================================
set_zoom_tele_speed <speed>      (set the zoom to maximum with a speed between 2 and 7)
set_zoom_wide_speed <speed>      (set the zoom to minimum with a speed between 2 and 7)
set_zoom_value <zoom>            (set the zoom to the given value between 0 and 1023)
set_focus_far_speed <speed>      (not for D30)
set_focus_near_speed <speed>     (not for D30)
set_focus_value <focus>          (set the focus to the given value between 1000 and 40959)
set_focus_near_limit <limit>     (not for D30)
set_whitebal_mode <mode>         (set the whitebalance mode to 0: Auto, 1: Indoor, 2: Outdoor, 3: OnePush)
set_rgain_value <value>          (not for D30)
set_bgain_value <value>          (not for D30)
set_shutter_value <value>        (set the shutter value between 0: 1/60 and 27: 1/10000)
set_iris_value <value>           (set the iris opening to a value between 0: closed and 17: F1.8)
set_gain_value <value>           (set the gain value between 1: 0dB and 7: +18dB)
set_bright_value <value>         (not for D30)
set_aperture_value <value>       (not for D30)
set_exp_comp_value <value>       (not for D30)
set_auto_exp_mode <mode>         (set the AE mode to 0: Full Auto, 3: Manual, 10: Shutter priority, 11: Iris priority, 13: Bright Mode)
set_wide_mode <mode>             (not for D30)
set_picture_effect <mode>        (not for D30)
set_digital_effect <mode>        (not for D30)
set_digital_effect_level <level> (not for D30)
memory_set <channel>             (save the current position to channel 0 to 5)
memory_recall <channel>          (recall the current position from channel 0 to 5)
memory_reset <channel>           (reset a channel 0 to 5)

Commands with two integer parameters:
=====================================
set_zoom_and_focus_value <zoom> <focus>             (not for D30, zoom 0 to 1023, focus 1000 to 40959)
set_pantilt_up <pan_speed> <tilt_speed>             (move up, pan_speed from 1 to 24, tilt speed from 1 to 20)
set_pantilt_down <pan_speed> <tilt_speed>           (move down, pan_speed from 1 to 24, tilt speed from 1 to 20)
set_pantilt_left <pan_speed> <tilt_speed>           (move left, pan_speed from 1 to 24, tilt speed from 1 to 20)
set_pantilt_right <pan_speed> <tilt_speed>          (move right, pan_speed from 1 to 24, tilt speed from 1 to 20)
set_pantilt_upleft <pan_speed> <tilt_speed>         (move up and left, pan_speed from 1 to 24, tilt speed from 1 to 20)
set_pantilt_upright <pan_speed> <tilt_speed>        (move up and right, pan_speed from 1 to 24, tilt speed from 1 to 20)
set_pantilt_downleft <pan_speed> <tilt_speed>       (move down and left, pan_speed from 1 to 24, tilt speed from 1 to 20)
set_pantilt_downright <pan_speed> <tilt_speed>      (move down and right, pan_speed from 1 to 24, tilt speed from 1 to 20)
set_pantilt_stop <pan_speed> <tilt_speed>           (stop moving, pan_speed from 1 to 24, tilt speed from 1 to 20)
set_pantilt_limit_upright <pan_limit> <tilt_limit>  (limit movement upper right corner, pan limit: -879 to 880, tilt limit: -299 to 300)
set_pantilt_limit_downleft <pan_limit> <tilt_limit> (limit movement lower left corner, pan limit: -879 to 880, tilt limit: -299 to 300)

Commands with four integer parameters:
======================================
set_pantilt_absolute_position <pan_speed> <tilt_speed> <pan_position> <tilt_position> (set position, pan_speed from 1 to 24, tilt speed from 1 to 20, pan_pos: -879 to 880, tilt_pos: -299 to 300)
set_pantilt_relative_position <pan_speed> <tilt_speed> <pan_position> <tilt_position> (set position, pan_speed from 1 to 24, tilt speed from 1 to 20, pan_pos: -879 to 880, tilt_pos: -299 to 300)
set_title_params <vposition> <hposition> <color> <blink> (not for D30, set title params)

Commands with five parameters:
==============================
set_date_time <year> <month> <day> <hour> <minute>       (not for D30, set date and time)
set_title <vposition> <hposition> <color> <blink> <text> (not for D30, set title params and title text)

Commands that return one boolean value:
=======================================
get_power          (returns 1 if in standby mode, 0 otherwise)
get_dzoom          (not for D30)
get_focus_auto     (returns 1 if autofocus, 0 otherwise)
get_exp_comp_power (not for D30)
get_backlight_comp (returns 1 if backlight compensation is on, 0 otherwise)
get_zero_lux_shot  (not for D30)
get_ir_led         (not for D30)
get_mirror         (not for D30)
get_freeze         (not for D30)
get_display        (not for D30)
get_datascreen     (returns 1 if a datascreen is displayed, 0 otherwise)

Commands that return one integer value:
=======================================
get_zoom_value           (returns a value between 0 and 1023)
get_focus_value          (returns a value between 1000 and 40959)
get_focus_auto_sense     (not for D30)
get_focus_near_limit     (not for D30)
get_whitebal_mode        (returns the whitebalance mode: 0: Auto, 1: Indoor, 2: Outdoor, 3: OnePush)
get_rgain_value          (not for D30)
get_bgain_value          (not for D30)
get_auto_exp_mode        (returns the auto exposure mode:
                           0: Full Auto, 3: Manual, 10: Shutter priority, 11: Iris priority, 13: Bright Mode)
get_slow_shutter_auto    (not for D30)
get_shutter_value        (returns the shutter value between 
                          0: 1/60 and 27: 1/10000)
get_iris_value           (returns the iris value between 
                          0: closed and 17: F1.8
get_gain_value           (returns the gain value between 1: 0dB and 7: +18dB)
get_bright_value         (not for D30)
get_exp_comp_value       (not for D30)
get_aperture_value       (not for D30)
get_wide_mode            (not for D30)
get_picture_effect       (not for D30)
get_digital_effect       (not for D30)
get_digital_effect_level (not for D30)
get_memory               (returns the current memory preset position 0 to 5)
get_id                   (returns the camera id)
get_videosystem          (returns the video sytstem: 0 for NTSC, 1 for PAL)
get_pantilt_mode         (returns the pantilt status, what is this?)

Commands that return two integer values:
========================================
get_pantilt_maxspeed (returns max_pan_speed and max_tilt_speed)
get_pantilt_position (returns pan_position: -860..862 and tilt_position: -281..283)

==================================================
Commands not yet in libVISCA:
==================================================

Commands without parameter:
===========================
set_at_mode_onoff           (Target tracking mode On/Off)
set_at_ae_onoff             (Auto exposure for target tracking mode On/Off)
set_at_autozoom_onoff       (Auto zoom for target tracking mode On/Off)
set_atmd_framedisplay_onoff (Frame display for target tracking or 
                             motion detection mode On/Off)
set_at_frameoffset_onoff    (Frame offset control for 
                             target tracking mode On/Off)
set_atmd_startstop          (Start or stop target tracking or 
                             motion detection)
set_at_chase_next           (Select target tracking chase mode 1/2/3)
set_md_mode_onoff           (Motion detection mode On/Off)
set_md_frame                (Set detection area/size for motion detection)
set_md_detect               (Select detecting frame for motion detection, 
                             1, 2 or 1+2)
set_at_lostinfo             (returns when target is lost 
                             in target tracking mode)
set_md_lostinfo             (returns when motion is detected within frame 
                             in motion detection mode)
set_md_measure_mode1_onoff  (Set motion detection measure mode 1 On/Off)
set_md_measure_mode2_onoff  (Set motion detection measure mode 2 On/Off)

Commands with one boolean parameter (0|1):
==========================================
set_at_mode           (Target tracking mode On/Off)
set_at_ae             (Auto exposure for target tracking mode On/Off)
set_at_autozoom       (Auto zoom for target tracking mode On/Off)
set_atmd_framedisplay (Frame display for target tracking or 
                       motion detection mode On/Off)
set_at_frameoffset    (Frame offset control for target tracking mode On/Off)
set_md_mode           (Motion detection mode On/Off)
set_md_measure_mode1  (Set motion detection measure mode 1 On/Off)
set_md_measure_mode2  (Set motion detection measure mode 2 On/Off)

Commands with one integer parameter:
====================================
set_wide_con_lens <conversion> (AT compensation when a wide conversion lens is installed, 0: No conversion to 7: X0.6 conversion)
set_at_chase <chase_mode>      (Select target tracking chase mode 0, 1 or 2)
set_at_entry <entry>           (Select target study mode for target tracking available modes: 0 to 3)
set_md_adjust_ylevel <level>   (adjust level of detection from 0 to 15)
set_md_adjust_huelevel <level> (adjust level of detection from 0 to 15)
set_md_adjust_size <level>     (adjust level of detection from 0 to 15)
set_md_adjust_disptime <level> (adjust level of detection from 0 to 15)
set_md_adjust_refmode <mode>   (set refreshmode from 0 to 2)
set_md_adjust_reftime <time>   (set refreshtime from 0 to 15)

Commands that return one boolean value:
=======================================
get_keylock (returns 1 if keylock is set, 0 otherwise)

Commands that return one integer value:
=======================================
get_wide_con_lens     (returns which wide conversion lens is installed, 0: No conversion to 7: X0.6 conversion)
get_atmd_mode         (returns the current AT or MD mode: 0: Normal mode, 1: AT mode, 2: MD mode)
get_at_mode           (returns the AT status, see D30/31 Command List for details
get_at_entry          (returns the AT entry: 0 to 3)
get_md_mode           (returns the MD status, see D30/31 Command List for details)
get_md_ylevel         (returns level of detection from 0 to 15)
get_md_huelevel       (returns level of detection from 0 to 15)
get_md_size           (returns level of detection from 0 to 15)
get_md_disptime       (returns level of detection from 0 to 15)
get_md_refmode        (returns refreshmode from 0 to 2)
get_md_reftime        (returns refreshtime from 0 to 15)

Commands that return three integer values:
==========================================
get_at_obj_pos (returns the center position of the detection frame divided by 48x30 pixels and a status: 0=Setting, 1=Tracking, 2=Lost)
get_md_obj_pos (returns the center position of the detection frame divided by 48x30 pixels and a status: 1=UnDetect, 2=Detected)
*/
// #include "stdafx.h"
#include "libvisca.h"


#ifdef VISCA_WIN
# ifdef _DEBUG
#  define DEBUG 1
# else
#  undef DEBUG
# endif
#endif

/********************************/
/*      PRIVATE FUNCTIONS       */
/********************************/

void
_VISCA_append_byte(VISCAPacket_t *packet, unsigned char byte)
{
  packet->bytes[packet->length]=byte;
  (packet->length)++;
}


void
_VISCA_init_packet(VISCAPacket_t *packet)
{
  // we start writing at byte 1, the first byte will be filled by the
  // packet sending function. This function will also append a terminator.
  packet->length=1;
}


VISCA_API uint32_t
_VISCA_get_reply(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  // first message: -------------------
  if (_VISCA_get_packet(iface)!=VISCA_SUCCESS) 
    return VISCA_FAILURE;
  iface->type=iface->ibuf[1]&0xF0;

  // skip ack messages
  while (iface->type==VISCA_RESPONSE_ACK)
    {
      if (_VISCA_get_packet(iface)!=VISCA_SUCCESS) 
        return VISCA_FAILURE;
      iface->type=iface->ibuf[1]&0xF0;
    }
 
  switch (iface->type)
    {
    case VISCA_RESPONSE_CLEAR:
      return VISCA_SUCCESS;
      break;
    case VISCA_RESPONSE_ADDRESS:
      return VISCA_SUCCESS;
      break;
    case VISCA_RESPONSE_COMPLETED:
      return VISCA_SUCCESS;
      break;
    case VISCA_RESPONSE_ERROR:
      return VISCA_SUCCESS;
      break;
    }
  return VISCA_FAILURE;
}

VISCA_API uint32_t
_VISCA_send_packet_with_reply(VISCAInterface_t *iface, VISCACamera_t *camera, VISCAPacket_t *packet)
{
  if (_VISCA_send_packet(iface,camera,packet)!=VISCA_SUCCESS)
    return VISCA_FAILURE;

  if (_VISCA_get_reply(iface,camera)!=VISCA_SUCCESS)
    return VISCA_FAILURE;

  return VISCA_SUCCESS;    
}


/****************************************************************************/
/*                           PUBLIC FUNCTIONS                               */
/****************************************************************************/


/***********************************/
/*       SYSTEM  FUNCTIONS         */
/***********************************/

VISCA_API uint32_t
VISCA_set_address(VISCAInterface_t *iface, int *camera_num)
{
  VISCAPacket_t packet;
  int backup;
  VISCACamera_t camera; /* dummy camera struct */

  camera.address=1;
  backup=iface->broadcast;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet,0x30);
  _VISCA_append_byte(&packet,0x01);

  iface->broadcast=1;
  if (_VISCA_send_packet(iface, &camera, &packet)!=VISCA_SUCCESS)
    {
      iface->broadcast=backup;
      return VISCA_FAILURE;
    }
  else
    iface->broadcast=backup;
  
  if (_VISCA_get_reply(iface, &camera)!=VISCA_SUCCESS)
    return VISCA_FAILURE;
  else
    {
      /* We parse the message from the camera here  */
      /* We expect to receive 4*camera_num bytes,
         every packet should be 88 30 0x FF, x being
         the camera id+1. The number of cams will thus be
         ibuf[bytes-2]-1  */
      if ((iface->bytes & 0x3)!=0) /* check multiple of 4 */
	return VISCA_FAILURE;
      else
	{
	  *camera_num=iface->ibuf[iface->bytes-2]-1;
	  if ((*camera_num==0)||(*camera_num>7))
	    return VISCA_FAILURE;
	  else
	    return VISCA_SUCCESS;
	}
    }
  
}


VISCA_API uint32_t
VISCA_clear(VISCAInterface_t *iface)
{
  VISCAPacket_t packet;

  int backup;
  VISCACamera_t camera; /* dummy camera struct */

  uint32_t sret;

  camera.address=0;
  backup=iface->broadcast;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet,0x01);
  _VISCA_append_byte(&packet,0x00);
  _VISCA_append_byte(&packet,0x01);

  iface->broadcast = 1;
  sret = _VISCA_send_packet(iface, &camera, &packet);
  iface->broadcast = backup;

  if (sret!=VISCA_SUCCESS)
	  return VISCA_FAILURE;
  else if (_VISCA_get_reply(iface, &camera)!=VISCA_SUCCESS)
      return VISCA_FAILURE;
  else
      return VISCA_SUCCESS;
}

VISCA_API uint32_t
VISCA_get_camera_info(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;
  packet.bytes[0]=0x80 | camera->address;
  packet.bytes[1]=0x09;
  packet.bytes[2]=0x00;
  packet.bytes[3]=0x02;
  packet.bytes[4]=VISCA_TERMINATOR;
  packet.length=5;

  if (_VISCA_write_packet_data(iface, camera, &packet)!=VISCA_SUCCESS)
    return VISCA_FAILURE;
  else
    if (_VISCA_get_reply(iface, camera)!=VISCA_SUCCESS)
      return VISCA_FAILURE;

  if (iface->bytes!= 10) /* we expect 10 bytes as answer */
    return VISCA_FAILURE;
  else
    {
      camera->vendor=(iface->ibuf[2]<<8) + iface->ibuf[3];
      camera->model=(iface->ibuf[4]<<8) + iface->ibuf[5];
      camera->rom_version=(iface->ibuf[6]<<8) + iface->ibuf[7];
      camera->socket_num=iface->ibuf[8];
      return VISCA_SUCCESS;
    }
}

/***********************************/
/*       COMMAND FUNCTIONS         */
/***********************************/

VISCA_API uint32_t
VISCA_set_power(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t power)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_POWER);
  _VISCA_append_byte(&packet, power);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_keylock(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t power)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_KEYLOCK);
  _VISCA_append_byte(&packet, power);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_camera_id(VISCAInterface_t *iface, VISCACamera_t *camera, uint16_t id)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_ID);
  _VISCA_append_byte(&packet, (id & 0xF000) >> 12);
  _VISCA_append_byte(&packet, (id & 0x0F00) >>  8);
  _VISCA_append_byte(&packet, (id & 0x00F0) >>  4);
  _VISCA_append_byte(&packet, (id & 0x000F));

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_zoom_tele(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_ZOOM);
  _VISCA_append_byte(&packet, VISCA_ZOOM_TELE);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_zoom_wide(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_ZOOM);
  _VISCA_append_byte(&packet, VISCA_ZOOM_WIDE);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_zoom_stop(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_ZOOM);
  _VISCA_append_byte(&packet, VISCA_ZOOM_STOP);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_zoom_tele_speed(VISCAInterface_t *iface, VISCACamera_t *camera, uint32_t speed)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_ZOOM);
  _VISCA_append_byte(&packet, VISCA_ZOOM_TELE_SPEED | (speed & 0x7));

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_zoom_wide_speed(VISCAInterface_t *iface, VISCACamera_t *camera, uint32_t speed)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_ZOOM);
  _VISCA_append_byte(&packet, VISCA_ZOOM_WIDE_SPEED | (speed & 0x7));

  return _VISCA_send_packet_with_reply(iface, camera, &packet);

}


VISCA_API uint32_t
VISCA_set_zoom_value(VISCAInterface_t *iface, VISCACamera_t *camera, uint32_t zoom)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_ZOOM_VALUE);
  _VISCA_append_byte(&packet, (zoom & 0xF000) >> 12);
  _VISCA_append_byte(&packet, (zoom & 0x0F00) >>  8);
  _VISCA_append_byte(&packet, (zoom & 0x00F0) >>  4);
  _VISCA_append_byte(&packet, (zoom & 0x000F));

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_zoom_and_focus_value(VISCAInterface_t *iface, VISCACamera_t *camera, uint32_t zoom, uint32_t focus)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_ZOOM_FOCUS_VALUE);
  _VISCA_append_byte(&packet, (zoom & 0xF000) >> 12);
  _VISCA_append_byte(&packet, (zoom & 0x0F00) >>  8);
  _VISCA_append_byte(&packet, (zoom & 0x00F0) >>  4);
  _VISCA_append_byte(&packet, (zoom & 0x000F));
  _VISCA_append_byte(&packet, (focus & 0xF000) >> 12);
  _VISCA_append_byte(&packet, (focus & 0x0F00) >>  8);
  _VISCA_append_byte(&packet, (focus & 0x00F0) >>  4);
  _VISCA_append_byte(&packet, (focus & 0x000F));
 
  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_dzoom(VISCAInterface_t *iface, VISCACamera_t *camera, uint32_t power)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_DZOOM);
  _VISCA_append_byte(&packet, power);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_dzoom_limit(VISCAInterface_t *iface, VISCACamera_t *camera, uint32_t limit)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_DZOOM_LIMIT);
  _VISCA_append_byte(&packet, limit);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_dzoom_mode(VISCAInterface_t *iface, VISCACamera_t *camera, uint32_t power)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_DZOOM_MODE);
  _VISCA_append_byte(&packet, power);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_focus_far(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_FOCUS);
  _VISCA_append_byte(&packet, VISCA_FOCUS_FAR);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_focus_near(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_FOCUS);
  _VISCA_append_byte(&packet, VISCA_FOCUS_NEAR);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_focus_stop(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_FOCUS);
  _VISCA_append_byte(&packet, VISCA_FOCUS_STOP);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_focus_far_speed(VISCAInterface_t *iface, VISCACamera_t *camera, uint32_t speed)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_FOCUS);
  _VISCA_append_byte(&packet, VISCA_FOCUS_FAR_SPEED | (speed & 0x7));

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_focus_near_speed(VISCAInterface_t *iface, VISCACamera_t *camera, uint32_t speed)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_FOCUS);
  _VISCA_append_byte(&packet, VISCA_FOCUS_NEAR_SPEED | (speed & 0x7));

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_focus_value(VISCAInterface_t *iface, VISCACamera_t *camera, uint32_t focus)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_FOCUS_VALUE);
  _VISCA_append_byte(&packet, (focus & 0xF000) >> 12);
  _VISCA_append_byte(&packet, (focus & 0x0F00) >>  8);
  _VISCA_append_byte(&packet, (focus & 0x00F0) >>  4);
  _VISCA_append_byte(&packet, (focus & 0x000F));

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_focus_auto(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t power)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_FOCUS_AUTO);
  _VISCA_append_byte(&packet, power);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_focus_one_push(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_FOCUS_ONE_PUSH);
  _VISCA_append_byte(&packet, VISCA_FOCUS_ONE_PUSH_TRIG);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_focus_infinity(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_FOCUS_ONE_PUSH);
  _VISCA_append_byte(&packet, VISCA_FOCUS_ONE_PUSH_INF);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_focus_autosense_high(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_FOCUS_AUTO_SENSE);
  _VISCA_append_byte(&packet, VISCA_FOCUS_AUTO_SENSE_HIGH);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_focus_autosense_low(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_FOCUS_AUTO_SENSE);
  _VISCA_append_byte(&packet, VISCA_FOCUS_AUTO_SENSE_LOW);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_focus_near_limit(VISCAInterface_t *iface, VISCACamera_t *camera, uint32_t limit)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_FOCUS_NEAR_LIMIT);
  _VISCA_append_byte(&packet, (limit & 0xF000) >> 12);
  _VISCA_append_byte(&packet, (limit & 0x0F00) >>  8);
  _VISCA_append_byte(&packet, (limit & 0x00F0) >>  4);
  _VISCA_append_byte(&packet, (limit & 0x000F));

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_whitebal_mode(VISCAInterface_t *iface, VISCACamera_t *camera, uint32_t mode)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_WB);
  _VISCA_append_byte(&packet, mode);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_whitebal_one_push(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_WB_TRIGGER);
  _VISCA_append_byte(&packet, VISCA_WB_ONE_PUSH_TRIG);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_rgain_up(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_RGAIN);
  _VISCA_append_byte(&packet, VISCA_UP);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_rgain_down(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_RGAIN);
  _VISCA_append_byte(&packet, VISCA_DOWN);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_rgain_reset(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_RGAIN);
  _VISCA_append_byte(&packet, VISCA_RESET);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);

}


VISCA_API uint32_t
VISCA_set_rgain_value(VISCAInterface_t *iface, VISCACamera_t *camera, uint32_t value)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_RGAIN_VALUE);
  _VISCA_append_byte(&packet, (value & 0xF000) >> 12);
  _VISCA_append_byte(&packet, (value & 0x0F00) >>  8);
  _VISCA_append_byte(&packet, (value & 0x00F0) >>  4);
  _VISCA_append_byte(&packet, (value & 0x000F));

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_bgain_up(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_BGAIN);
  _VISCA_append_byte(&packet, VISCA_UP);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_bgain_down(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_BGAIN);
  _VISCA_append_byte(&packet, VISCA_DOWN);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_bgain_reset(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_BGAIN);
  _VISCA_append_byte(&packet, VISCA_RESET);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_bgain_value(VISCAInterface_t *iface, VISCACamera_t *camera, uint32_t value)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_BGAIN_VALUE);
  _VISCA_append_byte(&packet, (value & 0xF000) >> 12);
  _VISCA_append_byte(&packet, (value & 0x0F00) >>  8);
  _VISCA_append_byte(&packet, (value & 0x00F0) >>  4);
 _VISCA_append_byte(&packet, (value & 0x000F));

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_shutter_up(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_SHUTTER);
  _VISCA_append_byte(&packet, VISCA_UP);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_shutter_down(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_SHUTTER);
  _VISCA_append_byte(&packet, VISCA_DOWN);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_shutter_reset(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_SHUTTER);
  _VISCA_append_byte(&packet, VISCA_RESET);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_shutter_value(VISCAInterface_t *iface, VISCACamera_t *camera, uint32_t value)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_SHUTTER_VALUE);
  _VISCA_append_byte(&packet, (value & 0xF000) >> 12);
  _VISCA_append_byte(&packet, (value & 0x0F00) >>  8);
  _VISCA_append_byte(&packet, (value & 0x00F0) >>  4);
 _VISCA_append_byte(&packet, (value & 0x000F));

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_iris_up(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_IRIS);
  _VISCA_append_byte(&packet, VISCA_UP);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_iris_down(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_IRIS);
  _VISCA_append_byte(&packet, VISCA_DOWN);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_iris_reset(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_IRIS);
  _VISCA_append_byte(&packet, VISCA_RESET);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_iris_value(VISCAInterface_t *iface, VISCACamera_t *camera, uint32_t value)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_IRIS_VALUE);
  _VISCA_append_byte(&packet, (value & 0xF000) >> 12);
  _VISCA_append_byte(&packet, (value & 0x0F00) >>  8);
  _VISCA_append_byte(&packet, (value & 0x00F0) >>  4);
 _VISCA_append_byte(&packet, (value & 0x000F));

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_gain_up(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_GAIN);
  _VISCA_append_byte(&packet, VISCA_UP);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_gain_down(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_GAIN);
  _VISCA_append_byte(&packet, VISCA_DOWN);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_gain_reset(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_GAIN);
  _VISCA_append_byte(&packet, VISCA_RESET);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_gain_value(VISCAInterface_t *iface, VISCACamera_t *camera, uint32_t value)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_GAIN_VALUE);
  _VISCA_append_byte(&packet, (value & 0xF000) >> 12);
  _VISCA_append_byte(&packet, (value & 0x0F00) >>  8);
  _VISCA_append_byte(&packet, (value & 0x00F0) >>  4);
  _VISCA_append_byte(&packet, (value & 0x000F));

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_bright_up(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_BRIGHT);
  _VISCA_append_byte(&packet, VISCA_UP);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_bright_down(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_BRIGHT);
  _VISCA_append_byte(&packet, VISCA_DOWN);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_bright_reset(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_BRIGHT);
  _VISCA_append_byte(&packet, VISCA_RESET);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_bright_value(VISCAInterface_t *iface, VISCACamera_t *camera, uint32_t value)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_BRIGHT_VALUE);
  _VISCA_append_byte(&packet, (value & 0xF000) >> 12);
  _VISCA_append_byte(&packet, (value & 0x0F00) >>  8);
  _VISCA_append_byte(&packet, (value & 0x00F0) >>  4);
  _VISCA_append_byte(&packet, (value & 0x000F));

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_aperture_up(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_APERTURE);
  _VISCA_append_byte(&packet, VISCA_UP);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_aperture_down(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_APERTURE);
  _VISCA_append_byte(&packet, VISCA_DOWN);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_aperture_reset(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_APERTURE);
  _VISCA_append_byte(&packet, VISCA_RESET);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_aperture_value(VISCAInterface_t *iface, VISCACamera_t *camera, uint32_t value)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_APERTURE_VALUE);
  _VISCA_append_byte(&packet, (value & 0xF000) >> 12);
  _VISCA_append_byte(&packet, (value & 0x0F00) >>  8);
  _VISCA_append_byte(&packet, (value & 0x00F0) >>  4);
  _VISCA_append_byte(&packet, (value & 0x000F));

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_exp_comp_up(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_EXP_COMP);
  _VISCA_append_byte(&packet, VISCA_UP);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_exp_comp_down(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_EXP_COMP);
  _VISCA_append_byte(&packet, VISCA_DOWN);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_exp_comp_reset(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_EXP_COMP);
  _VISCA_append_byte(&packet, VISCA_RESET);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);

  return VISCA_SUCCESS;
}


VISCA_API uint32_t
VISCA_set_exp_comp_value(VISCAInterface_t *iface, VISCACamera_t *camera, uint32_t value)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_EXP_COMP_VALUE);
  _VISCA_append_byte(&packet, (value & 0xF000) >> 12);
  _VISCA_append_byte(&packet, (value & 0x0F00) >>  8);
  _VISCA_append_byte(&packet, (value & 0x00F0) >>  4);
  _VISCA_append_byte(&packet, (value & 0x000F));

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_exp_comp_power(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t power)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_EXP_COMP_POWER);
  _VISCA_append_byte(&packet, power);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_auto_exp_mode(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t mode)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_AUTO_EXP);
  _VISCA_append_byte(&packet, mode);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_slow_shutter_auto(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t power)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_SLOW_SHUTTER);
  _VISCA_append_byte(&packet, power);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_backlight_comp(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t power)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_BACKLIGHT_COMP);
  _VISCA_append_byte(&packet, power);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_zero_lux_shot(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t power)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_ZERO_LUX);
  _VISCA_append_byte(&packet, power);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_ir_led(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t power)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_IR_LED);
  _VISCA_append_byte(&packet, power);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_wide_mode(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t mode)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_WIDE_MODE);
  _VISCA_append_byte(&packet, mode);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_mirror(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t power)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_MIRROR);
  _VISCA_append_byte(&packet, power);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_freeze(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t power)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_FREEZE);
  _VISCA_append_byte(&packet, power);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_picture_effect(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t mode)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_PICTURE_EFFECT);
  _VISCA_append_byte(&packet, mode);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_digital_effect(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t mode)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_DIGITAL_EFFECT);
  _VISCA_append_byte(&packet, mode);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_digital_effect_level(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t level)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_DIGITAL_EFFECT_LEVEL);
  _VISCA_append_byte(&packet, level);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_cam_stabilizer(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t power)
{
  VISCAPacket_t packet;
  
  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_CAM_STABILIZER);
  _VISCA_append_byte(&packet, power);
  
  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_memory_set(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t channel)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_MEMORY);
  _VISCA_append_byte(&packet, VISCA_MEMORY_SET);
  _VISCA_append_byte(&packet, channel);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_memory_recall(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t channel)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_MEMORY);
  _VISCA_append_byte(&packet, VISCA_MEMORY_RECALL);
  _VISCA_append_byte(&packet, channel);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_memory_reset(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t channel)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_MEMORY);
  _VISCA_append_byte(&packet, VISCA_MEMORY_RESET);
  _VISCA_append_byte(&packet, channel);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_display(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t power)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_DISPLAY);
  _VISCA_append_byte(&packet, power);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_date_time(VISCAInterface_t *iface, VISCACamera_t *camera, uint32_t year, uint32_t month, uint32_t day, uint32_t hour, uint32_t minute)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_DATE_TIME_SET);
  _VISCA_append_byte(&packet, year/10);
  _VISCA_append_byte(&packet, year-10*(year/10));
  _VISCA_append_byte(&packet, month/10);
  _VISCA_append_byte(&packet, month-10*(month/10));
  _VISCA_append_byte(&packet, day/10);
  _VISCA_append_byte(&packet, day-10*(day/10));
  _VISCA_append_byte(&packet, hour/10);
  _VISCA_append_byte(&packet, hour-10*(hour/10));
  _VISCA_append_byte(&packet, minute/10);
  _VISCA_append_byte(&packet, minute-10*(minute/10));

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_date_display(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t power)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_DATE_DISPLAY);
  _VISCA_append_byte(&packet, power);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_time_display(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t power)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_TIME_DISPLAY);
  _VISCA_append_byte(&packet, power);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_title_display(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t power)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_TITLE_DISPLAY);
  _VISCA_append_byte(&packet, power);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_title_clear(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_TITLE_DISPLAY);
  _VISCA_append_byte(&packet, VISCA_TITLE_DISPLAY_CLEAR);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_title_params(VISCAInterface_t *iface, VISCACamera_t *camera, VISCATitleData_t *title)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_TITLE_SET);
  _VISCA_append_byte(&packet, VISCA_TITLE_SET_PARAMS);
  _VISCA_append_byte(&packet, title->vposition);
  _VISCA_append_byte(&packet, title->hposition);
  _VISCA_append_byte(&packet, title->color);
  _VISCA_append_byte(&packet, title->blink);
  _VISCA_append_byte(&packet, 0);
  _VISCA_append_byte(&packet, 0);
  _VISCA_append_byte(&packet, 0);
  _VISCA_append_byte(&packet, 0);
  _VISCA_append_byte(&packet, 0);
  _VISCA_append_byte(&packet, 0);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_title(VISCAInterface_t *iface, VISCACamera_t *camera, VISCATitleData_t *title)
{
  VISCAPacket_t packet;
  int i, err=0;
  
  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_TITLE_SET);
  _VISCA_append_byte(&packet, VISCA_TITLE_SET_PART1);

  for (i=0;i<10;i++)
    _VISCA_append_byte(&packet, title->title[i]);

  err+=_VISCA_send_packet_with_reply(iface, camera, &packet);

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_TITLE_SET);
  _VISCA_append_byte(&packet, VISCA_TITLE_SET_PART2);

  for (i=0;i<10;i++)
    _VISCA_append_byte(&packet, title->title[i+10]);

  err+=_VISCA_send_packet_with_reply(iface, camera, &packet);

  return err;
}


VISCA_API uint32_t
VISCA_set_spot_ae_on(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_SPOT_AE);
  _VISCA_append_byte(&packet, VISCA_SPOT_AE_ON);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_spot_ae_off(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_SPOT_AE);
  _VISCA_append_byte(&packet, VISCA_SPOT_AE_OFF);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_spot_ae_position(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t x_position, uint8_t y_position)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_SPOT_AE_POSITION);
  _VISCA_append_byte(&packet, (x_position & 0xF0) >>  4);
  _VISCA_append_byte(&packet, (x_position & 0x0F));
  _VISCA_append_byte(&packet, (y_position & 0xF0) >>  4);
  _VISCA_append_byte(&packet, (y_position & 0x0F));

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


/***********************************/
/*       INQUIRY FUNCTIONS         */
/***********************************/

VISCA_API uint32_t
VISCA_get_power(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t *power)
{
  VISCAPacket_t packet;
  uint32_t err;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_INQUIRY);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_POWER);
  err=_VISCA_send_packet_with_reply(iface, camera, &packet);
  if (err!=VISCA_SUCCESS)
    return err;
  else
    {
      *power=iface->ibuf[2];
      return VISCA_SUCCESS;
    }
}


VISCA_API uint32_t
VISCA_get_dzoom(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t *power)
{
  VISCAPacket_t packet;
  uint32_t err;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_INQUIRY);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_DZOOM);
  err=_VISCA_send_packet_with_reply(iface, camera, &packet);
  if (err!=VISCA_SUCCESS)
    return err;
  else {
    *power=iface->ibuf[2];
    return VISCA_SUCCESS;
  }
}


VISCA_API uint32_t
VISCA_get_dzoom_limit(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t *value)
{
  VISCAPacket_t packet;
  uint32_t err;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_INQUIRY);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_DZOOM_LIMIT);
  err=_VISCA_send_packet_with_reply(iface, camera, &packet);
  if (err!=VISCA_SUCCESS)
    return err;
  else {
    *value=iface->ibuf[2];
    return VISCA_SUCCESS;
  }
}



VISCA_API uint32_t
VISCA_get_zoom_value(VISCAInterface_t *iface, VISCACamera_t *camera, uint16_t *value)
{
  VISCAPacket_t packet;
  uint32_t err;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_INQUIRY);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_ZOOM_VALUE);
  err=_VISCA_send_packet_with_reply(iface, camera, &packet);
  if (err!=VISCA_SUCCESS)
    return err;
  else {
    *value=(iface->ibuf[2]<<12)+(iface->ibuf[3]<<8)+(iface->ibuf[4]<<4)+iface->ibuf[5];
    return VISCA_SUCCESS;
  }

}


VISCA_API uint32_t
VISCA_get_focus_auto(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t *power)
{
  VISCAPacket_t packet;
  uint32_t err;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_INQUIRY);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_FOCUS_AUTO);
  err=_VISCA_send_packet_with_reply(iface, camera, &packet);
  if (err!=VISCA_SUCCESS)
    return err;
  else
    {
      *power=iface->ibuf[2];
      return VISCA_SUCCESS;
    }
}


VISCA_API uint32_t
VISCA_get_focus_value(VISCAInterface_t *iface, VISCACamera_t *camera, uint16_t *value)
{
  VISCAPacket_t packet;
  uint32_t err;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_INQUIRY);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_FOCUS_VALUE);
  err=_VISCA_send_packet_with_reply(iface, camera, &packet);
  if (err!=VISCA_SUCCESS)
    return err;
  else
    {
      *value=(iface->ibuf[2]<<12)+(iface->ibuf[3]<<8)+(iface->ibuf[4]<<4)+iface->ibuf[5];
      return VISCA_SUCCESS;
    }
}


VISCA_API uint32_t
VISCA_get_focus_auto_sense(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t *mode)
{
  VISCAPacket_t packet;
  uint32_t err;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_INQUIRY);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_FOCUS_AUTO_SENSE );
  err=_VISCA_send_packet_with_reply(iface, camera, &packet);
  if (err!=VISCA_SUCCESS)
    return err;
  else
    {
      *mode=iface->ibuf[2];
      return VISCA_SUCCESS;
    }
}


VISCA_API uint32_t
VISCA_get_focus_near_limit(VISCAInterface_t *iface, VISCACamera_t *camera, uint16_t *value)
{
  VISCAPacket_t packet;
  uint32_t err;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_INQUIRY);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_FOCUS_NEAR_LIMIT);
  err=_VISCA_send_packet_with_reply(iface, camera, &packet);
  if (err!=VISCA_SUCCESS)
    return err;
  else
    {
      *value=(iface->ibuf[2]<<12)+(iface->ibuf[3]<<8)+(iface->ibuf[4]<<4)+iface->ibuf[5];
      return VISCA_SUCCESS;
    }
}


VISCA_API uint32_t
VISCA_get_whitebal_mode(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t *mode)
{
  VISCAPacket_t packet;
  uint32_t err;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_INQUIRY);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_WB);
  err=_VISCA_send_packet_with_reply(iface, camera, &packet);
  if (err!=VISCA_SUCCESS)
    return err;
  else
    {
      *mode=iface->ibuf[2];
      return VISCA_SUCCESS;
    }
}


VISCA_API uint32_t
VISCA_get_rgain_value(VISCAInterface_t *iface, VISCACamera_t *camera, uint16_t *value)
{
  VISCAPacket_t packet;
  uint32_t err;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_INQUIRY);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_RGAIN_VALUE);
  err=_VISCA_send_packet_with_reply(iface, camera, &packet);
  if (err!=VISCA_SUCCESS)
    return err;
  else
    {
      *value=(iface->ibuf[2]<<12)+(iface->ibuf[3]<<8)+(iface->ibuf[4]<<4)+iface->ibuf[5];
      return VISCA_SUCCESS;
    }
}


VISCA_API uint32_t
VISCA_get_bgain_value(VISCAInterface_t *iface, VISCACamera_t *camera, uint16_t *value)
{
  VISCAPacket_t packet;
  uint32_t err;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_INQUIRY);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_BGAIN_VALUE);
  err=_VISCA_send_packet_with_reply(iface, camera, &packet);
  if (err!=VISCA_SUCCESS)
    return err;
  else
    {
      *value=(iface->ibuf[2]<<12)+(iface->ibuf[3]<<8)+(iface->ibuf[4]<<4)+iface->ibuf[5];
      return VISCA_SUCCESS;
    }
}


VISCA_API uint32_t
VISCA_get_auto_exp_mode(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t *mode)
{
  VISCAPacket_t packet;
  uint32_t err;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_INQUIRY);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_AUTO_EXP);
  err=_VISCA_send_packet_with_reply(iface, camera, &packet);
  if (err!=VISCA_SUCCESS)
    return err;
  else
    {
      *mode=iface->ibuf[2];
      return VISCA_SUCCESS;
    }
}


VISCA_API uint32_t
VISCA_get_slow_shutter_auto(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t *mode)
{
  VISCAPacket_t packet;
  uint32_t err;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_INQUIRY);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_SLOW_SHUTTER);
  err=_VISCA_send_packet_with_reply(iface, camera, &packet);
  if (err!=VISCA_SUCCESS)
    return err;
  else
    {
      *mode=iface->ibuf[2];
      return VISCA_SUCCESS;
    }
}


VISCA_API uint32_t
VISCA_get_shutter_value(VISCAInterface_t *iface, VISCACamera_t *camera, uint16_t *value)
{
  VISCAPacket_t packet;
  uint32_t err;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_INQUIRY);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_SHUTTER_VALUE);
  err=_VISCA_send_packet_with_reply(iface, camera, &packet);
  if (err!=VISCA_SUCCESS)
    return err;
  else
    {
      *value=(iface->ibuf[2]<<12)+(iface->ibuf[3]<<8)+(iface->ibuf[4]<<4)+iface->ibuf[5];
      return VISCA_SUCCESS;
    }
}


VISCA_API uint32_t
VISCA_get_iris_value(VISCAInterface_t *iface, VISCACamera_t *camera, uint16_t *value)
{
  VISCAPacket_t packet;
  uint32_t err;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_INQUIRY);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_IRIS_VALUE);
  err=_VISCA_send_packet_with_reply(iface, camera, &packet);
  if (err!=VISCA_SUCCESS)
    return err;
  else
    {
      *value=(iface->ibuf[2]<<12)+(iface->ibuf[3]<<8)+(iface->ibuf[4]<<4)+iface->ibuf[5];
      return VISCA_SUCCESS;
    }
}


VISCA_API uint32_t
VISCA_get_gain_value(VISCAInterface_t *iface, VISCACamera_t *camera, uint16_t *value)
{
  VISCAPacket_t packet;
  uint32_t err;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_INQUIRY);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_GAIN_VALUE);
  err=_VISCA_send_packet_with_reply(iface, camera, &packet);
  if (err!=VISCA_SUCCESS)
    return err;
  else
    {
      *value=(iface->ibuf[2]<<12)+(iface->ibuf[3]<<8)+(iface->ibuf[4]<<4)+iface->ibuf[5];
      return VISCA_SUCCESS;
    }
}


VISCA_API uint32_t
VISCA_get_bright_value(VISCAInterface_t *iface, VISCACamera_t *camera, uint16_t *value)
{
  VISCAPacket_t packet;
  uint32_t err;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_INQUIRY);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_BRIGHT_VALUE);
  err=_VISCA_send_packet_with_reply(iface, camera, &packet);
  if (err!=VISCA_SUCCESS)
    return err;
  else
    {
      *value=(iface->ibuf[2]<<12)+(iface->ibuf[3]<<8)+(iface->ibuf[4]<<4)+iface->ibuf[5];
      return VISCA_SUCCESS;
    }
}


VISCA_API uint32_t
VISCA_get_exp_comp_power(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t *power)
{
  VISCAPacket_t packet;
  uint32_t err;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_INQUIRY);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_EXP_COMP_POWER);
  err=_VISCA_send_packet_with_reply(iface, camera, &packet);
  if (err!=VISCA_SUCCESS)
    return err;
  else
    {
      *power=iface->ibuf[2];
      return VISCA_SUCCESS;
    }
}


VISCA_API uint32_t
VISCA_get_exp_comp_value(VISCAInterface_t *iface, VISCACamera_t *camera, uint16_t *value)
{
  VISCAPacket_t packet;
  uint32_t err;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_INQUIRY);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_EXP_COMP_VALUE);
  err=_VISCA_send_packet_with_reply(iface, camera, &packet);
  if (err!=VISCA_SUCCESS)
    return err;
  else
    {
      *value=(iface->ibuf[2]<<12)+(iface->ibuf[3]<<8)+(iface->ibuf[4]<<4)+iface->ibuf[5];
      return VISCA_SUCCESS;
    }
}


VISCA_API uint32_t
VISCA_get_backlight_comp(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t *power)
{
  VISCAPacket_t packet;
  uint32_t err;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_INQUIRY);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_BACKLIGHT_COMP);
  err=_VISCA_send_packet_with_reply(iface, camera, &packet);
  if (err!=VISCA_SUCCESS)
    return err;
  else
    {
      *power=iface->ibuf[2];
      return VISCA_SUCCESS;
    }
}


VISCA_API uint32_t
VISCA_get_aperture_value(VISCAInterface_t *iface, VISCACamera_t *camera, uint16_t *value)
{
  VISCAPacket_t packet;
  uint32_t err;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_INQUIRY);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_APERTURE_VALUE);
  err=_VISCA_send_packet_with_reply(iface, camera, &packet);
  if (err!=VISCA_SUCCESS)
    return err;
  else
    {
      *value=(iface->ibuf[2]<<12)+(iface->ibuf[3]<<8)+(iface->ibuf[4]<<4)+iface->ibuf[5];
      return VISCA_SUCCESS;
    }
}


VISCA_API uint32_t
VISCA_get_zero_lux_shot(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t *power)
{
  VISCAPacket_t packet;
  uint32_t err;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_INQUIRY);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_ZERO_LUX);
  err=_VISCA_send_packet_with_reply(iface, camera, &packet);
  if (err!=VISCA_SUCCESS)
    return err;
  else
    {
      *power=iface->ibuf[2];
      return VISCA_SUCCESS;
    }
}


VISCA_API uint32_t
VISCA_get_ir_led(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t *power)
{
  VISCAPacket_t packet;
  uint32_t err;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_INQUIRY);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_IR_LED);
  err=_VISCA_send_packet_with_reply(iface, camera, &packet);
  if (err!=VISCA_SUCCESS)
    return err;
  else
    {
      *power=iface->ibuf[2];
      return VISCA_SUCCESS;
    }
}


VISCA_API uint32_t
VISCA_get_wide_mode(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t *mode)
{
  VISCAPacket_t packet;
  uint32_t err;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_INQUIRY);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_WIDE_MODE);
  err=_VISCA_send_packet_with_reply(iface, camera, &packet);
  if (err!=VISCA_SUCCESS)
    return err;
  else
    {
      *mode=iface->ibuf[2];
      return VISCA_SUCCESS;
    }
}


VISCA_API uint32_t
VISCA_get_mirror(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t *power)
{
  VISCAPacket_t packet;
  uint32_t err;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_INQUIRY);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_MIRROR);
  err=_VISCA_send_packet_with_reply(iface, camera, &packet);
  if (err!=VISCA_SUCCESS)
    return err;
  else
    {
      *power=iface->ibuf[2];
      return VISCA_SUCCESS;
    }
}


VISCA_API uint32_t
VISCA_get_freeze(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t *power)
{
  VISCAPacket_t packet;
  uint32_t err;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_INQUIRY);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_FREEZE);
  err=_VISCA_send_packet_with_reply(iface, camera, &packet);
  if (err!=VISCA_SUCCESS)
    return err;
  else
    {
      *power=iface->ibuf[2];
      return VISCA_SUCCESS;
    }
}


VISCA_API uint32_t
VISCA_get_picture_effect(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t *mode)
{
  VISCAPacket_t packet;
  uint32_t err;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_INQUIRY);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_PICTURE_EFFECT);
  err=_VISCA_send_packet_with_reply(iface, camera, &packet);
  if (err!=VISCA_SUCCESS)
    return err;
  else
    {
      *mode=iface->ibuf[2];
      return VISCA_SUCCESS;
    }
}


VISCA_API uint32_t
VISCA_get_digital_effect(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t *mode)
{
  VISCAPacket_t packet;
  uint32_t err;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_INQUIRY);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_DIGITAL_EFFECT);
  err=_VISCA_send_packet_with_reply(iface, camera, &packet);
  if (err!=VISCA_SUCCESS)
    return err;
  else
    {
      *mode=iface->ibuf[2];
      return VISCA_SUCCESS;
    }
}


VISCA_API uint32_t
VISCA_get_digital_effect_level(VISCAInterface_t *iface, VISCACamera_t *camera, uint16_t *value)
{
  VISCAPacket_t packet;
  uint32_t err;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_INQUIRY);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_DIGITAL_EFFECT_LEVEL);
  err=_VISCA_send_packet_with_reply(iface, camera, &packet);
  if (err!=VISCA_SUCCESS)
    return err;
  else
    {
      *value=(iface->ibuf[2]<<12)+(iface->ibuf[3]<<8)+(iface->ibuf[4]<<4)+iface->ibuf[5];
      return VISCA_SUCCESS;
    }
}


VISCA_API uint32_t
VISCA_get_memory(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t *channel)
{
  VISCAPacket_t packet;
  uint32_t err;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_INQUIRY);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_MEMORY);
  err=_VISCA_send_packet_with_reply(iface, camera, &packet);
  if (err!=VISCA_SUCCESS)
    return err;
  else
    {
      *channel=iface->ibuf[2];
      return VISCA_SUCCESS;
    }
}


VISCA_API uint32_t
VISCA_get_display(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t *power)
{
  VISCAPacket_t packet;
  uint32_t err;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_INQUIRY);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_DISPLAY);
  err=_VISCA_send_packet_with_reply(iface, camera, &packet);
  if (err!=VISCA_SUCCESS)
    return err;
  else
    {
      *power=iface->ibuf[2];
      return VISCA_SUCCESS;
    }
}


VISCA_API uint32_t
VISCA_get_id(VISCAInterface_t *iface, VISCACamera_t *camera, uint16_t *id)
{
  VISCAPacket_t packet;
  uint32_t err;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_INQUIRY);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_ID);
  err=_VISCA_send_packet_with_reply(iface, camera, &packet);
  if (err!=VISCA_SUCCESS)
    return err;
  else
    {
      *id=(iface->ibuf[2]<<12)+(iface->ibuf[3]<<8)+(iface->ibuf[4]<<4)+iface->ibuf[5];
      return VISCA_SUCCESS;
    }
}

VISCA_API uint32_t
VISCA_set_irreceive_on(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_PAN_TILTER);
  _VISCA_append_byte(&packet, VISCA_IRRECEIVE);
  _VISCA_append_byte(&packet, VISCA_IRRECEIVE_ON);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}

VISCA_API uint32_t
VISCA_set_irreceive_off(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_PAN_TILTER);
  _VISCA_append_byte(&packet, VISCA_IRRECEIVE);
  _VISCA_append_byte(&packet, VISCA_IRRECEIVE_OFF);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}

VISCA_API uint32_t
VISCA_set_irreceive_onoff(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_PAN_TILTER);
  _VISCA_append_byte(&packet, VISCA_IRRECEIVE);
  _VISCA_append_byte(&packet, VISCA_IRRECEIVE_ONOFF);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_pantilt_up(VISCAInterface_t *iface, VISCACamera_t *camera, uint32_t pan_speed, uint32_t tilt_speed)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_PAN_TILTER);
  _VISCA_append_byte(&packet, VISCA_PT_DRIVE);
  _VISCA_append_byte(&packet, pan_speed);
  _VISCA_append_byte(&packet, tilt_speed);
  _VISCA_append_byte(&packet, VISCA_PT_DRIVE_HORIZ_STOP);
  _VISCA_append_byte(&packet, VISCA_PT_DRIVE_VERT_UP);
  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}

VISCA_API uint32_t
VISCA_set_pantilt_down(VISCAInterface_t *iface, VISCACamera_t *camera, uint32_t pan_speed, uint32_t tilt_speed)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_PAN_TILTER);
  _VISCA_append_byte(&packet, VISCA_PT_DRIVE);
  _VISCA_append_byte(&packet, pan_speed);
  _VISCA_append_byte(&packet, tilt_speed);
  _VISCA_append_byte(&packet, VISCA_PT_DRIVE_HORIZ_STOP);
  _VISCA_append_byte(&packet, VISCA_PT_DRIVE_VERT_DOWN);
  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}

VISCA_API uint32_t
VISCA_set_pantilt_left(VISCAInterface_t *iface, VISCACamera_t *camera, uint32_t pan_speed, uint32_t tilt_speed)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_PAN_TILTER);
  _VISCA_append_byte(&packet, VISCA_PT_DRIVE);
  _VISCA_append_byte(&packet, pan_speed);
  _VISCA_append_byte(&packet, tilt_speed);
  _VISCA_append_byte(&packet, VISCA_PT_DRIVE_HORIZ_LEFT);
  _VISCA_append_byte(&packet, VISCA_PT_DRIVE_VERT_STOP);
  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}

VISCA_API uint32_t
VISCA_set_pantilt_right(VISCAInterface_t *iface, VISCACamera_t *camera, uint32_t pan_speed, uint32_t tilt_speed)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_PAN_TILTER);
  _VISCA_append_byte(&packet, VISCA_PT_DRIVE);
  _VISCA_append_byte(&packet, pan_speed);
  _VISCA_append_byte(&packet, tilt_speed);
  _VISCA_append_byte(&packet, VISCA_PT_DRIVE_HORIZ_RIGHT);
  _VISCA_append_byte(&packet, VISCA_PT_DRIVE_VERT_STOP);
  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}

VISCA_API uint32_t
VISCA_set_pantilt_upleft(VISCAInterface_t *iface, VISCACamera_t *camera, uint32_t pan_speed, uint32_t tilt_speed)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_PAN_TILTER);
  _VISCA_append_byte(&packet, VISCA_PT_DRIVE);
  _VISCA_append_byte(&packet, pan_speed);
  _VISCA_append_byte(&packet, tilt_speed);
  _VISCA_append_byte(&packet, VISCA_PT_DRIVE_HORIZ_LEFT);
  _VISCA_append_byte(&packet, VISCA_PT_DRIVE_VERT_UP);
  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}

VISCA_API uint32_t
VISCA_set_pantilt_upright(VISCAInterface_t *iface, VISCACamera_t *camera, uint32_t pan_speed, uint32_t tilt_speed)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_PAN_TILTER);
  _VISCA_append_byte(&packet, VISCA_PT_DRIVE);
  _VISCA_append_byte(&packet, pan_speed);
  _VISCA_append_byte(&packet, tilt_speed);
  _VISCA_append_byte(&packet, VISCA_PT_DRIVE_HORIZ_RIGHT);
  _VISCA_append_byte(&packet, VISCA_PT_DRIVE_VERT_UP);
  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}

VISCA_API uint32_t
VISCA_set_pantilt_downleft(VISCAInterface_t *iface, VISCACamera_t *camera, uint32_t pan_speed, uint32_t tilt_speed)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_PAN_TILTER);
  _VISCA_append_byte(&packet, VISCA_PT_DRIVE);
  _VISCA_append_byte(&packet, pan_speed);
  _VISCA_append_byte(&packet, tilt_speed);
  _VISCA_append_byte(&packet, VISCA_PT_DRIVE_HORIZ_LEFT);
  _VISCA_append_byte(&packet, VISCA_PT_DRIVE_VERT_DOWN);
  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}

VISCA_API uint32_t
VISCA_set_pantilt_downright(VISCAInterface_t *iface, VISCACamera_t *camera, uint32_t pan_speed, uint32_t tilt_speed)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_PAN_TILTER);
  _VISCA_append_byte(&packet, VISCA_PT_DRIVE);
  _VISCA_append_byte(&packet, pan_speed);
  _VISCA_append_byte(&packet, tilt_speed);
  _VISCA_append_byte(&packet, VISCA_PT_DRIVE_HORIZ_RIGHT);
  _VISCA_append_byte(&packet, VISCA_PT_DRIVE_VERT_DOWN);
  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}

VISCA_API uint32_t
VISCA_set_pantilt_stop(VISCAInterface_t *iface, VISCACamera_t *camera, uint32_t pan_speed, uint32_t tilt_speed)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_PAN_TILTER);
  _VISCA_append_byte(&packet, VISCA_PT_DRIVE);
  _VISCA_append_byte(&packet, pan_speed);
  _VISCA_append_byte(&packet, tilt_speed);
  _VISCA_append_byte(&packet, VISCA_PT_DRIVE_HORIZ_STOP);
  _VISCA_append_byte(&packet, VISCA_PT_DRIVE_VERT_STOP);
  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}

VISCA_API uint32_t
VISCA_set_pantilt_absolute_position(VISCAInterface_t *iface, VISCACamera_t *camera, uint32_t pan_speed, uint32_t tilt_speed, int pan_position, int tilt_position)
{
  VISCAPacket_t packet;

  uint32_t pan_pos=(uint32_t) pan_position;
  uint32_t tilt_pos=(uint32_t) tilt_position;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_PAN_TILTER);
  _VISCA_append_byte(&packet, VISCA_PT_ABSOLUTE_POSITION);
  _VISCA_append_byte(&packet, pan_speed);
  _VISCA_append_byte(&packet, tilt_speed);

  _VISCA_append_byte(&packet, (pan_pos & 0x0f000) >> 12);
  _VISCA_append_byte(&packet, (pan_pos & 0x00f00) >>  8);
  _VISCA_append_byte(&packet, (pan_pos & 0x000f0) >>  4);
  _VISCA_append_byte(&packet,  pan_pos & 0x0000f       );

  _VISCA_append_byte(&packet, (tilt_pos & 0xf000) >> 12);
  _VISCA_append_byte(&packet, (tilt_pos & 0x0f00) >> 8);
  _VISCA_append_byte(&packet, (tilt_pos & 0x00f0) >> 4);
  _VISCA_append_byte(&packet, tilt_pos & 0x000f);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_pantilt_relative_position(VISCAInterface_t *iface, VISCACamera_t *camera, uint32_t pan_speed, uint32_t tilt_speed, int pan_position, int tilt_position)
{
  VISCAPacket_t packet;

  uint32_t pan_pos=(uint32_t) pan_position;
  uint32_t tilt_pos=(uint32_t) tilt_position;
  

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_PAN_TILTER);
  _VISCA_append_byte(&packet, VISCA_PT_RELATIVE_POSITION);
  _VISCA_append_byte(&packet, pan_speed);
  _VISCA_append_byte(&packet, tilt_speed);

  _VISCA_append_byte(&packet, (pan_pos & 0x0f000) >> 12);
  _VISCA_append_byte(&packet, (pan_pos & 0x00f00) >>  8);
  _VISCA_append_byte(&packet, (pan_pos & 0x000f0) >>  4);
  _VISCA_append_byte(&packet,  pan_pos & 0x0000f       );

  _VISCA_append_byte(&packet, (tilt_pos & 0xf000) >> 12);
  _VISCA_append_byte(&packet, (tilt_pos & 0x0f00) >> 8);
  _VISCA_append_byte(&packet, (tilt_pos & 0x00f0) >> 4);
  _VISCA_append_byte(&packet, tilt_pos & 0x000f);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}

VISCA_API uint32_t
VISCA_set_pantilt_home(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_PAN_TILTER);
  _VISCA_append_byte(&packet, VISCA_PT_HOME);
  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}

VISCA_API uint32_t
VISCA_set_pantilt_reset(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_PAN_TILTER);
  _VISCA_append_byte(&packet, VISCA_PT_RESET);
  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}

VISCA_API uint32_t
VISCA_set_pantilt_limit_upright(VISCAInterface_t *iface, VISCACamera_t *camera, int pan_position, int tilt_position)
{
  VISCAPacket_t packet;

  uint32_t pan_pos=(uint32_t) pan_position;
  uint32_t tilt_pos=(uint32_t) tilt_position;
  

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_PAN_TILTER);
  _VISCA_append_byte(&packet, VISCA_PT_LIMITSET);
  _VISCA_append_byte(&packet, VISCA_PT_LIMITSET_SET);
  _VISCA_append_byte(&packet, VISCA_PT_LIMITSET_SET_UR);
  _VISCA_append_byte(&packet, (pan_pos & 0xf000) >> 12);
  _VISCA_append_byte(&packet, (pan_pos & 0x0f00) >> 8);
  _VISCA_append_byte(&packet, (pan_pos & 0x00f0) >> 4);
  _VISCA_append_byte(&packet, pan_pos & 0x000f);

  _VISCA_append_byte(&packet, (tilt_pos & 0xf000) >> 12);
  _VISCA_append_byte(&packet, (tilt_pos & 0x0f00) >> 8);
  _VISCA_append_byte(&packet, (tilt_pos & 0x00f0) >> 4);
  _VISCA_append_byte(&packet, tilt_pos & 0x000f);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_pantilt_limit_downleft(VISCAInterface_t *iface, VISCACamera_t *camera, int pan_position, int tilt_position)
{
  VISCAPacket_t packet;

  uint32_t pan_pos=(uint32_t) pan_position;
  uint32_t tilt_pos=(uint32_t) tilt_position;
  

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_PAN_TILTER);
  _VISCA_append_byte(&packet, VISCA_PT_LIMITSET);
  _VISCA_append_byte(&packet, VISCA_PT_LIMITSET_SET);
  _VISCA_append_byte(&packet, VISCA_PT_LIMITSET_SET_DL);
  _VISCA_append_byte(&packet, (pan_pos & 0xf000) >> 12);
  _VISCA_append_byte(&packet, (pan_pos & 0x0f00) >> 8);
  _VISCA_append_byte(&packet, (pan_pos & 0x00f0) >> 4);
  _VISCA_append_byte(&packet, pan_pos & 0x000f);

  _VISCA_append_byte(&packet, (tilt_pos & 0xf000) >> 12);
  _VISCA_append_byte(&packet, (tilt_pos & 0x0f00) >> 8);
  _VISCA_append_byte(&packet, (tilt_pos & 0x00f0) >> 4);
  _VISCA_append_byte(&packet, tilt_pos & 0x000f);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_pantilt_limit_downleft_clear(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  uint32_t pan_pos=0x7fff;
  uint32_t tilt_pos=0x7fff;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_PAN_TILTER);
  _VISCA_append_byte(&packet, VISCA_PT_LIMITSET);
  _VISCA_append_byte(&packet, VISCA_PT_LIMITSET_CLEAR);
  _VISCA_append_byte(&packet, VISCA_PT_LIMITSET_SET_DL);
  _VISCA_append_byte(&packet, (pan_pos & 0xf000) >> 12);
  _VISCA_append_byte(&packet, (pan_pos & 0x0f00) >> 8);
  _VISCA_append_byte(&packet, (pan_pos & 0x00f0) >> 4);
  _VISCA_append_byte(&packet, pan_pos & 0x000f);

  _VISCA_append_byte(&packet, (tilt_pos & 0xf000) >> 12);
  _VISCA_append_byte(&packet, (tilt_pos & 0x0f00) >> 8);
  _VISCA_append_byte(&packet, (tilt_pos & 0x00f0) >> 4);
  _VISCA_append_byte(&packet, tilt_pos & 0x000f);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_pantilt_limit_upright_clear(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  uint32_t pan_pos=0x7fff;
  uint32_t tilt_pos=0x7fff;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_PAN_TILTER);
  _VISCA_append_byte(&packet, VISCA_PT_LIMITSET);
  _VISCA_append_byte(&packet, VISCA_PT_LIMITSET_CLEAR);
  _VISCA_append_byte(&packet, VISCA_PT_LIMITSET_SET_UR);
  _VISCA_append_byte(&packet, (pan_pos & 0xf000) >> 12);
  _VISCA_append_byte(&packet, (pan_pos & 0x0f00) >> 8);
  _VISCA_append_byte(&packet, (pan_pos & 0x00f0) >> 4);
  _VISCA_append_byte(&packet, pan_pos & 0x000f);

  _VISCA_append_byte(&packet, (tilt_pos & 0xf000) >> 12);
  _VISCA_append_byte(&packet, (tilt_pos & 0x0f00) >> 8);
  _VISCA_append_byte(&packet, (tilt_pos & 0x00f0) >> 4);
  _VISCA_append_byte(&packet, tilt_pos & 0x000f);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_datascreen_on(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_PAN_TILTER);
  _VISCA_append_byte(&packet, VISCA_PT_DATASCREEN);
  _VISCA_append_byte(&packet, VISCA_PT_DATASCREEN_ON);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}

VISCA_API uint32_t
VISCA_set_datascreen_off(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_PAN_TILTER);
  _VISCA_append_byte(&packet, VISCA_PT_DATASCREEN);
  _VISCA_append_byte(&packet, VISCA_PT_DATASCREEN_OFF);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}

VISCA_API uint32_t
VISCA_set_datascreen_onoff(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_PAN_TILTER);
  _VISCA_append_byte(&packet, VISCA_PT_DATASCREEN);
  _VISCA_append_byte(&packet, VISCA_PT_DATASCREEN_ONOFF);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_register(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t reg_num, uint8_t reg_val)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_REGISTER_VALUE);
  _VISCA_append_byte(&packet, reg_num);
  _VISCA_append_byte(&packet, (reg_val & 0xF0) >>  4);
  _VISCA_append_byte(&packet, (reg_val & 0x0F));
  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


/***********************************/
/*       INQUIRY FUNCTIONS         */
/***********************************/

VISCA_API uint32_t
VISCA_get_videosystem(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t *system)
{
  VISCAPacket_t packet;
  uint32_t err;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_INQUIRY);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_PAN_TILTER);
  _VISCA_append_byte(&packet, VISCA_PT_VIDEOSYSTEM_INQ);
  err=_VISCA_send_packet_with_reply(iface, camera, &packet);
  if (err!=VISCA_SUCCESS)
    return err;
  else
    {
      *system=iface->ibuf[2];
      return VISCA_SUCCESS;
    }
}

VISCA_API uint32_t
VISCA_get_pantilt_mode(VISCAInterface_t *iface, VISCACamera_t *camera, uint16_t *status)
{
  VISCAPacket_t packet;
  uint32_t err;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_INQUIRY);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_PAN_TILTER);
  _VISCA_append_byte(&packet, VISCA_PT_MODE_INQ);
  err=_VISCA_send_packet_with_reply(iface, camera, &packet);
  if (err!=VISCA_SUCCESS)
    return err;
  else
    {
      *status = ((iface->ibuf[2] & 0xff) << 8) + (iface->ibuf[3] & 0xff);
      return VISCA_SUCCESS;
    }
}

VISCA_API uint32_t
VISCA_get_pantilt_maxspeed(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t *max_pan_speed, uint8_t *max_tilt_speed)
{
  VISCAPacket_t packet;
  uint32_t err;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_INQUIRY);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_PAN_TILTER);
  _VISCA_append_byte(&packet, VISCA_PT_MAXSPEED_INQ);
  err=_VISCA_send_packet_with_reply(iface, camera, &packet);
  if (err!=VISCA_SUCCESS)
    return err;
  else
    {
      *max_pan_speed = (iface->ibuf[2] & 0xff);
      *max_tilt_speed = (iface->ibuf[3] & 0xff);
      return VISCA_SUCCESS;
    }
}

VISCA_API uint32_t
VISCA_get_pantilt_position(VISCAInterface_t *iface, VISCACamera_t *camera, int *pan_position, int *tilt_position)
{
  VISCAPacket_t packet;
  uint32_t err;
  uint16_t pan_pos, tilt_pos;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_INQUIRY);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_PAN_TILTER);
  _VISCA_append_byte(&packet, VISCA_PT_POSITION_INQ);
  err=_VISCA_send_packet_with_reply(iface, camera, &packet);
  if (err!=VISCA_SUCCESS)
    return err;
  else
    {
      pan_pos  = ((iface->ibuf[3] & 0xf) << 12) + ((iface->ibuf[4] & 0xf) << 8) + ((iface->ibuf[5] & 0xf) << 4) + (iface->ibuf[6] & 0xf); 
      tilt_pos = ((iface->ibuf[7] & 0xf) << 12) + ((iface->ibuf[8] & 0xf) << 8) + ((iface->ibuf[9] & 0xf) << 4) + (iface->ibuf[10] & 0xf); 

      if (!iface->ibuf[2]) *pan_position=pan_pos;
      else *pan_position=((int)pan_pos) - 65536;
      if (tilt_pos<0x8000) *tilt_position=tilt_pos;
      else *tilt_position=((int)tilt_pos) - 65536;

      return VISCA_SUCCESS;
    }
}

VISCA_API uint32_t
VISCA_get_datascreen(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t *status)
{
  VISCAPacket_t packet;
  uint32_t err;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_INQUIRY);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_PAN_TILTER);
  _VISCA_append_byte(&packet, VISCA_PT_DATASCREEN_INQ);
  err=_VISCA_send_packet_with_reply(iface, camera, &packet);
  if (err!=VISCA_SUCCESS)
    return err;
  else
    {
      *status=iface->ibuf[2];
      return VISCA_SUCCESS;
    }
}


VISCA_API uint32_t
VISCA_get_register(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t reg_num, uint8_t* reg_val)
{
  VISCAPacket_t packet;
  uint32_t err;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_INQUIRY);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_REGISTER_VALUE);
  _VISCA_append_byte(&packet, reg_num);
  err=_VISCA_send_packet_with_reply(iface, camera, &packet);
  if (err!=VISCA_SUCCESS)
    return err;
  else
    {
      *reg_val=(iface->ibuf[2]<<4)+iface->ibuf[3];
      return VISCA_SUCCESS;
    }
}


/********************************/
/* SPECIAL FUNCTIONS FOR D30/31 */
/********************************/

VISCA_API uint32_t
VISCA_set_wide_con_lens(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t power)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA2);
  _VISCA_append_byte(&packet, VISCA_WIDE_CON_LENS);
  _VISCA_append_byte(&packet, VISCA_WIDE_CON_LENS_SET);
  _VISCA_append_byte(&packet, power);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_at_mode_onoff(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA2);
  _VISCA_append_byte(&packet, VISCA_AT_MODE);
  _VISCA_append_byte(&packet, VISCA_AT_ONOFF);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_at_mode(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t power)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA2);
  _VISCA_append_byte(&packet, VISCA_AT_MODE);
  _VISCA_append_byte(&packet, power);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_at_ae_onoff(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA2);
  _VISCA_append_byte(&packet, VISCA_AT_AE);
  _VISCA_append_byte(&packet, VISCA_AT_ONOFF);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_at_ae(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t power)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA2);
  _VISCA_append_byte(&packet, VISCA_AT_AE);
  _VISCA_append_byte(&packet, power);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_at_autozoom_onoff(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA2);
  _VISCA_append_byte(&packet, VISCA_AT_AUTOZOOM);
  _VISCA_append_byte(&packet, VISCA_AT_ONOFF);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_at_autozoom(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t power)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA2);
  _VISCA_append_byte(&packet, VISCA_AT_AUTOZOOM);
  _VISCA_append_byte(&packet, power);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_atmd_framedisplay_onoff(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA2);
  _VISCA_append_byte(&packet, VISCA_ATMD_FRAMEDISPLAY);
  _VISCA_append_byte(&packet, VISCA_AT_ONOFF);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_atmd_framedisplay(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t power)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA2);
  _VISCA_append_byte(&packet, VISCA_ATMD_FRAMEDISPLAY);
  _VISCA_append_byte(&packet, power);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_at_frameoffset_onoff(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA2);
  _VISCA_append_byte(&packet, VISCA_AT_FRAMEOFFSET);
  _VISCA_append_byte(&packet, VISCA_AT_ONOFF);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_at_frameoffset(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t power)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA2);
  _VISCA_append_byte(&packet, VISCA_AT_FRAMEOFFSET);
  _VISCA_append_byte(&packet, power);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_atmd_startstop(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA2);
  _VISCA_append_byte(&packet, VISCA_ATMD_STARTSTOP);
  _VISCA_append_byte(&packet, VISCA_AT_ONOFF);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_at_chase(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t power)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA2);
  _VISCA_append_byte(&packet, VISCA_AT_CHASE);
  _VISCA_append_byte(&packet, power);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}

VISCA_API uint32_t
VISCA_set_at_chase_next(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA2);
  _VISCA_append_byte(&packet, VISCA_AT_CHASE);
  _VISCA_append_byte(&packet, VISCA_AT_CHASE_NEXT);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_md_mode_onoff(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA2);
  _VISCA_append_byte(&packet, VISCA_MD_MODE);
  _VISCA_append_byte(&packet, VISCA_MD_ONOFF);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_md_mode(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t power)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA2);
  _VISCA_append_byte(&packet, VISCA_MD_MODE);
  _VISCA_append_byte(&packet, power);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_md_frame(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA2);
  _VISCA_append_byte(&packet, VISCA_MD_FRAME);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_md_detect(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA2);
  _VISCA_append_byte(&packet, VISCA_MD_DETECT);
  _VISCA_append_byte(&packet, VISCA_MD_ONOFF);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_at_entry(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t power)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA2);
  _VISCA_append_byte(&packet, VISCA_AT_ENTRY);
  _VISCA_append_byte(&packet, power);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_at_lostinfo(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_PAN_TILTER);
  _VISCA_append_byte(&packet, VISCA_ATMD_LOSTINFO1);
  _VISCA_append_byte(&packet, VISCA_ATMD_LOSTINFO2);
  _VISCA_append_byte(&packet, VISCA_AT_LOSTINFO);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_md_lostinfo(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_PAN_TILTER);
  _VISCA_append_byte(&packet, VISCA_ATMD_LOSTINFO1);
  _VISCA_append_byte(&packet, VISCA_ATMD_LOSTINFO2);
  _VISCA_append_byte(&packet, VISCA_MD_LOSTINFO);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_md_adjust_ylevel(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t power)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA2);
  _VISCA_append_byte(&packet, VISCA_MD_ADJUST_YLEVEL);
  _VISCA_append_byte(&packet, VISCA_MD_ADJUST);
  _VISCA_append_byte(&packet, power);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_md_adjust_huelevel(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t power)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA2);
  _VISCA_append_byte(&packet, VISCA_MD_ADJUST_HUELEVEL);
  _VISCA_append_byte(&packet, VISCA_MD_ADJUST);
  _VISCA_append_byte(&packet, power);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_md_adjust_size(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t power)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA2);
  _VISCA_append_byte(&packet, VISCA_MD_ADJUST_SIZE);
  _VISCA_append_byte(&packet, VISCA_MD_ADJUST);
  _VISCA_append_byte(&packet, power);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_md_adjust_disptime(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t power)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA2);
  _VISCA_append_byte(&packet, VISCA_MD_ADJUST_DISPTIME);
  _VISCA_append_byte(&packet, VISCA_MD_ADJUST);
  _VISCA_append_byte(&packet, power);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_md_adjust_refmode(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t power)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA2);
  _VISCA_append_byte(&packet, VISCA_MD_ADJUST_REFMODE);
  _VISCA_append_byte(&packet, power);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_md_adjust_reftime(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t power)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA2);
  _VISCA_append_byte(&packet, VISCA_MD_ADJUST_REFTIME);
  _VISCA_append_byte(&packet, VISCA_MD_ADJUST);
  _VISCA_append_byte(&packet, power);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_md_measure_mode1_onoff(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA2);
  _VISCA_append_byte(&packet, VISCA_MD_MEASURE_MODE_1);
  _VISCA_append_byte(&packet, VISCA_MD_ONOFF);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_md_measure_mode1(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t power)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA2);
  _VISCA_append_byte(&packet, VISCA_MD_MEASURE_MODE_1);
  _VISCA_append_byte(&packet, power);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_md_measure_mode2_onoff(VISCAInterface_t *iface, VISCACamera_t *camera)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA2);
  _VISCA_append_byte(&packet, VISCA_MD_MEASURE_MODE_2);
  _VISCA_append_byte(&packet, VISCA_MD_ONOFF);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_set_md_measure_mode2(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t power)
{
  VISCAPacket_t packet;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_COMMAND);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA2);
  _VISCA_append_byte(&packet, VISCA_MD_MEASURE_MODE_2);
  _VISCA_append_byte(&packet, power);

  return _VISCA_send_packet_with_reply(iface, camera, &packet);
}


VISCA_API uint32_t
VISCA_get_keylock(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t *power)
{
  VISCAPacket_t packet;
  uint32_t err;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_INQUIRY);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_KEYLOCK);
  err=_VISCA_send_packet_with_reply(iface, camera, &packet);
  if (err!=VISCA_SUCCESS)
    return err;
  else
    {
      *power=iface->ibuf[2];
      return VISCA_SUCCESS;
    }
}


VISCA_API uint32_t
VISCA_get_wide_con_lens(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t *power)
{
  VISCAPacket_t packet;
  uint32_t err;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_INQUIRY);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA1);
  _VISCA_append_byte(&packet, VISCA_WIDE_CON_LENS);
  err=_VISCA_send_packet_with_reply(iface, camera, &packet);
  if (err!=VISCA_SUCCESS)
    return err;
  else
    {
      *power=iface->ibuf[2];
      return VISCA_SUCCESS;
    }
}


VISCA_API uint32_t
VISCA_get_atmd_mode(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t *power)
{
  VISCAPacket_t packet;
  uint32_t err;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_INQUIRY);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA2);
  _VISCA_append_byte(&packet, VISCA_ATMD_MODE);
  err=_VISCA_send_packet_with_reply(iface, camera, &packet);
  if (err!=VISCA_SUCCESS)
    return err;
  else
    {
      *power=iface->ibuf[2];
      return VISCA_SUCCESS;
    }
}


VISCA_API uint32_t
VISCA_get_at_mode(VISCAInterface_t *iface, VISCACamera_t *camera, uint16_t *value)
{
  VISCAPacket_t packet;
  uint32_t err;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_INQUIRY);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA2);
  _VISCA_append_byte(&packet, VISCA_AT_MODE_QUERY);
  err=_VISCA_send_packet_with_reply(iface, camera, &packet);
  if (err!=VISCA_SUCCESS)
    return err;
  else
    {
      *value=((iface->ibuf[2] & 0xff) << 8) + (iface->ibuf[3] & 0xff);
      return VISCA_SUCCESS;
    }
}


VISCA_API uint32_t
VISCA_get_at_entry(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t *power)
{
  VISCAPacket_t packet;
  uint32_t err;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_INQUIRY);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA2);
  _VISCA_append_byte(&packet, VISCA_AT_ENTRY);
  err=_VISCA_send_packet_with_reply(iface, camera, &packet);
  if (err!=VISCA_SUCCESS)
    return err;
  else
    {
      *power=iface->ibuf[2];
      return VISCA_SUCCESS;
    }
}


VISCA_API uint32_t
VISCA_get_md_mode(VISCAInterface_t *iface, VISCACamera_t *camera, uint16_t *value)
{
  VISCAPacket_t packet;
  uint32_t err;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_INQUIRY);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA2);
  _VISCA_append_byte(&packet, VISCA_MD_MODE_QUERY);
  err=_VISCA_send_packet_with_reply(iface, camera, &packet);
  if (err!=VISCA_SUCCESS)
    return err;
  else
    {
      *value=((iface->ibuf[2] & 0xff) << 8) + (iface->ibuf[3] & 0xff);
      return VISCA_SUCCESS;
    }
}


VISCA_API uint32_t
VISCA_get_md_ylevel(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t *power)
{
  VISCAPacket_t packet;
  uint32_t err;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_INQUIRY);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA2);
  _VISCA_append_byte(&packet, VISCA_MD_ADJUST_YLEVEL);
  err=_VISCA_send_packet_with_reply(iface, camera, &packet);
  if (err!=VISCA_SUCCESS)
    return err;
  else
    {
      *power=(iface->ibuf[3] & 0x0f);
      return VISCA_SUCCESS;
    }
}


VISCA_API uint32_t
VISCA_get_md_huelevel(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t *power)
{
  VISCAPacket_t packet;
  uint32_t err;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_INQUIRY);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA2);
  _VISCA_append_byte(&packet, VISCA_MD_ADJUST_HUELEVEL);
  err=_VISCA_send_packet_with_reply(iface, camera, &packet);
  if (err!=VISCA_SUCCESS)
    return err;
  else
    {
      *power=(iface->ibuf[3] & 0x0f);
      return VISCA_SUCCESS;
    }
}


VISCA_API uint32_t
VISCA_get_md_size(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t *power)
{
  VISCAPacket_t packet;
  uint32_t err;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_INQUIRY);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA2);
  _VISCA_append_byte(&packet, VISCA_MD_ADJUST_SIZE);
  err=_VISCA_send_packet_with_reply(iface, camera, &packet);
  if (err!=VISCA_SUCCESS)
    return err;
  else
    {
      *power=(iface->ibuf[3] & 0x0f);
      return VISCA_SUCCESS;
    }
}


VISCA_API uint32_t
VISCA_get_md_disptime(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t *power)
{
  VISCAPacket_t packet;
  uint32_t err;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_INQUIRY);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA2);
  _VISCA_append_byte(&packet, VISCA_MD_ADJUST_DISPTIME);
  err=_VISCA_send_packet_with_reply(iface, camera, &packet);
  if (err!=VISCA_SUCCESS)
    return err;
  else
    {
      *power=(iface->ibuf[3] & 0x0f);
      return VISCA_SUCCESS;
    }
}


VISCA_API uint32_t
VISCA_get_md_refmode(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t *power)
{
  VISCAPacket_t packet;
  uint32_t err;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_INQUIRY);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA2);
  _VISCA_append_byte(&packet, VISCA_MD_ADJUST_REFMODE);
  err=_VISCA_send_packet_with_reply(iface, camera, &packet);
  if (err!=VISCA_SUCCESS)
    return err;
  else
    {
      *power=iface->ibuf[2];
      return VISCA_SUCCESS;
    }
}


VISCA_API uint32_t
VISCA_get_md_reftime(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t *power)
{
  VISCAPacket_t packet;
  uint32_t err;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_INQUIRY);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA2);
  _VISCA_append_byte(&packet, VISCA_MD_REFTIME_QUERY);
  err=_VISCA_send_packet_with_reply(iface, camera, &packet);
  if (err!=VISCA_SUCCESS)
    return err;
  else
    {
      *power=(iface->ibuf[3] & 0x0f);
      return VISCA_SUCCESS;
    }
}



VISCA_API uint32_t
VISCA_get_at_obj_pos(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t *xpos, uint8_t *ypos, uint8_t *status)
{
  VISCAPacket_t packet;
  uint32_t err;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_INQUIRY);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA2);
  _VISCA_append_byte(&packet, VISCA_AT_POSITION);
  err=_VISCA_send_packet_with_reply(iface, camera, &packet);
  if (err!=VISCA_SUCCESS)
    return err;
  else
    {
      *xpos=iface->ibuf[2];
      *ypos=iface->ibuf[3];
      *status=(iface->ibuf[4] & 0x0f);
      return VISCA_SUCCESS;
    }
}


VISCA_API uint32_t
VISCA_get_md_obj_pos(VISCAInterface_t *iface, VISCACamera_t *camera, uint8_t *xpos, uint8_t *ypos, uint8_t *status)
{
  VISCAPacket_t packet;
  uint32_t err;

  _VISCA_init_packet(&packet);
  _VISCA_append_byte(&packet, VISCA_INQUIRY);
  _VISCA_append_byte(&packet, VISCA_CATEGORY_CAMERA2);
  _VISCA_append_byte(&packet, VISCA_MD_POSITION);
  err=_VISCA_send_packet_with_reply(iface, camera, &packet);
  if (err!=VISCA_SUCCESS)
    return err;
  else
    {
      *xpos=iface->ibuf[2];
      *ypos=iface->ibuf[3];
      *status=(iface->ibuf[4] & 0x0f);
      return VISCA_SUCCESS;
    }
}
