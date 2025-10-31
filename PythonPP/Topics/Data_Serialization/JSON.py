import json
data = {
        "name": "Jane Doe",
        "age": 28,
        "is_employed": True,
        "skills": ["Python", "JSON", "Data Analysis"]
}
j_string = json.dumps(data, indent=4)
print(j_string)
with open('output.json', 'w') as f:
    json.dump(data, f, indent=4)
