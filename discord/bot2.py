import discord
import json
from flask import Flask, jsonify

app = Flask(__name__)

intents = discord.Intents.default()
intents.members = True

client = discord.Client(intents=intents)

@client.event
async def on_rate_limit(rate_limit_info):
    print(f'Rate limit hit. Retry after {rate_limit_info.retry_after}s. Route: {rate_limit_info.route}')
async def on_message(message):
    if message.channel.id == 1093268082430050354: # ID van het Discord-kanaal voor motortemperatuur
        if "Temperatuur motor" in message.content:
            temperature = message.content.split(":")[1].strip().split(" ")[0] # haal de temperatuurwaarde uit het bericht
            with open("temperatures.json", "r+") as f:
                data = json.load(f)
                data["temperature motor"] = temperature
                f.seek(0)
                json.dump(data, f) # sla de temperatuurwaarde op in een JSON-bestand
                f.truncate()
    if message.channel.id == 1093268094933282846: # ID van het Discord-kanaal voor batterijtemperatuur
        if "Temperatuur batterij" in message.content:
            temperature = message.content.split(":")[1].strip().split(" ")[0] # haal de temperatuurwaarde uit het bericht
            with open("temperatures.json", "r+") as f:
                data = json.load(f)
                data["temperature batterij"] = temperature
                f.seek(0)
                json.dump(data, f) # sla de temperatuurwaarde op in een JSON-bestand
                f.truncate()
    if message.channel.id == 1093268111865688195: # ID van het Discord-kanaal voor motortemperatuur
        if "Temperatuur sensor 3" in message.content:
            temperature = message.content.split(":")[1].strip().split(" ")[0] # haal de temperatuurwaarde uit het bericht
            with open("temperatures.json", "r+") as f:
                data = json.load(f)
                data["Temperatuur sensor 3"] = temperature
                f.seek(0)
                json.dump(data, f) # sla de temperatuurwaarde op in een JSON-bestand
                f.truncate()
    if message.channel.id == 1093268134468780094: # ID van het Discord-kanaal voor batterijtemperatuur
        if "Temperatuur sensor 4" in message.content:
            temperature = message.content.split(":")[1].strip().split(" ")[0] # haal de temperatuurwaarde uit het bericht
            with open("temperatures.json", "r+") as f:
                data = json.load(f)
                data["Temperatuur sensor 4"] = temperature
                f.seek(0)
                json.dump(data, f) # sla de temperatuurwaarde op in een JSON-bestand
                f.truncate()

@app.route('/temperature')
def get_temperature():
    with open("temperatures.json", "r") as f:
        data = json.load(f)
        return jsonify(data) # geeft de temperatuurwaarden als JSON-respons terug

if __name__ == '__main__':
    client.run('-----') # start de Discord bot
