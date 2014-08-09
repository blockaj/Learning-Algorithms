def insertionSort(a):
  for j in range(1, len(a)):
    key = a[j]
    i = j - 1
    while i > -1 and a[i] > key:
      a[i + 1] = a[i]
      i = i - 1
    a[i + 1] = key
  return input

input = [3, 5, 6, 2, 8, 9]
print insertionSort(input)
