import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import uart
from esphome.const import CONF_ID

DEPENDENCIES = ["uart"]

modbus_monitor_ns = cg.esphome_ns.namespace("modbus_monitor")
ModbusMonitor = modbus_monitor_ns.class_('ModbusMonitor', cg.Component, uart.UARTDevice)

CONFIG_SCHEMA = cv.Schema({
  cv.GenerateID(): cv.declare_id(ModbusMonitor)
}).extend(cv.COMPONENT_SCHEMA).extend(uart.UART_DEVICE_SCHEMA)

async def to_code(config):
  var = cg.new_Pvariable(config[CONF_ID])
  await cg.register_component(var, config)
  await uart.register_uart_device(var, config)
  
