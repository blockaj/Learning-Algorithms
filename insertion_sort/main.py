# The purpose of this small script is to understand the way
# basic algorithms (like insertion sort) slow down over time. 
# Insertion sort grows in quadratic time and can be expressed 
# by cn^2

from random import randint

#We want to start at the second item in our array
#and then compare it to the first
def insertionSort(a):
  for j in range(1, len(a)):
    key = a[j]
    i = j - 1  #Get the previous item

    #While the previous item is greater than the current one
    #flip the items positions in the array
    while i > -1 and a[i] > key:
      a[i + 1] = a[i]
      i = i - 1

    a[i + 1] = key  #If they're in the right order move along
    
  return input

arrayLength = raw_input('Set an array length please: ')
input = []
for x in range(0, int(arrayLength)):
  inputItem = randint(0, int(arrayLength))
  print inputItem
  input.insert(x, inputItem)
print insertionSort(input)
