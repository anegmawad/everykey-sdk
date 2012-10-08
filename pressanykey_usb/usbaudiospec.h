// Structures and values taken from the usb audio spec. This is rather platform independent


#ifndef _USBAUDIOSPEC_
#define _USBAUDIOSPEC_

/** Class-specific desriptor types */
typedef enum USB_AUDIO_DESCRIPTOR_TYPE {
	USB_DESC_AUDIO_DEVICE				= 0x21,
	USB_DESC_AUDIO_CONFIGURATION		= 0x22,
	USB_DESC_AUDIO_STRING				= 0x23,
	USB_DESC_AUDIO_INTERFACE			= 0x24,
	USB_DESC_AUDIO_ENDPOINT				= 0x25
} USB_AUDIO_DESCRIPTOR_TYPE;

/** USB Audio interface subclasses */
typedef enum USB_AUDIO_INTERFACE_SUBCLASS_CODE {
	USB_AUDIO_INTERFACE_AUDIOCONTROL	= 0x01,
	USB_AUDIO_INTERFACE_AUDIOSTREAMING	= 0x02,
	USB_AUDIO_INTERFACE_MIDISTREAMING	= 0x03
} USB_AUDIO_INTERFACE_SUBCLASS_CODE;

/** USB Audio endpoint subclasses */
typedef enum USB_AUDIO_ENDPOINT_SUBCLASS_CODE {
	USB_AUDIO_ENDPOINT_GENERAL	= 0x01
} USB_AUDIO_ENDPOINT_SUBCLASS_CODE;

/** USB Audio Control interface-specific descriptor subclasses */
typedef enum USB_AUDIO_CONTROL_INTERFACE_DESCRIPTOR_SUBTYPE {
	USB_AUDIO_CONTROL_INTERFACE_DESCRIPTOR_HEADER			= 0x01,
	USB_AUDIO_CONTROL_INTERFACE_DESCRIPTOR_INPUT_TERMINAL	= 0x02,
	USB_AUDIO_CONTROL_INTERFACE_DESCRIPTOR_OUTPUT_TERMINAL	= 0x03,
	USB_AUDIO_CONTROL_INTERFACE_DESCRIPTOR_MIXER_UNIT		= 0x04,
	USB_AUDIO_CONTROL_INTERFACE_DESCRIPTOR_SELECTOR_UNIT	= 0x05,
	USB_AUDIO_CONTROL_INTERFACE_DESCRIPTOR_FEATURE_UNIT		= 0x06,
	USB_AUDIO_CONTROL_INTERFACE_DESCRIPTOR_PROCESSING_UNIT	= 0x07,
	USB_AUDIO_CONTROL_INTERFACE_DESCRIPTOR_EXTENSION_UNIT	= 0x08
} USB_AUDIO_CONTROL_INTERFACE_DESCRIPTOR_SUBTYPE;

/** USB Audio Stream interface-specific descriptor subclasses */
typedef enum USB_AUDIO_STREAM_INTERFACE_DESCRIPTOR_SUBTYPE {
	USB_AUDIO_STREAM_INTERFACE_DESCRIPTOR_GENERAL			= 0x01,
	USB_AUDIO_STREAM_INTERFACE_DESCRIPTOR_FORMAT_TYPE		= 0x02,
	USB_AUDIO_STREAM_INTERFACE_DESCRIPTOR_FORMAT_SPECIFIC	= 0x03
} USB_AUDIO_STREAM_INTERFACE_DESCRIPTOR_SUBTYPE;

/** USB Audio endpoint-specific descriptor subclasses */
typedef enum USB_AUDIO_ENDPOINT_DESCRIPTOR_SUBTYPE {
	USB_AUDIO_ENDPOINT_DESCRIPTOR_UNDEFINED					= 0x01,
	USB_AUDIO_ENDPOINT_DESCRIPTOR_GENERAL					= 0x02
} USB_AUDIO_ENDPOINT_DESCRIPTOR_SUBTYPE;

/** endpoint flags for isoch audio data endpoint descriptors */
typedef enum USB_AUDIO_ENDPOINT_FLAGS {
	USB_AUDIO_ENDPOINT_FLAG_SAMPLING_FREQUENCY_SUPPORTED	= 0x01,
	USB_AUDIO_ENDPOINT_FLAG_PITCH_SUPPORTED					= 0x02,
	USB_AUDIO_ENDPOINT_FLAG_MAX_PACKET_SIZE_ONLY			= 0x80,
} USB_AUDIO_ENDPOINT_FLAGS;

