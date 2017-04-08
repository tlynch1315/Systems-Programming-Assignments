Homework 08
===========
ACTIVITY ONE
==============
1)  in entry_create() I allocated enough memory for one Entry, which contains a key, value, next, and type.  In entry_delete() I checked if the type of the entry was a string, and if it was, I freed the value.string, then freed the key and then the entry.  If recursive was true, I used a while loop with a helper pointer and went until the current entry was NULL and did the same thing as if it were not recursive.

2) in map_create I allocated enough memory for the size of a Map, then set all of the variables to what they should be, which were load factor, capacity, buckets, and size.  The buckets were an array of Entry's, so I also had to allocate enough space for the size of an Entry * the capacity.  In map_delete I used a counter to iterate over the buckets in the map and used entry_delete to delete the individual entries and then freed the buckets and the map itself.

3) in map_resize I callocated enough memory for the new_capacity items of Entry's. With that memory, I made it the same as the buckets for the current map, then freed the buckets and set them equal to the new entrys and then set the maps capacity equal to the new_capacity. This function is called when you need to add more space to the map and it generates new memory that is a different size than the old memory, sets the values in the new memory to be the same as the old then frees the old and sets the maps new values to the ones in the new memory.

4) map insert checks if the map needs to be resized in order to add another entry, and if it does then it is resized.  then, it chekcs if the key is already in the map and if it is then the value is replaced by the inserted value. if not, then the new value is inserted into the bucket with the appropriate key.
    average time: O(1)
    worst time: O(n)
    space average and worst: O(n)

5) map search works by creating a hash using the key and fnv, then that hash is used to find the correct bucket and then at that bucket, the linkded list is traversed to find the entry with the same key. if there is no match, NULL is returned.
    average time: O(1)
    worst time: O(n)
    space average and worst: O(n)

6) map remove workds similar to map_search in that it searches to see if there is a match and if there isnt false is returned.  If there is a match, the linked list at the appropriate bucket is traversed until the correct key is found and then the entry is removed.  the gap created is fixed using a helper pointer.
    average time: O(1)
    worst time: O(n)
    space average and worst: O(n)

ACTIVITY TWO
==============
1) as the numebr of items increases, the time and space grow but as the load factor increases, space stays constant and time fluctuates. This is not surprising since the number of items increases so the time and space would logically increase.

2) I have not created the treap for data structures yet, so I cannot compare them. I think that maps are more useful than trees though because you can have different types as keys.





