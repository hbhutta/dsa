from sorting_test import TestSort

def bubble_sort(nums: list[int]) -> list[int]:
    for i in range(0, len(nums)):
        for j in range(0, len(nums) - 1):
            if (nums[j] > nums[j + 1]):
                temp = nums[j]
                nums[j] = nums[j+1]
                nums[j+1] = temp
    return nums



test_sort = TestSort()
test_sort.test_increasing_order(bubble_sort)
test_sort.test_decreasing_order(bubble_sort)
test_sort.test_negatives(bubble_sort)
test_sort.test_duplicates(bubble_sort)
test_sort.test_zeros(bubble_sort)


