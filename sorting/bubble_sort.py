from sorting_test import TestSort
from math import inf

def bubble_sort(nums: list[int]) -> list[int]:
    for i in range(0, len(nums)):
        for j in range(0, len(nums) - 1):
            if (nums[j] > nums[j + 1]):
                temp = nums[j]
                nums[j] = nums[j+1]
                nums[j+1] = temp
    return nums

def selection_sort(nums: list[int]) -> list[int]:
    for i in range(0, len(nums)):
        curr_min = nums[i]
        curr_min_idx = 0
        for j in range(i, len(nums)):
            if (nums[j] <= curr_min): 
                curr_min = nums[j]
                curr_min_idx = j
        temp = nums[i]
        nums[i] = nums[curr_min_idx]
        nums[curr_min_idx] = temp 
    return nums


sorters = [bubble_sort, selection_sort]
test_sort = TestSort()
for sorter in sorters:
    print(f'Testing {sorter.__name__}')
    test_sort.test_increasing_order(sorter)
    test_sort.test_simple(sorter)
    test_sort.test_decreasing_order(sorter)
    test_sort.test_negatives(sorter)
    test_sort.test_duplicates(sorter)
    test_sort.test_zeros(sorter)


