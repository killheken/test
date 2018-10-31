import nltk
from nltk import trigrams
import re
from collections import Counter
from nltk import ngrams
import csv

f = open('dataset.txt', 'r')
testset = open('Submission File.csv' , 'r')

allbi = []

ori = f.read()
loweri = ori.lower()
text = re.split(r'\W+', loweri)
bi = ngrams(text, 2)

for x in list(bi):
    allbi.append(x)

c3 = Counter(allbi)

csvwriter = csv.writer(open('105502036.csv', 'w', encoding="UTF-8"))
csvwriter.writerow(["ID", "Values"])
rows = csv.reader(testset)
for i in rows:
    if len(i[1].split()) >1:
        for x in c3.most_common():
            if x[0][0] == i[1].split()[2]:
                csvwriter.writerow([i[0], x[0][1]])
                print([i[0], x[0][1]])
                break
