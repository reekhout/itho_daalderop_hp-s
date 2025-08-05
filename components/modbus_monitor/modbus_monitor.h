#ifndef MODBUS_MONITOR_H_
#define MODBUS_MONITOR_H_

#include "esphome/core/component.h"
#include "esphome/components/binary_sensor/binary_sensor.h"
#include "esphome/components/sensor/sensor.h"
#include "esphome/components/uart/uart.h"

#include "modbus_data_publisher.h"
#include "modbus_sniffer.h"

namespace esphome {
namespace modbus_monitor {

class ModbusMonitor : public Component, public uart::UARTDevice {
 public:
  ModbusMonitor(bool log_not_configured_data);

 private:
  ModbusMonitor(const ModbusMonitor&);

 public:
  ~ModbusMonitor();

  void setup() override;
  void loop() override;
  void dump_config() override;
  float get_setup_priority() const override;
  uint32_t get_baud_rate() const { return parent_->get_baud_rate(); }
  sensor::Sensor* create_sensor(uint8_t device_address, uint16_t register_address);
  binary_sensor::BinarySensor* create_binary_sensor(uint8_t device_address, uint16_t register_address, int8_t bit);
  
 protected:
  ModbusSniffer* sniffer_;
  ModbusDataPublisher data_publisher_;
};

} //namespace modbus_monitor
} //namespace esphome

#endif // MODBUS_MONITOR_H_
