#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

#include "esphome/core/datatypes.h"

namespace esphome {
namespace modbus_monitor {

class IUartInterface {
 public:
  virtual bool read_byte(uint8_t* data) = 0;
  virtual int available() const = 0;
  virtual uint32_t get_baud_rate() const = 0;
};

} //namespace modbus_monitor
} //namespace esphome

#endif // UART_INTERFACE_H_
