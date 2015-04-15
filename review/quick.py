def quick_sort(sort_list):
    """quick sort is a divide and conquer, recursive, sort.

    pivot value - any item (other than a previous pivot value),
    could just be the first item each time, used in splitting the list

    split point - position where the pivot value belongs in final
    sorted list

    partition - reorder the list so that items larger than the pivot
    are placed to the left of items greater than the pivot. the pivot is 
    placed in final sorted position, at the split point.

        process - locate two markers, i and j, at the beginning and end
        of the remaining items in the list (excluding the pivot)

        increment i until we find an item larger than the pivot.
        decrement j until we find an item smaller than the pivot.
        now we have two items that are out of place with repect to
        the pivot, swap.

        stop when i and j cross (so that the position of j is less than
        the position of i).  the position of j is the split point.  the
        value at the split point is swapped with the value the pivot (which
        was the first item in the list in our example).

    time analysis:
        best: O(n log n)
        worst: O(n^2)
        avg: O(n log n)

    space analysis:
        avg: O(log n)
        worst: O(n)

    method:
        partitioning"""
    quick_sort_helper(sort_list, 0, len(sort_list)-1)

def quick_sort_helper(sort_list, first, last):
    if first < last:
        split_point = partition(sort_list, first, last)

        quick_sort_helper(sort_list, first, split_point-1)
        quick_sort_helper(sort_list, split_point+1, last)

def partition(sort_list, first, last):
    pivot_value = sort_list[first]

    i = first+1
    j = last

    done = False
    while not done:

        while i <= j and sort_list[i] <= pivot_value:
            i = i+1

        while sort_list[j] >= pivot_value and j >= i:		
            j = j-1

        if j < i:
            done = True
        else:
            temp = sort_list[i]
            sort_list[i] = sort_list[j]
            sort_list[j] = temp

    # swap pivot with value at split point
    temp = sort_list[first]
    sort_list[first] = sort_list[j]
    sort_list[j] = temp

    return j

sort_list = [94,3,86,39,78,0,2]
print sort_list
quick_sort(sort_list)
print sort_list
