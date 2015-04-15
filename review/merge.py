def merge_sort(sort_list):
    """merge sort is a divide and conquer, recursive, sort.

    base case: list already sorted if length 0 or 1

    smaller caller: split list in half

    at this point the stack of recursive calls looks like a tree,
    with single item lists resembling leaves. as the call stack collapses,
    the algorithm merge lists together.

    the merge works like this: compare first item in left list to first item
    in right list, if left item is smaller than the right item, insert the
    left item into the first item of our new list.  then compare the next item
    in our left list to the first item in our right list, and so on, until
    all items from both lists are merged into our new list.

    time analysis:
        worst: O(n log n)
        best: O(n log n)
        avg: O(n log n)

    space analysis:
        O(n) - worst case

    method:
        merging
    """
    if len(sort_list) > 1:
        mid = len(sort_list) // 2
        left_half = sort_list[:mid]
        right_half = sort_list[mid:]

        merge_sort(left_half)
        merge_sort(right_half)

        i=0 # used to index left list
        j=0 # used to index right list
        k=0 # used to index sorted list

        while i < len(left_half) and j < len(right_half):
            if left_half[i] < right_half[j]:
                sort_list[k] = left_half[i]
                i = i+1
            else:
                sort_list[k] = right_half[j]
                j = j+1
            k = k+1

        while i < len(left_half):
            # in this case the right list is already all merged
            # into our sorted list, so we just need to stick in
            # items from the left list
            sort_list[k] = left_half[i]
            i = i+1
            k = k+1

        while j < len(right_half):
            # in this case the left list is already all merged
            # into our sorted list, so we just need to stick in
            # items from the right list
            sort_list[k] = right_half[j]
            j = j+1
            k = k+1
