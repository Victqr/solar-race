import serial
import discord
import asyncio

# Seriële communicatie instellen voor temperatuurcommunicatie
ser_temp = serial.Serial('COM23', 19200)


intents = discord.Intents.default()
intents.members = True

client = discord.Client(intents=intents)

CHANNEL_BATTERY_TEMP = 1093268094933282846 # ID van het Discord-kanaal voor batterijtemperatuur
CHANNEL_MOTOR_TEMP = 1093268082430050354 # ID van het Discord-kanaal voor motortemperatuur
CHANNEL_SENSOR_3_TEMP = 1093268111865688195 # ID van het Discord-kanaal voor temperatuur van sensor 3
CHANNEL_SENSOR_4_TEMP = 1093268134468780094 # ID van het Discord-kanaal voor temperatuur van sensor 4

async def send_temperatures():
    while True:
        # Lees temperatuurvariabelen
        ser_temp.write(b'1')
        temperatuurbatterij = ser_temp.readline().decode().strip()
        ser_temp.write(b'2')
        temperatuurmotor = ser_temp.readline().decode().strip()
        ser_temp.write(b'3')
        temperatuursensor3 = ser_temp.readline().decode().strip()
        ser_temp.write(b'4')
        lichtwaarde = ser_temp.readline().decode().strip()

        # Verstuur temperatuurwaarden naar Discord
        await client.get_channel(CHANNEL_BATTERY_TEMP).send(f"Temperatuur batterij: {temperatuurbatterij}")
        await client.get_channel(CHANNEL_MOTOR_TEMP).send(f"Temperatuur motor: {temperatuurmotor}")
        await client.get_channel(CHANNEL_SENSOR_3_TEMP).send(f"Temperatuur sensor 3: {temperatuursensor3}")
        await client.get_channel(CHANNEL_SENSOR_4_TEMP).send(f"Lichtwaarde: {lichtwaarde}")

        # Wacht 40 seconden voordat de volgende lees- en verzendcyclus begint
        await asyncio.sleep(40)

@client.event
async def on_ready():
    print(f"Logged in as {client.user} (ID: {client.user.id})")
    await send_temperatures()

client.run('-----')