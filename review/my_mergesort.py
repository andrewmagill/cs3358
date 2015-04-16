def mergesort(sort_list):

        if len(sort_list) <= 1:
            return sort_list

        mid = len(sort_list)//2
        #print sort_list
        left = mergesort(sort_list[:mid])
        right = mergesort(sort_list[mid:])
        merge(left, right)
        return sort_list

def merge(left, right):
    i=0
    j=0
    k=0
    merged = []
    done = False
    while not done:
        if i > len(left) and j > len(right):
            done = True

        if i < len(left) and left[i] < right[j]:
            merged.append(left[i])
            i = i + 1
            k = k + 1
        elif j < len(right):
            merged.append(right[j])
            j = j + 1
            k = k + 1

    return merged

mylist = [45,9,35,23,7,27,71,98,34,12]
mergesort(mylist)
