import numpy as np

# np will always choose the strongest type: 
# if a list contains a float, all elements will be cast to np floats
# if there is a string all to numpy strings
# if you put an object np will use python ints and floats (slow, bad)

l = [3.14, 4, 5, 7]
np_l = np.array(l, dtype="int8") # datatype is important
# int wh no specification will use native architecture 
un_l = np.ones((2,3), dtype="int")
filled_l = np.full((2,3), 3)
ranged_l = np.arange(0,20,2)
lin_l = np.linspace(0,1,5)
rand_l = np.random.random((2,2))
normal_l = np.random.normal(0, 1, 5)
randrange_l = np.random.randint(0, 10, 5)
id_l = np.eye(3)
empty_l = np.empty((3, 2))

my_l = np.random.randint(0,10, (3, 5, 3))

print(l, "\n")
print(np_l, "\n")
print(un_l, "\n")
print(filled_l, "\n")
print(ranged_l, "\n")
print(lin_l, "\n")
print(rand_l, "\n")
print(normal_l, "\n")
print(randrange_l, "\n")
print(id_l, "\n")
print(empty_l, "\n")
print(my_l, 
      f'''\narray dims:{my_l.ndim}
    array shape:{my_l.shape}
    array size:{my_l.size}''')

print(my_l[2, -1], "\n")
# this is no copy, but a view, using pointers it returns certain elements in that list
# since we're talking about pointers changing this view will change the list itself
print(my_l[2:5], "\n")
copy_l = my_l[2:5].copy() # this creates a copy

dva_l = np.random.randint(0, 10, (3,3))
subarray = dva_l[:2, 1:3] # taking multidimentional slices

print(f'''took {subarray}
      from {dva_l} \n''')

row_col = dva_l[:,2] # taking a column
print(row_col, "\n")

