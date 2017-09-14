/*
 * <one line to give the library's name and an idea of what it does.>
 * Copyright (C) 2017  Victor Guerra Veloso <victorgvbh@gmail.com>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

#include "heapsort.h"

// Rearranja um vetor v[1..m] de modo a
// transformá-lo em heap.

void constroiHeap(int *v, int m){
   int k; 
   for (k = 1; k < m; ++k) {                   
      // v[1..k] é um heap
      int f = k+1;
      while (f > 1 && v[f/2] < v[f]) {  // 5
         int t = v[f/2];
         v[f/2] = v[f];
         v[f] = v[f/2];          // 6
         f /= 2;                        // 7
      }
   }
}

void peneira(int *v, int m){ 
   int p = 1, f = 2, t = v[1];
   while (f <= m) {
      if (f < m && v[f] < v[f+1])  ++f;
      if (t >= v[f]) break;
      v[p] = v[f];
      p = f, f = 2*p;
   }
   v[p] = t;
}

void heapSort(int **in, int sz){
    heapSort_(*v,n);
}
void heapSort_(int *v, int n){
    int m;
    constroiHeap (v, n);
    for (m = n; m >= 2; --m) {
        int t = v[1];
        v[1] = v[m];
        v[m] = t;          // 6
        peneira (v, m-1);
    }
}
