/*
  wl_definitions.h - Library for Arduino Wifi shield.
  Copyright (c) 2011-2014 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
/*
 * wl_definitions.h
 *
 *  Created on: Mar 6, 2011
 *      Author: dlafauci
 */

#ifndef WL_DEFINITIONS_H
#define WL_DEFINITIONS_H

// Maximum size of a SSID
#define WL_SSID_MAX_LENGTH          32
// Length of passphrase. Valid lengths are 8-63.
#define WL_WPA_KEY_MAX_LENGTH       63
// Length of key in bytes. Valid values are 5 and 13.
#define WL_WEP_KEY_MAX_LENGTH       13
// Size of a MAC-address or BSSID
#define WL_MAC_ADDR_LENGTH          6
// Size of a MAC-address or BSSID
#define WL_IPV4_LENGTH              4
// Maximum size of a SSID list
#define WL_NETWORKS_LIST_MAXNUM     50
// Maxmium number of socket
#define	MAX_SOCK_NUM                4
// Socket not available constant
#define SOCK_NOT_AVAIL              255
// Default state value for Wifi state field
#define NA_STATE                    -1
//Maximum number of attempts to establish wifi connection
#define WL_MAX_ATTEMPT_CONNECTION   10

typedef enum {
    WL_NO_SHIELD = 255,
    WL_IDLE_STATUS = 0,
    WL_NO_SSID_AVAIL,
    WL_SCAN_COMPLETED,
    WL_CONNECTED,
    WL_CONNECT_FAILED,
    WL_CONNECTION_LOST,
    WL_DISCONNECTED
} wl_status_t;

/* Encryption modes */
enum wl_enc_type {  /* Values map to 802.11 encryption suites... */
    ENC_TYPE_WEP  = 5,
    ENC_TYPE_WPA  = 2,
    ENC_TYPE_WPA3 = 3,
    ENC_TYPE_WPA2 = 4,
    /* ... except these two, 7 and 8 are reserved in 802.11-2007 */
    ENC_TYPE_NONE = 7,
    ENC_TYPE_AUTO = 8
};

/* RTK added type */
#ifndef WEP_ENABLED

#define WEP_ENABLED         0x0001
#define TKIP_ENABLED        0x0002
#define AES_ENABLED         0x0004
#define WSEC_SWFLAG         0x0008

#define SHARED_ENABLED      0x00008000
#define WPA_SECURITY        0x00200000
#define WPA2_SECURITY       0x00400000
#define WPA3_SECURITY       0x00800000
#define WPS_ENABLED         0x10000000

#endif // #ifndef WEP_ENABLED

/* redefined from enum rtw_security_t */
#define SECURITY_OPEN            (0)
#define SECURITY_WEP_PSK         (WEP_ENABLED)
#define SECURITY_WEP_SHARED      (WEP_ENABLED | SHARED_ENABLED)
#define SECURITY_WPA_TKIP_PSK    (WPA_SECURITY  | TKIP_ENABLED)
#define SECURITY_WPA_AES_PSK     (WPA_SECURITY  | AES_ENABLED)
#define SECURITY_WPA2_AES_PSK    (WPA2_SECURITY | AES_ENABLED)
#define SECURITY_WPA2_TKIP_PSK   (WPA2_SECURITY | TKIP_ENABLED)
#define SECURITY_WPA2_MIXED_PSK  (WPA2_SECURITY | AES_ENABLED | TKIP_ENABLED)
#define SECURITY_WPA_WPA2_MIXED  (WPA_SECURITY  | WPA2_SECURITY)
#define SECURITY_WPA3_AES_PSK    (WPA3_SECURITY | AES_ENABLED)
#define SECURITY_WPA2_WPA3_MIXED (WPA2_SECURITY | WPA3_SECURITY | AES_ENABLED)

#endif /* WL_DEFINITIONS_H_ */
