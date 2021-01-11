# Report
 
 
## __Introduction__
 
I have created a whole program to allow a user to sort a range of random data with a selection of sorting algorithms for the user to choose. The user has a choice of using Selection sort, Insertion sort and Radix sort. After the data is sorted it will display the time it took to sort and it will output the sorted data to a text file. I chose Selection sort as it is a standard, common algorithm, Insertion sort as I find it quite interesting when put up vs selection sort and Radix sort as it is one of the quicker algorithms.
 
 
## __Datasets__
 
Within my program I utilized the datasets - Ascending order, Descending order and random order. Previously I was attempting to implement partial sort and a dataset to order in odd numbers ascending and then even numbers descending however I failed. I implemented the above three datasets as they are simple, effective in displaying data and are easy for the user to understand. Ascending order gave an interesting insight to Insertion sort as touched on in _Algorithim Performance_.
 
 
## __Algorithm Performance__
 
## 1
As the number of elements increased (1, 10, 100... 5000000) each algorithm's performance got progressively slower. Radix sort was exceptional when handling larger amounts of data past 1000000 with times like 295ms. Selection sort and insertion sort on the other hand weren't as efficient with large amounts of data and were left as DNF as they would take far too long handling data over a million. As expected Insertion sort and Selection sort were head to head however Insertion sort was nearly two times faster after each figure above 100000. Both compared to Radix sort were extremely slow. For example with 100000, Selection sort managed a time of 11150ms, Insertion sort 7162ms and Radix sort with an extraordinary 295ms. All results are displayed in results.md!
 
## 2
Utilizing different datasets allowed for a more interesting approach to how these algorithms sort data under order's that aren't just randomized data. Ascending order caught my eye the most out all datasets due to how Insertion Sort performed. Insertion Sort was extremely quick and efficient. It even succeeded in reaching a million and 5 million with outstanding sorting speeds. It was also faster than Radix sort by a mile. This however was expected as having the data in an ascending order allowed for Insertion Sorts methods of sorting to be much simplified which made it super quicker to iterate through the data. Insertion sort is quadratic at worst but linear at best which makes it a more capable algorithm than radix sort but inferior to Radix sort.
 
Radix Sort managed to stay consistent through each dataset maintaining similar times in each dataset and number of elements. One thing I noticed and took into consideration is how Radix sort needs more memory than other algorithms. Once you start advancing into the gigabyte range Radix sort starts to show its true colours asking for more memory. For example initially I ran into trouble sorting a million elements due to memory but with an alteration it was fixed. Radix sort best case is O(n.log n).
 
Selection sort also performed in consistency as shown in the results. Selection sort portrayed to work effectively with lower inputs regardless of how it was sorted. Selection sort proved to be the slowest among the three algorithms. This is caused due to the fact that it always has quadratic complexity, in the worst case as well as in the best case.
 
## 3
Selection sort remained consistent with its speed time through the datasets. It is ineffective when executed at large inputs and works at an acceptable rate at other half of lower elements. It performed at its best with data sorted at an ascending order and its worst at descending order however the results between each were minimal.
 
Insertion sort was consistent with Random sort and descending sort however it displayed its power at the ascending dataset exposing itself to unbelievable speeds although this was as expected due to how it functions. Insertion sort owned the ascending order of data but lacked by descending order being nearly the same speed of selection sort.
 
Radix sort is one of the more known speedy sorting algorithm's and this was clearly evident. It performed its best with random data and its worst with ascending dataset however like selection sort the results were similar to one another regardless of the dataset.
 
 
## __Negatives__
 
Throughout this project I experienced a lot of issues. The biggest issue of all is at times when I run my prgoram it works perfectly as I intend but other times it just seems to bug and no matter what I try to fix or implement there always seems to be a bug but as of currently for myself it is operating. Another issue is that when I type a letter instead of an int when selecting an algorithm is still functions and does not output an error. I had many issues creating the file_write file but managed to complete it with satisfaction after working on it to find a working method. My algorithms could be improved in complexity is well and it could be done with more time on my hands to learn to implement.
 
 
## __Conclusion and future work__
 
I truly enjoyed piecing this program together however I underestimated how long it wouldve took. If I had more time I would create 2 more DataSets, Parial sort and a dataset to order all odd numbers in descending order and then even numbers in ascending order. I would also work on implementing more compliacted, quicker algorithms such as quick sort and merge sort as I was having trouble implementing them earlier and couldnt find a fix to get them fully operating.

