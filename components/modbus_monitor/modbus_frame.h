#ifndef MODBUS_FRAME_H_
#define MODBUS_FRAME_H_

#include "esphome/core/datatypes.h"
#include "esphome/core/log.h"

namespace esphome {
namespace modbus_monitor {

class ModbusFrame {
 public:
  ModbusFrame(uint8_t address, uint8_t function, uint8_t* data, uint8_t data_length);
  ~ModbusFrame();

 private:
  ModbusFrame(const ModbusFrame&);

 public:
  uint8_t get_address() const { return this->address_; }
  uint8_t get_function() const { return this->function_; }
  uint8_t* get_data() const { return this->data_; }
  uint8_t get_data_length() const { return this->data_length_; }

 protected:
  uint8_t address_;
  uint8_t function_;
  uint8_t* data_;
  uint8_t data_length_;
};

} // namespace modbus_monitor
} // namespace esphome

#endif // MODBUS_FRAME_H_
