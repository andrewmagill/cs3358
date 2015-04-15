def bubble_sort(sort_list):
    """bubble sort makes multiple passes over a list, comparing
    pairs of items, switching if item i > i+1. largest element
    bubbles to end on each pass, reducing number of unsorted elements by 1.
    time analysis:
        best O(n) - already sorted... i don't understand why only O(n)...
        worst O(n^2)
        avg O(n^2)
    space:
        O(1) - temp variable holds item to switch
    method:
        exchange"""
    for num_unsorted in range(len(sort_list) - 1, 0, -1):
        for i in range(num_unsorted):
            if sort_list[i] > sort_list[i+1]:
                temp = sort_list[i]
                sort_list[i] = sort_list[i+1]
                sort_list[i+1] = temp
