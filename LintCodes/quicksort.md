---
title: quicksort
date: 2016-06-16 19:00:17
categories: algorithm
tags: sorting
---

做到与快速排序相关的一道题,所以来复习一下快速排序。顾名思义,这个算法是很快速的算法。平均复杂度是 O(nlogn),主要还是分而治之的思想。

1. 首先选取一个 pivot,关于如何选取有一些不同的方法,比如选取中间的那个数,或者是随机选一个数。
2. 之后是很关键的一步, partition。对数组里的元素进行划分, pivot 左边的元素要满足都小于 pivot,右边的都要大于等于 pivot。
3. 对 pivot 左边和右边的部分递归地进行排序。

我们重点看一下 partition 这一步,这一步的实现是整个算法的关键所在。我们维护两个指针 i 和 j,分别指向数组的第一个元素以及最后一个元素。 partition 的时候我们把 i 往右边移动,把 j 往左边移动。如果遇到 A[i] >= pivot 以及 A[j] < pivot,这时候就把这两个元素交换即可。具体看如下代码:

```java
int partition(int arr[], int left, int right)
{
      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] >= pivot)
                  j--;
            if (i <= j) {
                  //swap arr[i] and arr[j]
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      }
      return i;
}

void quickSort(int arr[], int left, int right) {
      int index = partition(arr, left, right); // left other < arr[index] <= right other
      if (left < index - 1)
            quickSort(arr, left, index - 1); // recursively sort left part
      if (index < right)
            quickSort(arr, index, right); // recursively sort right part
}
```

Knuth 的高徒 Robert Sedgewick 还改进了 quicksort,这里就不讨论了,有兴趣的同学可以去看一下。
