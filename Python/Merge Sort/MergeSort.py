def mergeSort(array):
    print(f"Splitting the array {array}")
    if len(array)>1:
        mid = len(array)//2
        lefthalf = array[:mid]
        righthalf = array[mid:]

        mergeSort(lefthalf)
        mergeSort(righthalf)
        i=j=k=0       
        while i < len(lefthalf) and j < len(righthalf):
            if lefthalf[i] < righthalf[j]:
                array[k]=lefthalf[i]
                i=i+1
            else:
                array[k]=righthalf[j]
                j=j+1
            k=k+1

        while i < len(lefthalf):
            array[k]=lefthalf[i]
            i=i+1
            k=k+1

        while j < len(righthalf):
            array[k]=righthalf[j]
            j=j+1
            k=k+1
    # print(f"List Sorting => {array}")

arr = [145,426,4333,2217,7,1,4321315,2312423434321,-5525,-5,-125688]
mergeSort(arr)
for i in range(len(arr)): 
	print (f"{arr[i]}", end=" "), 