/** units for isoch audio data endpoint descriptors */
typedef enum USB_AUDIO_LOCKDELAY_UNITS {
	USB_AUDIO_LOCKDELAY_UNDEFINED							= 0x00,
	USB_AUDIO_LOCKDELAY_MILLISECONDS						= 0x01,
	USB_AUDIO_LOCKDELAY_SAMPLES								= 0x02
} USB_AUDIO_LOCKDELAY_UNITS;

/** values for USB Audio wFormatTag (Format types 1-3, USB Audio Format Spec, Appendix A) */
typedef enum USB_AUDIO_FORMATTAG {
	USB_AUDIO_FORMAT_I_UNDEFINED		= 0x0000,
	USB_AUDIO_FORMAT_I_PCM				= 0x0001,
	USB_AUDIO_FORMAT_I_PCM8				= 0x0002,
	USB_AUDIO_FORMAT_I_IEEE_FLOAT		= 0x0003,
	USB_AUDIO_FORMAT_I_ALAW				= 0x0004,
	USB_AUDIO_FORMAT_I_MULAW			= 0x0005,
	USB_AUDIO_FORMAT_II_UNDEFINED		= 0x1000,
	USB_AUDIO_FORMAT_II_MPEG			= 0x1001,
	USB_AUDIO_FORMAT_II_AC3				= 0x1002,
	USB_AUDIO_FORMAT_III_UNDEFINED		= 0x2000,
	USB_AUDIO_FORMAT_III_AC3			= 0x2001,
	USB_AUDIO_FORMAT_III_MPEG1LAYER1	= 0x2002,
	USB_AUDIO_FORMAT_III_MPEG1LAYER2	= 0x2003,
	USB_AUDIO_FORMAT_III_MPEG1LAYER3	= 0x2003,
	USB_AUDIO_FORMAT_III_MPEG2_NOEXT	= 0x2003,
	USB_AUDIO_FORMAT_III_MPEG2_EXT		= 0x2004,
	USB_AUDIO_FORMAT_III_MPEG2LAYER1LS	= 0x2005,
	USB_AUDIO_FORMAT_III_MPEG2LAYER2LS	= 0x2006,
	USB_AUDIO_FORMAT_III_MPEG2LAYER3LS	= 0x2006
} USB_AUDIO_FORMATTAG;

/** USB Audio format types (USB Audio Format Spec, Appendix A.2) */
typedef enum USB_AUDIO_FORMATTYPE {
	USB_AUDIO_FORMATTYPE_UNDEFINED = 0,
	USB_AUDIO_FORMATTYPE_I = 1,
	USB_AUDIO_FORMATTYPE_II = 2,
	USB_AUDIO_FORMATTYPE_III = 3
} USB_AUDIO_FORMATTYPE;

/** USB Audio class-specific request codes (USB Audio Spec Appendix A.9)
 * Usually sent to control interface. */
typedef enum USB_AUDIO_REQUEST {
	USB_AUDIO_REQ_UNDEFINED			= 0x00,
	USB_AUDIO_REQ_SET_CUR			= 0x01,
	USB_AUDIO_REQ_SET_MIN			= 0x02,
	USB_AUDIO_REQ_SET_MAX			= 0x03,
	USB_AUDIO_REQ_SET_RES			= 0x04,
	USB_AUDIO_REQ_SET_MEM			= 0x05,
	USB_AUDIO_REQ_GET_CUR			= 0x81,
	USB_AUDIO_REQ_GET_MIN			= 0x82,
	USB_AUDIO_REQ_GET_MAX			= 0x83,
	USB_AUDIO_REQ_GET_RES			= 0x84,
	USB_AUDIO_REQ_GET_MEM			= 0x85,
	USB_AUDIO_REQ_GET_STAT			= 0xff
} USB_AUDIO_REQUEST;
	
