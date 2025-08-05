import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import uart
from esphome.const import CONF_ID

DEPENDENCIES = ["uart"]

modbus_monitor_ns = cg.esphome_ns.namespace('modbus_monitor')
ModbusMonitor = modbus_monitor_ns.class_('ModbusMonitor', cg.Component, uart.UARTDevice)
CONF_LOG_NOT_CONFIGURED_DATA = 'log_not_configured_data'

CONFIG_SCHEMA = cv.Schema({
  cv.GenerateID(): cv.declare_id(ModbusMonitor),
  cv.Optional(CONF_LOG_NOT_CONFIGURED_DATA, default=False): cv.boolean
}).extend(cv.COMPONENT_SCHEMA).extend(uart.UART_DEVICE_SCHEMA)

async def to_code(config):
  rhs = ModbusMonitor.new(config[CONF_LOG_NOT_CONFIGURED_DATA])
  var = cg.Pvariable(config[CONF_ID], rhs)
  await cg.register_component(var, config)
  await uart.register_uart_device(var, config)
