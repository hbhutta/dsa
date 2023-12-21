import unittest

class TestSort(unittest.TestCase):
    def test_simple(self, sorter):
        self.assertEqual([1,2,3,4], sorter([1,3,2,4]))


    def test_increasing_order(self, sorter):
        self.assertEqual([1,2,3,4,5,6,7,8,9], sorter([1,2,3,4,5,6,7,8,9]))
        print('Test passed!')
        
        # print('Sorting increasing order array failed..')

    def test_decreasing_order(self, sorter):
        # try: 
        self.assertEqual([1,2,3,4,5,6,7,8,9], sorter([9,8,7,6,5,4,3,2,1]))
        print('Test passed!')
        # except:
            # print('Sorting decreasing order array failed..')

    def test_negatives(self, sorter):
        try: 
            self.assertEqual([-9,-7,-5,-3,-1,2,4,6,8], sorter([-9,8,-7,6,-5,4,-3,2,-1]))
            print('Test passed!')
        except:
            print('Sorting array with negatives failed')

    def test_zeros(self, sorter):
        try: 
            self.assertEqual([-6,-4,-2,0,1,3,5,7], sorter([0,1,-2,3,-4,5,-6,7]))
            print('Test passed!')
        except:
            print('Sorting array with zeroes failed..')

    def test_duplicates(self, sorter):
        try:
            self.assertEqual([-11,1,1,1,2,4,5,13,61], sorter([1,1,-11,1,13,4,5,61,2]))
            print('Test passed!')
        except:
            print('Sorting array with duplicates failed..')