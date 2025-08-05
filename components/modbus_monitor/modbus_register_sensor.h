#ifndef MODBUS_REGISTER_SENSOR_H_
#define MODBUS_REGISTER_SENSOR_H_

#include "esphome/components/sensor/sensor.h"
#include "esphome/core/datatypes.h"

namespace esphome {
namespace modbus_monitor {

class IModbusRegisterSensor {
 public:
  virtual ~IModbusRegisterSensor();
  virtual void publish_state(uint16_t state) = 0;
};

class ModbusRegisterSensor : public IModbusRegisterSensor {
 public:
  ModbusRegisterSensor();
  virtual ~ModbusRegisterSensor() override;

  virtual void publish_state(uint16_t state) override;
  sensor::Sensor* get_sensor() const;

 protected:
  sensor::Sensor* sensor_;
};

} //namespace modbus_monitor
} //namespace esphome

#endif // MODBUS_REGISTER_SENSOR_H_
