"""
Put these files in the same folder as `houses.csv` and `dataset_truth.csv`.

Usage:
    $ python evaluate.py
"""
from __future__ import print_function
import csv
import sys
import os.path


def load_csv(filename):
    """Load a CSV file and return a list with datas (corresponding to truths or
    predictions).
    """
    datas = list()
    with open(filename, 'r') as opened_csv:
        read_csv = csv.reader(opened_csv, delimiter=',')
        for line in read_csv:
            datas.append(line[1])
    # Clean the header cell
    datas.remove("Hogwarts House")
    return datas

if __name__ == '__main__':
    if os.path.isfile("dataset_truth.csv"):
        truths = load_csv("dataset_truth.csv")
    else:
        sys.exit("Error: missing dataset_truth.csv in the current directory.")
    if os.path.isfile("houses.csv"):
        predictions = load_csv("houses.csv")
    else:
        sys.exit("Error: missing houses.csv in the current directory.")
    # Here we are comparing each values and counting each time
    count = 0
    if len(truths) == len(predictions):
        for i in range(len(truths)):
            if truths[i] == predictions[i]:
                count += 1
    score = float(count) / len(truths)
    print("Your score on test set: %.3f" % score)
    if score >= .98:
        print("Good job! Mc Gonagall congratulates you.")
    else:
        print("Too bad, Mc Gonagall flunked you.")

