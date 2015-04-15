def insertion_sort(sort_list):
    """insertion sort makes multiple passes through the list, comparing
    the first unsorted element to previously sorted elements, shifting those
    previously sorted elements right that are larger than the first unsorted element.
    The unsorted element is the inserted into sorted order.  Make sense?

    Time analysis:
        Best: O(n) - already sorted, or nearly sorted(?)
        Worst: O(n^2) - probably reverse sorted would be the worst
        Avg: O(n^2)

    Space Analysis:
        O(1)

    Method:
        insertion
    """
    for index in range(1,len(sort_list)):

        current_value = sort_list[index]
        position = index

        while position > 0 and sort_list[position-1] > current_value:
            sort_list[position] = sort_list[position-1]
            position = position-1

        sort_list[position] = current_value
