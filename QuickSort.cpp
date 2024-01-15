#include <iostream>

using namespace std;
// int A[1000] = {2,7,9,4,8,2,10,5};
int A[1000] = {4, 9, 3, 7, 10, 11, 8};
// int A[1000] = {1, 5, 7, 9, 6, 4, 3, 8};
int n = 7;

void in_ra(){
    for (int i = 0; i < n; i++)
        cout<< A[i]<<"  ";
    cout << endl;
}

void QuickSort(int L, int H){
    cout<< L << "  " << H << endl;
    in_ra();
    if (L < H){
        
        int k = A[(int)(L+H)/2];
        // cout<<k;
        int i = L;
        int j = H;
        do{ 
            while (A[i] < k) i++;
            while (A[j] > k) j--;
       
                // cout << A[i] << "   " << A[j] << endl;
            if (i <= j){
                if (i < j){
                    int tmp = A[i];
                    A[i] = A[j];
                    A[j] = tmp;
                }
                // cout << A[i] << "   " << A[j] << endl;
                i++;
                j--;
            }
            
        }while (i <= j);
        // cout << "i=" << i << "j=" <<j;
        QuickSort(L,j);
        QuickSort(i,H);
    }
}


int main()
{
    
    QuickSort(0, n - 1);

    


    return 0;
}
