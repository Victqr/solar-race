from flask import Flask, jsonify
import json

app = Flask(__name__)

@app.route('/')
def get_temperature():
    with open('data.json', 'r') as f:
        data = json.load(f)
    return jsonify(data)

if __name__ == '__main__':
    app.run(host='192.168.0.226', debug=True)