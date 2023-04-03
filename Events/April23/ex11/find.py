# Import the requests module
try:
	import requests
except ImportError:
	print("This script needs Requests module to be installed!")
	exit(1)

# Request user input
id = input("Enter the name of a Pokemon: ")
if not len(id):
	print("No pokemon name of id provided!")
	exit(1)

# Retrieve the data from PokeAPI
url = "https://pokeapi.co/api/v2/pokemon/" + str(id).lower()
res = requests.get(url)
if not res.ok:
	print("Failed to retrieve information about this pokemon!")
	exit(1)

# Print out the data if valid
json = res.json()
print(f"Name: {json['name'].title()}\nAbilities:")
for i in json['abilities']:
	print(f"- {i['ability']['name'].capitalize()}")
