from time import time
import matplotlib.pyplot as plt
import numpy as np
import random
import time


#heap sort
def maxHeapify(arr, n, i):
    largest = i
    l = 2 * i + 1
    r = 2 * i + 2
  
    if l < n and arr[i] < arr[l]:
        largest = l
  
    if r < n and arr[largest] < arr[r]:
        largest = r
  
    if largest != i:
        arr[i],arr[largest] = arr[largest],arr[i]
        maxHeapify(arr, n, largest)
  
def heapSort(arr):
    n = len(arr)

    for i in range(n // 2 - 1, -1, -1):
        maxHeapify(arr, n, i)
  
    for i in range(n-1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]
        maxHeapify(arr, i, 0)





#merge sort
def merge(left, right):
    result = []

    while len(left) and len(right):
        if (left[0] < right[0]):
            result.append(left.pop(0))
        else:
            result.append(right.pop(0))

    result = result+left if len(left) else result+right
    return result

def mergeSort(array):
    if len(array) < 2:
        return array

    mid = len(array)//2
    leftArray = array[:mid]
    rightArray = array[mid:]

    return merge(mergeSort(leftArray),mergeSort(rightArray))




#quick sort
def quicksort(data, left, right): 
    if left >= right :            
        return

    i = left                      
    j = right                     
    pivot = data[left]                 

    while i != j:                  
        while data[j] > pivot and i < j:   
            j -= 1
        while data[i] <= pivot and i < j:  
            i += 1
        if i < j:                        
            data[i], data[j] = data[j], data[i] 

    
    data[left] = data[i] 
    data[i] = pivot

    quicksort(data, left, i-1)  
    quicksort(data, i+1, right)  

#quicksort(data, 0, len(data)-1)





#shell sort


def ShellSort(data):
    n = len(data)
    gap = n // 2 
    while gap > 0: 
        for i in range(gap,n): 
            temp = data[i] 
            j = i 
            while  j >= gap and data[j-gap] > temp: 
                data[j] = data[j-gap] 
                j = j - gap 
            data[j] = temp 
        gap = gap // 2
    return data



#main


data = [[],[],[],[],[],[],[],[],[],[],[],[]]
data_num_list = [10000,50000,100000,200000,300000,400000,500000,600000,700000,800000,900000,1000000]
heap_sort_perform_time = []
merge_sort_perform_time = []
quick_sort_perform_time = []
shell_sort_perform_time = []
perform_time_lists = [heap_sort_perform_time, merge_sort_perform_time, quick_sort_perform_time, shell_sort_perform_time]


for i in range(0,len(data_num_list)):
   for j in range(0,data_num_list[i]):
     data[i].append(random.randint(1,10000))



#heap sort
for i in range(0,len(data_num_list)):
    start = time.time()
    heapSort(data[i])
    end = time.time()
    heap_sort_perform_time.append(end-start)
    

print(heap_sort_perform_time)




#merge sort
for i in range(0,len(data_num_list)):
    start = time.time()
    mergeSort(data[i])
    end = time.time()
    merge_sort_perform_time.append(end-start)
    

print(merge_sort_perform_time)



#quicksort
for i in range(0,len(data_num_list)):
    start = time.time()
    quicksort(data[i], 0, len(data[i])-1)
    end = time.time()
    quick_sort_perform_time.append(end-start)
    

print(quick_sort_perform_time)


#shell sort
for i in range(0,len(data_num_list)):
    start = time.time()
    ShellSort(data[i])
    end = time.time()
    shell_sort_perform_time.append(end-start)
    

print(shell_sort_perform_time)    
    



for i in range(0,len(perform_time_lists)):
  plt.plot(data_num_list, perform_time_lists[i],'r.')
  plt.grid(True)
  plt.show()
  
  

#plt.plot(data_num_list, perform_time_lists[2],'r.')
#plt.grid(True)
#plt.show()

