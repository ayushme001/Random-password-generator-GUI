/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: AT
 *
 * Created on 3 February, 2018, 3:04 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    int i = 0,n = 0;
    char c;
    char a[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789/_.-+=<>?";
        srand(time(NULL));
        printf("enter password length - ");
        scanf("%d",&n);
        
        for(i = 0; i < n; i++)
        {  
            c = a[rand() % (sizeof(a))];
            printf("%c", c);  
        }
        printf("\n");
    return 0;
}
