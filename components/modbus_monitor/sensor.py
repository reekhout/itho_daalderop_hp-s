import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import sensor
from esphome.const import CONF_ID
from . import ModbusMonitor, modbus_monitor_ns

DEPENDENCIES = ["modbus_monitor"]

ModbusRegisterSensor = modbus_monitor_ns.class_('ModbusRegisterSensor', sensor.Sensor)
CONF_MODBUS_MONITOR_ID = 'modbus_monitor_id'
CONF_DEVICE_ADDRESS = 'device_address'
CONF_REGISTER_ADDRESS = 'register_address'

CONFIG_SCHEMA = sensor.sensor_schema(ModbusRegisterSensor).extend({
    cv.GenerateID(CONF_MODBUS_MONITOR_ID): cv.use_id(ModbusMonitor),
    cv.Required(CONF_DEVICE_ADDRESS): int,
    cv.Required(CONF_REGISTER_ADDRESS): int
})

async def to_code(config):
    modbus_monitor = await cg.get_variable(config[CONF_MODBUS_MONITOR_ID])
    modbus_register_sensor = modbus_monitor.create_sensor(config[CONF_DEVICE_ADDRESS], config[CONF_REGISTER_ADDRESS])
    await sensor.register_sensor(modbus_register_sensor, config)
