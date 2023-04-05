from flask import Flask, jsonify
import json

app = Flask(__name__)

# JSON-bestand waarin we de temperatuurwaarden opslaan
JSON_FILE = 'temperatures.json'

# Functie die de temperatuurwaarden ophaalt uit het JSON-bestand
def get_temperatures():
    with open(JSON_FILE, 'r') as f:
        return json.load(f)

# API endpoint voor het verkrijgen van de temperatuurgegevens
@app.route('/')
def get_temperatures_api():
    return jsonify(get_temperatures())

# Start de Flask applicatie
if __name__ == '__main__':
    app.run(host='192.168.0.226', debug=True)