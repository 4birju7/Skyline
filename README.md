## Skyline
<br/>
Assist an architect in drawing the skyline of a city given the locations of the buildings in the city. All buildings are rectangular in shape and they share a common bottom (a flat surface). A building is specified by an ordered triplet (Li, Ri, Hi) where Li and Ri are the left and right (x) coordinates, respectively, of the building i (0 < Li < Ri) and Hi is the height of the building.<br/>
For example, the input can be as follows.<br/>
(33, 41, 5)<br/>
(4, 9, 21)<br/>
(30, 36, 9)<br/>
(14, 18, 11)<br/>
(2, 12, 14)<br/>
(34, 43, 19)<br/>
(23, 25, 8)<br/>
(14, 21, 16)<br/>
(32, 37, 12)<br/>
(7, 16, 7)<br/>
(24, 27, 10).<br/>
To understand the problem properly please visit https://www.ideserve.co.in/learn/the-skyline-problem#:~:text=A%20city's%20skyline%20is%20the,when%20viewed%20from%20a%20distance.&text=For%20example%2C%20if%20input%20is,%2C%5B15%2C0%5D%5D. or https://www.youtube.com/watch?v=Cv0ft2dFz80.<br/><br/>
**Solution1: BRUTE FORCE APPROACH :** <br/>
First we will sort the given building coordinates with respect to left x (Li) of building, so that we can start our approach. After sorting we will use and array named auxH with each element set to 0 initially.<br/>
We'll iterate every building from start to end which are sorted in the array, and while iterating we will update auxH array's every element i.e, each coordinate, with larger of current element of auxH and the current value of building's height.<br/>
The sorting part can be done using Bubble sort or Merge Sort, depending on which our time complexity changes. If we consider n be the number of inputs and all the x coordinates are below some values m than we need to run skyline solution n x m, m cannot be comparible to n as n tends to infinity so this function becomes **Ѳ(n)**. But considering the sorting part : <br/>
**T(n) = Ѳ(n) + time for sorting.<br/>
T(n) = Ѳ(n) + [Ѳ(nlogn) or Ѳ(n^2)] //depending on type of sort you use.<br/>
If bubble sort is used than, T(n) = Ѳ(n) + Ѳ(n^(2)) = Ѳ(n^(2))<br/>
and if merge sort than, T(n) = Ѳ(n) + Ѳ(nlogn) = Ѳ(nlogn)<br/>
If already sorted array of buildings were provided than time complexity would be T(n) = Ѳ(n).<br/><br/>
Solution2: Divide and Conquer : ** <br/>
This approach is very smaller to "MERGE SORT". First we will divide the building coordinate array into individual building, which is the divide part, and while merging we will take care of the intersection part which is conquer and combine at the same time. The one with the lesser x (Li) coordinate will be beginning and than we will check the overlapping area. If overlapping area is found than we will update the points or else we will just add points of each building directly in to array containing skyline points. In this process we will get many wrong point because we will not conside entire skyline at the time when smaller buildings are merged, we call this point redundant points or wrong points, as we want minimum points. Please look at the cpp file uploaded to understand this solution.<br/>
The merge part will only follow till m, which is the rightmost point.<br/>
Therefore, T(n) = 2T(n/2) + Ѳ(1)<br/>
This is same as that of binary search and evaluates to Ѳ(logn)<br/>
If m and n are comparable than T(n) = T(n) = 2T(n/2) + Ѳ(n)<br/>
Therefore T(n) = Ѳ(logn) +  Ѳ(n) = Ѳ(n) <br/>
