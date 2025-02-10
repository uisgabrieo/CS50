import csv
from collections import Counter

#with open("favorites.csv", "r") as file:
    # reader = file.read()
    # print(reader)
    # file_reader = csv.reader(file)
    # next(file_reader)
    # for row in file_reader:
    #     print(row[1])
# with open("favorites.csv", "r") as file:
#     file_reader = csv.DictReader(file)
#     for row in file_reader:
#         print(row)

with open("favorites.csv", "r") as file:

    file_reader = csv.DictReader(file)
    count = Counter()

    for row in file_reader:
        favorite = row["language"]
        count[favorite] += 1
    # count = {}
    # for row in file_reader:
    #     count[row["language"]] = count.get(row["language"], 0) + 1

    # print(count)

# for favorite in sorted(count, key=count.get, reverse=True):
for favorite, counts in count.most_common():
    print(f"{favorite}: {counts}")
