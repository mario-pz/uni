/* ----------- Εκφώνηση - Disclaimer ----------- 

    Βγάζω όλους τους πιθανούς αλγορίθμους που ζητήθηκαν στην την ύλη μας. 
    Δεν παίρνω καμία ευθήνη αν κατηγορηθείτε για αντιγραφή αν παίρνετε τυφλά περίεργους αλγορίθμους χωρίς να ξέρετε.
    
    I brought out all the possible algorithms requested in our material.
    I take no responsibility if you get accused of copying if you blindly take off strange algorithms without even understanding it. 
*/


/*-----------  Βιβλιοθήκες - Libraries ----------- */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*----------- Αλγόριθμοι - Algorithms --------------*/

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubble_sort(int *arr, int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j=0; j < n-i-1; j++)
        {
            int item_a = *(arr + j);
            int item_b = *(arr + j + 1);
            swap(&item_a, &item_b);
        }
    }
}

void print_p_n(int n)
{
   // Prints out all number combinations
   for(int i = 1; i <= n - 2; i++)
      for(int j = i + 1; j <= n - 1; j++)
         for(int k = j + 1; k <= n; k++)
             printf("[%d %d %d]", i,j,k);
}

void print_p_arr(int n, int* arr)
{
   // Prints out all possible integer array combinations
   for(int i = 1; i <= n - 2; i++)
      for(int j = i + 1; j <= n - 1; j++)
         for(int k = j + 1; k <= n; k++)
             printf("[%d %d %d]", *(arr + i),*(arr + j),*(arr + k));
}

int* arr_freqs(int len_arr, int* arr)
{
   // Returns an array of integers that contain how many times they have been combined
   int temp_arr[len_arr] = 0; 
   for(int i = 1; i <= len_arr - 2; i++)
      for(int j = i + 1; j <= len_arr - 1; j++)
         for(int k = j + 1; k <= len_arr; k++)
             temp_arr[ arr[i] - 1 ]++;
             temp_arr[ arr[j] - 1 ]++;
             temp_arr[ arr[k] - 1 ]++;
   return temp_arr;
}

void r_2d_planting(int** array, int r, int c, int *bombs){

    // Μοιράζω δίκαια σε κάθε row βόμβες και μετά απο εκεί εξαρτάτε από το stock 
    int div_bombs = ceil(*bombs / r); 

    for(int i = 0; i < r; i++)
    {   
        for(int j=0; j < div_bombs; j++)
        {   
            int random_index = 0;
            if (*bombs > 0)
            {
                // Ξανα χτυπάει αριθμό όταν βρίσκει 3 μέσα στο κελί 
                do{random_index = rand() % 5;} while(*(*(array + i) + random_index) == 3);
                *(*(array + i) + random_index) = 3;
                *bombs-= 1; // Remove one Bomb
            }
        }
    }
}

int** create_2D_array(int r, int c) {
    int** array = (int**) malloc(r * sizeof(int*));
    for (int i = 0; i < r; i++) {
        *(array + i) = (int*) malloc(c * sizeof(int));
        for (int j = 0; j < c; j++) {
            *(*(array + i) + j) = 0;
        }
    }

    return array;
}

void free_2D_array(int*** array, int r) {
    for (int i = 0; i < r; i++) {
        free(*(*array + i));
    }
    free(*array);
}

void print_2d_array(int*** array, int r, int c) {
    // ONLY FOR 2D ARRAYS
    putchar('\n');
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("| %d ", *(*(*array + i) + j));
        }
        printf("\n");
    }
}




void guess_six(int x1, int x2, int y1, int y2)
{
   // Prints out all number combinations
   for(int i = 1; i <= 12-5; i++)
      for(int j = i + 1; j <= 12-4; j++)
         for(int k = j + 1; k <= 12-3; k++)
            for(int l = k + 1; l <= 12 - 2; l++)
                for(int m = l + 1; m <= 12 - 1; m++)
                    for(int n = m + 1; n <= 12; n++)
                    {
                        int y_total = i + j + k + l + m + n;
                        if (y_total >= y1 && y_total <= y2)
                        {
                            // Arties metablhtes
                            int x_array[3] = {j, l, n}; 
                            int success = 1; // False


                            for(int w = 0; w < 3; w++)
                            {
                                if ( x_array[w] >= x1 && x_array[w] <= x2)
                                {
                                    success = 0;
                                }
                                else
                                {
                                    success = 1;
                                }
                            }   

                            if(success)
                            {
                                printf("[%d %d %d %d %d %d]",i,j,k,l,m,n);
                            }
                        }
                    }
}









