#ifndef __COMMUNICATION_CONSTANTS__
#define __COMMUNICATION_CONSTANTS__

enum communication_source_list {
  USB_SOURCE = 0,
  RS_485_SOURCE,
  TCP_IP_SOURCE,
  NULL_SOURCE
};

enum usb_error_list {
  USB_NO_ERROR = 0,
  USB_READ_ERROR,
  USB_WRITE_ERROR
};

enum rs_485_error_list {
  RS_485_NO_ERROR = 0,
  RS_485_READ_ERROR,
  RS_485_WRITE_ERROR
};

#endif

