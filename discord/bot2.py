import discord
import json

intents = discord.Intents.default()
intents.members = True

client = discord.Client(intents=intents)

CHANNEL_BATTERY_TEMP = 1093268094933282846  # ID van het Discord-kanaal voor batterijtemperatuur
CHANNEL_MOTOR_TEMP = 1093268082430050354  # ID van het Discord-kanaal voor motortemperatuur
CHANNEL_SENSOR_3_TEMP = 1093268111865688195  # ID van het Discord-kanaal voor temperatuur van sensor 3
CHANNEL_SENSOR_4_TEMP = 1093268134468780094  # ID van het Discord-kanaal voor temperatuur van sensor 4

data = {}


@client.event
async def on_ready():
    print(f"Logged in as {client.user} (ID: {client.user.id})")


@client.event
async def on_message(message):
    if message.channel.id == CHANNEL_BATTERY_TEMP:
        content_parts = message.content.split(': ')
        if len(content_parts) >= 2:
            data['battery TEMP'] = content_parts[1]
    elif message.channel.id == CHANNEL_MOTOR_TEMP:
        content_parts = message.content.split(': ')
        if len(content_parts) >= 2:
            data['motor TEMP'] = content_parts[1]
    elif message.channel.id == CHANNEL_SENSOR_3_TEMP:
        content_parts = message.content.split(': ')
        if len(content_parts) >= 2:
            data['sensor_3 TEMP'] = content_parts[1]
    elif message.channel.id == CHANNEL_SENSOR_4_TEMP:
        content_parts = message.content.split(': ')
        if len(content_parts) >= 2:
            data['lichtwaarde LUX'] = content_parts[1]
    
    with open('data.json', 'w') as f:
        json.dump(data, f)


client.run('------')
