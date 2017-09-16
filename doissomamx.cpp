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

#include "doissomamx.h"
#include <time.h>
int doisSomamXComTimer(int **in, int sz, int x, unsigned long long *tempo_de_cpu, unsigned long long *tempo_de_usuario, void sort(int**,int), int search(int**,int,int)){
    int retorno = 0;
    time_t inicio_real = time(NULL);
    clock_t inicio_cpu = clock();
    retorno = doisSomamX(in,sz,x,sort,search);
    *tempo_de_cpu = (clock() - inicio_cpu)/CLOCKS_PER_SEC;
    *tempo_de_usuario = time(NULL) - inicio_real - *tempo_de_cpu;
    return retorno;
}
int doisSomamX(int **in, int sz, int x, void sort(int**,int), int search(int**,int,int)){
    if(sort != NULL)    sort(in,sz);
    return search(in,sz,x);
}
