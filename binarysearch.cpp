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

#include "binarysearch.h"

int binarySearch(int **in, int sz, int x){
   int low = 0;
   int high = sz - 1;
   int mid;
   while (low <= high) {
       mid = low + ((high - low) / 2);
       if ((*in)[mid] > x)
           high = mid - 1;
       else if ((*in)[mid] < x)
           low = mid + 1;
       else{
           return mid; // found
           
   }
   return -1; // not found
}
