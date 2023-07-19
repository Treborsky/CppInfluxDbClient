#!/usr/bin/python3

import influxdb_client
from influxdb_client import InfluxDBClient, Point, WritePrecision
from influxdb_client.client.write_api import SYNCHRONOUS


token = "vxEubvMV7U6AJE_S7wZ4BZgIuSTBgVUK8wvy-a6V87Jx4USdLTmA6Mx3lfq9SiF8EqOouCQlgIivTD-_4xEK0w=="
bucket = "cpp-testing"
org = "robert.koziarski@solarboat.agh.edu.pl"
url = "localhost:12345"

write_client = influxdb_client.InfluxDBClient(url=url, token=token, org=org)

write_api = write_client.write_api(write_options=SYNCHRONOUS)

point = Point("airSensors").tag("sensor_id", "TLM0201").field("temperature", "73.970381")
write_api.write(bucket=bucket, org=org, record=point)

print("Complete. Return to the InfluxDB UI.")