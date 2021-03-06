/**
 * FreeRDP: A Remote Desktop Protocol Implementation
 * Extended Input channel common definitions
 *
 * Copyright 2013 Marc-Andre Moreau <marcandre.moreau@gmail.com>
 * Copyright 2014 Thincast Technologies Gmbh.
 * Copyright 2014 David FORT <contact@hardening-consulting.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef FREERDP_CHANNEL_RDPEI_H
#define FREERDP_CHANNEL_RDPEI_H

#include <winpr/wtypes.h>

#define RDPINPUT_HEADER_LENGTH 6

#define RDPEI_DVC_CHANNEL_NAME "Microsoft::Windows::RDS::Input"

/** @brief protocol version */
enum
{
	RDPINPUT_PROTOCOL_V10 = 0x00010000,
	RDPINPUT_PROTOCOL_V101 = 0x00010001,
	RDPINPUT_PROTOCOL_V200 = 0x00020000,
	RDPINPUT_PROTOCOL_V300 = 0x00030000
};

/* Client Ready Flags */
#if !defined(DEFINE_NO_DEPRECATED)
#define READY_FLAGS_SHOW_TOUCH_VISUALS 0x00000001          /* Deprecated */
#define READY_FLAGS_DISABLE_TIMESTAMP_INJECTION 0x00000002 /* Deprecated */
#endif

#define CS_READY_FLAGS_SHOW_TOUCH_VISUALS 0x00000001
#define CS_READY_FLAGS_DISABLE_TIMESTAMP_INJECTION 0x00000002
#define CS_READY_FLAGS_ENABLE_MULTIPEN_INJECTION 0x00000004

#define CONTACT_DATA_CONTACTRECT_PRESENT 0x0001
#define CONTACT_DATA_ORIENTATION_PRESENT 0x0002
#define CONTACT_DATA_PRESSURE_PRESENT 0x0004

typedef enum
{
	PEN_CONTACT_PENFLAGS_PRESENT = 0x0001,
	PEN_CONTACT_PRESSURE_PRESENT = 0x0002,
	PEN_CONTACT_ROTATION_PRESENT = 0x0004,
	PEN_CONTACT_TILTX_PRESENT = 0x0008,
	PEN_CONTACT_TILTY_PRESENT = 0x0010
} RDPINPUT_PEN_FIELDS_PRESENT;

typedef enum
{
	CONTACT_FLAG_DOWN = 0x0001,
	CONTACT_FLAG_UPDATE = 0x0002,
	CONTACT_FLAG_UP = 0x0004,
	CONTACT_FLAG_INRANGE = 0x0008,
	CONTACT_FLAG_INCONTACT = 0x0010,
	CONTACT_FLAG_CANCELED = 0x0020
} RDPINPUT_CONTACT_FLAGS;

typedef enum
{
	PEN_FLAG_BARREL_PRESSED = 0x0001,
	PEN_FLAG_ERASER_PRESSED = 0x0002,
	PEN_FLAG_INVERTED = 0x0004
} RDPINPUT_PEN_FLAGS;

/** @brief a contact point */
struct _RDPINPUT_CONTACT_DATA
{
	UINT32 contactId;
	UINT32 fieldsPresent;
	INT32 x;
	INT32 y;
	UINT32 contactFlags;
	INT32 contactRectLeft;
	INT32 contactRectTop;
	INT32 contactRectRight;
	INT32 contactRectBottom;
	UINT32 orientation;
	UINT32 pressure;
};
typedef struct _RDPINPUT_CONTACT_DATA RDPINPUT_CONTACT_DATA;

/** @brief a frame containing contact points */
struct _RDPINPUT_TOUCH_FRAME
{
	UINT32 contactCount;
	UINT64 frameOffset;
	RDPINPUT_CONTACT_DATA* contacts;
};
typedef struct _RDPINPUT_TOUCH_FRAME RDPINPUT_TOUCH_FRAME;

/** @brief a touch event with some frames*/
struct _RDPINPUT_TOUCH_EVENT
{
	UINT32 encodeTime;
	UINT16 frameCount;
	RDPINPUT_TOUCH_FRAME* frames;
};
typedef struct _RDPINPUT_TOUCH_EVENT RDPINPUT_TOUCH_EVENT;

struct _RDPINPUT_PEN_CONTACT
{
	UINT8 deviceId;
	UINT16 fieldsPresent;
	INT32 x;
	INT32 y;
	UINT32 contactFlags;
	UINT32 penFlags;
	UINT32 pressure;
	UINT16 rotation;
	INT16 tiltX;
	INT16 tiltY;
};
typedef struct _RDPINPUT_PEN_CONTACT RDPINPUT_PEN_CONTACT;

struct _RDPINPUT_PEN_FRAME
{
	UINT16 contactCount;
	UINT64 frameOffset;
	RDPINPUT_PEN_CONTACT* contacts;
};
typedef struct _RDPINPUT_PEN_FRAME RDPINPUT_PEN_FRAME;

/** @brief a touch event with some frames*/
struct _RDPINPUT_PEN_EVENT
{
	UINT32 encodeTime;
	UINT16 frameCount;
	RDPINPUT_PEN_FRAME* frames;
};
typedef struct _RDPINPUT_PEN_EVENT RDPINPUT_PEN_EVENT;
#endif /* FREERDP_CHANNEL_RDPEI_H */