/** USB Audio control selectors, sent to units (USB Audio Spec A.10) */
typedef enum USB_AUDIO_CONTROL_SELECTOR {
	USB_AUDIO_CSEL_TERMINAL_COPY_PROTECT	= 0x01,
	USB_AUDIO_CSEL_FEATURE_MUTE				= 0x01,
	USB_AUDIO_CSEL_FEATURE_VOLUME			= 0x02,
	USB_AUDIO_CSEL_FEATURE_BASS				= 0x03,
	USB_AUDIO_CSEL_FEATURE_MID				= 0x04,
	USB_AUDIO_CSEL_FEATURE_TREBLE			= 0x05,
	USB_AUDIO_CSEL_FEATURE_EQ				= 0x06,
	USB_AUDIO_CSEL_FEATURE_AUTOGAIN			= 0x07,
	USB_AUDIO_CSEL_FEATURE_DELAY			= 0x08,
	USB_AUDIO_CSEL_FEATURE_BASSBOOST		= 0x09,
	USB_AUDIO_CSEL_FEATURE_LOUDNESS			= 0x0A,
	USB_AUDIO_CSEL_UPDOWNMIX_ENABLE			= 0x01,
	USB_AUDIO_CSEL_UPDOWNMIX_SELECT			= 0x02,
	USB_AUDIO_CSEL_DOLBYPL_ENABLE			= 0x01,
	USB_AUDIO_CSEL_DOLBYPL_SELECT			= 0x02,
	USB_AUDIO_CSEL_3D_ENABLE				= 0x01,
	USB_AUDIO_CSEL_3D_SPACIOUSNESS			= 0x02,
	USB_AUDIO_CSEL_REVERB_ENABLE			= 0x01,
	USB_AUDIO_CSEL_REVERB_LEVEL				= 0x02,
	USB_AUDIO_CSEL_REVERB_TIME				= 0x03,
	USB_AUDIO_CSEL_REVERB_FEEDBACK			= 0x04,
	USB_AUDIO_CSEL_CHORUS_ENABLE			= 0x01,
	USB_AUDIO_CSEL_CHORUS_LEVEL				= 0x02,
	USB_AUDIO_CSEL_CHORUS_RATE				= 0x03,
	USB_AUDIO_CSEL_CHORUS_DEPTH				= 0x04,
	USB_AUDIO_CSEL_COMPR_ENABLE				= 0x01,
	USB_AUDIO_CSEL_COMPR_RATE				= 0x02,
	USB_AUDIO_CSEL_COMPR_MAXAMPL			= 0x03,
	USB_AUDIO_CSEL_COMPR_THRESHOLD			= 0x04,
	USB_AUDIO_CSEL_COMPR_ATTACK				= 0x05,
	USB_AUDIO_CSEL_COMPR_RELEASE			= 0x06,
	USB_AUDIO_CSEL_EXTENSION_ENABLE			= 0x01,
	USB_AUDIO_CSEL_ENDPOINT_FREQ			= 0x01,
	USB_AUDIO_CSEL_ENDPOINT_PITCH			= 0x02
} USB_AUDIO_CONTROL_SELECTOR;

