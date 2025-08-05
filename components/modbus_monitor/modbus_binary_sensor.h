#ifndef MODBUS_BINARY_SENSOR_H_
#define MODBUS_BINARY_SENSOR_H_

#include "esphome/components/binary_sensor/binary_sensor.h"
#include "esphome/core/datatypes.h"

namespace esphome {
namespace modbus_monitor {

class IModbusBinarySensor {
 public:
  virtual ~IModbusBinarySensor();
  virtual void publish_state(bool state) = 0;
};

class ModbusBinarySensor : public IModbusBinarySensor {
 public:
  ModbusBinarySensor();
  virtual ~ModbusBinarySensor() override;

  virtual void publish_state(bool state) override;
  binary_sensor::BinarySensor* get_sensor() const;

 protected:
  binary_sensor::BinarySensor* sensor_;
};

} //namespace modbus_monitor
} //namespace esphome

#endif // MODBUS_BINARY_SENSOR_H_
