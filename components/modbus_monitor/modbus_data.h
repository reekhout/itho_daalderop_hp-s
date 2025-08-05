#ifndef MODBUS_DATA_H_
#define MODBUS_DATA_H_

#include "esphome/core/datatypes.h"

namespace esphome {
namespace modbus_monitor {

typedef struct ModbusData {
  uint16_t address { 0 };
  uint16_t value { 0 };
} ModbusData;

} // namespace esphome
} // namespace modbus_monitor

#endif // MODBUS_DATA_H_
