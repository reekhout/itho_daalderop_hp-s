#include "esphome/components/binary_sensor/binary_sensor.h"
#include "esphome/core/datatypes.h"
#include "esphome/core/log.h"

#include "modbus_binary_sensor.h"

namespace esphome {
namespace modbus_monitor {

static const char *TAG = "ModbusBinarySensor";

IModbusBinarySensor::~IModbusBinarySensor() {
}

ModbusBinarySensor::ModbusBinarySensor() {
  this->sensor_ = new binary_sensor::BinarySensor;
}

ModbusBinarySensor::~ModbusBinarySensor() {
  delete this->sensor_;
}

void ModbusBinarySensor::publish_state(bool state) {
  ESP_LOGV(TAG, "About to publish state: %d", state);
  this->sensor_->publish_state(state);
}

binary_sensor::BinarySensor* ModbusBinarySensor::get_sensor() const {
  return this->sensor_;
}

} //namespace modbus_monitor
} //namespace esphome
