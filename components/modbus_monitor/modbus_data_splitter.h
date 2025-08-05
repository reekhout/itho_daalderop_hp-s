#ifndef MODBUS_DATA_SPLITTER_H_
#define MODBUS_DATA_SPLITTER_H_

#include <vector>

#include "modbus_data.h"
#include "modbus_frame.h"
#include "esphome/core/datatypes.h"

namespace esphome {
namespace modbus_monitor {

class ModbusDataSplitter {
 public:
  std::vector<ModbusData*>* split_request_and_response_data(ModbusFrame* request, ModbusFrame* response);

 private:
  bool address_and_function_match(ModbusFrame* request, ModbusFrame* response);
  std::vector<ModbusData*>* handle_function_3(ModbusFrame* request, ModbusFrame* response);
};

} //namespace modbus_monitor
} //namespace esphome

#endif // MODBUS_DATA_SPLITTER_H_
