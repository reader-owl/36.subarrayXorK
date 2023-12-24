#include <iostream>

/*
                    Q. count subarrays with XOR as K

                exa -  given arr[] = {4, 2, 2, 6, 4}    k = 6
                    desired subarrays - {4, 2}                      // [100]^[010] = [110] = 6
                                        {6}                         // [110] = 6
                                        {2, 2, 6}                   // [010]^[010]^[110] = [000]^[110] = [110] = 6
                                        {4, 2, 2, 6, 4}             // [100]^[010]^[010]^[110]^[100] = [100]^[100]^[010]^[010]^[110] = [110] = 6
                                Answer - 4

                        XOR - change the numbers in binary then find their XOR with relative to their binary

            Brute force -  as subarray with sum K

        Pseudo code
for(i=0; i<n; i++)
{
    for(j=i; j<n; j++)
    {
        XOR = 0
        for(k=i->j)
        {
            XOR = XOR^arr[k];           // this will iterate through i->j and give XOR of that
        }
        if(XOR == k)
            cnt++;
    }
}

            TC - O(N^3)
            SC - O(1)


            Better sol -  

        Pseudo cde
for(i=0; i<n; i++)
{
    for(j=; j<n; j++)
    {
        XOR = XOR^arr[j];

        if(XOR == k)
            cnt++;
    }
}

            TC - O(N^2)
            SC - O(1)


            Optimal sol -  we will be focusing on ending point of desired o/p (i.e [4, 2], [2, 2, 6], ..)
                            lets take example of - [4, 2, 2, 6, 4]
                            and lets say elements [4, 2, 2, 6] has XOR of 'XR'
                                if [2, 2, 6] has XOR of 'K' and element '4' has XOR of 'X'
                            then we can say that -  x^k = XR
                                    take XOR of 'k' on both sides
                                                    (x^k)^k = XR^k
                                                =>        x = XR^k      ..(a

                                        to store these values we will use hash table  -

                            lets firstly store (0, 1) in hash map at the very start         // (0, 1) -> (front XOR, cnt)
                            then take 4(1st element), from (a -  x = XR^k
                                                                 x = 4^6
                                                                 x = 2
                                and there is none 2  stored in our hash map previously so we move ahead and 
                                store (4, 1) in our hash map for (front XOR, cnt)

                            then take 2, then XR = 4^2 = 6
                                                     x = XR^k = 6^6
                                                     x = 0
                                and there is a '0' stored in hash map at the start so we store
                                (6, 1) in our hash map, counter will be '1'

                            take 2, then XR = 4
                                                x = 4^6
                                                x = 2
                                there is no '2' stored in hash map, so we store (4, 1) but we already have XR= 4
                                in our hash map so we will increase our counter - (4, 2)

                            take 6, then XR = 2 (4^2^2^6 = 2)
                                                x = 2^6
                                                x = 4
                                there are 2 XOR with XR = '4',  ([4], [4, 2, 2]),   then we store (2, 1) in our
                                hash map and counter will be 3 bcz we got 3 subarrays({[4], [2, 2, 6]}, {[4, 2, 2], [6]})

                            take 4, then XR = 6
                                                x = 6^6
                                                x = 0
                                there is '0' stored in our hash map and counter will be '4'

        Actual code
int subArrayWithSumK(vector<int> a, int k)
{
    int xr = 0;
    map<int, int> mpp;
    mpp[xr]++;          // (o, 1)

    for(int i = 0; i < a.size(); i++)
    {
        xr = xr ^ a[i];         // k
        int x = xr ^ k;
        cnt += mpp[x];
        mpp[xr]++;
    }
    return cnt;
}

                TC - O(N + log N)
                SC - O(N)
*/

int main()
{
    std::cout << "Hello World!\n";
}