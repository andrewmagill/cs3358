def selection_sort(sort_list):
    """Selection Sort is similar to Bubble Sort, but with a small
    improvement.  Like Bubble Sort, Selection Sort makes multiple
    passes over a list, the largest element visited is in place after pass,
    reducing the number of unsorted elements by 1 each time.  Unlike
    Bubble Sort, the Selection Sort algorithm only makes one swap per pass
    (selects the largest element, swaps with the last unsorted position).

    Time Analysis:
        best: O(n^2)
        worst: O(n^2)
        avg: O(n^2)

    Space Analysis:
        O(1)

    Method:
        selection
    """
    for fill_position in range(len(sort_list)-1,0,-1):
        position_of_max = 0
        for location in range(1, fill_position):
            if sort_list[location] > sort_list[position_of_max]:
                position_of_max = location

        temp = sort_list[fill_position]
        sort_list[fill_position] = sort_list[position_of_max]
        sort_list[position_of_max] = temp
