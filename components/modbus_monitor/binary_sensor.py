import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import binary_sensor
from esphome.const import CONF_ID
from . import ModbusMonitor, modbus_monitor_ns

DEPENDENCIES = ["modbus_monitor"]

ModbusBinarySensor = modbus_monitor_ns.class_('ModbusBinarySensor', binary_sensor.BinarySensor)
CONF_MODBUS_MONITOR_ID = 'modbus_monitor_id'
CONF_DEVICE_ADDRESS = 'device_address'
CONF_REGISTER_ADDRESS = 'register_address'
CONF_BIT = 'bit'

CONFIG_SCHEMA = binary_sensor.binary_sensor_schema(ModbusBinarySensor).extend({
    cv.GenerateID(CONF_MODBUS_MONITOR_ID): cv.use_id(ModbusMonitor),
    cv.Required(CONF_DEVICE_ADDRESS): int,
    cv.Required(CONF_REGISTER_ADDRESS): int,
    cv.Optional(CONF_BIT, default=-1): cv.int_range(-1, 15)
})

async def to_code(config):
    modbus_monitor = await cg.get_variable(config[CONF_MODBUS_MONITOR_ID])
    modbus_binary_sensor = modbus_monitor.create_binary_sensor(config[CONF_DEVICE_ADDRESS], config[CONF_REGISTER_ADDRESS], config[CONF_BIT])
    await binary_sensor.register_binary_sensor(modbus_binary_sensor, config)