/** bits for use in the Audio class isochronous audio data endpoint descriptor (USB Audio spec 4.6.1.2) */
typedef enum USB_AUDIO_EP_ATTRIBUTES {
	USB_AUDIO_EP_ATTRIBUTE_FREQ = 0x01,
	USB_AUDIO_EP_ATTRIBUTE_PITCH = 0x02
} USB_AUDIO_EP_ATTRIBUTES;
	
	
/** Terminal type codes for use in terminal descriptors (USB Audio Terminal Types spec) */
typedef enum USB_AUDIO_TERMINAL_TYPE {
	USB_AUDIO_TERMINAL_USB_UNDEFINED = 0x0100,
	USB_AUDIO_TERMINAL_USB_STREAMING = 0x0101,
	USB_AUDIO_TERMINAL_USB_VENDORSPECIFIC = 0x0102,
	USB_AUDIO_TERMINAL_IN_UNDEFINED = 0x0200,
	USB_AUDIO_TERMINAL_IN_MICROPHONE = 0x0201,
	USB_AUDIO_TERMINAL_IN_DESKTOP_MICROPHONE = 0x0202,
	USB_AUDIO_TERMINAL_IN_PERSONAL_MICROPHONE = 0x0203,
	USB_AUDIO_TERMINAL_IN_OMNIDIR_MICROPHONE = 0x0204,
	USB_AUDIO_TERMINAL_IN_MICROPHONE_ARRAY = 0x0205,
	USB_AUDIO_TERMINAL_OUT_UNDEFINED = 0x0300,
	USB_AUDIO_TERMINAL_OUT_SPEAKER = 0x0301,
	USB_AUDIO_TERMINAL_OUT_HEADPHONES = 0x0302,
	USB_AUDIO_TERMINAL_OUT_HMD = 0x0303,
	USB_AUDIO_TERMINAL_OUT_DESKTOP_SPEAKER = 0x0304,
	USB_AUDIO_TERMINAL_OUT_ROOM_SPEAKER = 0x0305,
	USB_AUDIO_TERMINAL_OUT_COMM_SPEAKER = 0x0306,
	USB_AUDIO_TERMINAL_OUT_LFE_SPEAKER = 0x0307,
	USB_AUDIO_TERMINAL_BIDI_UNDEFINED = 0x0400,
	USB_AUDIO_TERMINAL_BIDI_HANDSET = 0x0401,
	USB_AUDIO_TERMINAL_BIDI_HEADSET = 0x0402,
	USB_AUDIO_TERMINAL_BIDI_SPEAKERPHONE = 0x0403,
	USB_AUDIO_TERMINAL_BIDI_SPEAKERPHONE_ECHOSUPPRESS = 0x0404,
	USB_AUDIO_TERMINAL_BIDI_SPEAKERPHONE_ECHOCANCEL = 0x0405,
	USB_AUDIO_TERMINAL_TEL_UNDEFINED = 0x0500,
	USB_AUDIO_TERMINAL_TEL_PHONELINE = 0x0501,
	USB_AUDIO_TERMINAL_TEL_TELEPHONE = 0x0502,
	USB_AUDIO_TERMINAL_TEL_DOWNLINEPHONE = 0x0503,
	USB_AUDIO_TERMINAL_EXT_UNDEFINED = 0x0600,
	USB_AUDIO_TERMINAL_EXT_ANALOG_CONN = 0x0601,
	USB_AUDIO_TERMINAL_EXT_DIGIAUDIO_INTF = 0x0602,
	USB_AUDIO_TERMINAL_EXT_LINE_CONN = 0x0603,
	USB_AUDIO_TERMINAL_EXT_LEGACY_AUDIO = 0x0604,
	USB_AUDIO_TERMINAL_EXT_SPDIF = 0x0605,
	USB_AUDIO_TERMINAL_EXT_1394_DA = 0x0606,
	USB_AUDIO_TERMINAL_EXT_1394_DV = 0x0607,
	USB_AUDIO_TERMINAL_EMB_UNDEFINED = 0x0700,
	USB_AUDIO_TERMINAL_EMB_CALIB_NOISE = 0x0701,
	USB_AUDIO_TERMINAL_EMB_EQUALIZE_NOISE = 0x0702,
	USB_AUDIO_TERMINAL_EMB_CD = 0x0703,
	USB_AUDIO_TERMINAL_EMB_DAT = 0x0704,
	USB_AUDIO_TERMINAL_EMB_DCC = 0x0705,
	USB_AUDIO_TERMINAL_EMB_MINIDISC = 0x0706,
	USB_AUDIO_TERMINAL_EMB_TAPE = 0x0707,
	USB_AUDIO_TERMINAL_EMB_PHONO = 0x0708,
	USB_AUDIO_TERMINAL_EMB_VCR = 0x0709,
	USB_AUDIO_TERMINAL_EMB_VIDEODISC = 0x070A,
	USB_AUDIO_TERMINAL_EMB_DVD = 0x070B,
	USB_AUDIO_TERMINAL_EMB_TVTUNER = 0x070C,
	USB_AUDIO_TERMINAL_EMB_SATELLITERECEIVER = 0x070D,
	USB_AUDIO_TERMINAL_EMB_CABLETUNER = 0x070E,
	USB_AUDIO_TERMINAL_EMB_DSS = 0x070F,
	USB_AUDIO_TERMINAL_EMB_RADIORECEIVER = 0x0710,
	USB_AUDIO_TERMINAL_EMB_RADIOTRANSMITTER = 0x0711,
	USB_AUDIO_TERMINAL_EMB_MTRECORDER = 0x0712,
	USB_AUDIO_TERMINAL_EMB_SYNTHESIZER = 0x0713
} USB_AUDIO_TERMINAL_TYPE;

#endif