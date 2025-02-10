
people = [
    {"name": "Alice", "number": 25},
    {"name": "Bob", "number": 30},
    {"name": "Charlie", "number": 22}
]

people2 = {
    "Alice": 25,
    "Bob": 30,
    "Charlie": 22
}

name = input("Name: ")

for person in people:
    if (person["name"] == name):
        print(f"Found: {person["number"]}")
        break
else:
    print(f"Not found: {name}")

if name in people2:
    print(f"Found: {people2[name]}")
else:
    print(f"Not found: {name}")
