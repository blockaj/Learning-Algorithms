#We want to start at the second item in our array
#and then compare it to the first
def insertionSort(a):
  for j in range(1, len(a)):
    key = a[j]

    #Get the previous item
    i = j - 1

    #While the previous item is greater than the current one
    #flip the items positions in the array
    while i > -1 and a[i] > key:
      a[i + 1] = a[i]
      i = i - 1
    #If they're in the right order move along
    a[i + 1] = key
  return input

input = [3, 5, 6, 2, 8, 9]
print insertionSort(input)
