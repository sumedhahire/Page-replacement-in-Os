#include<stdio.h>

void optimal(int string[20],int n,int size)
{
    //Creating array for block storage
    int frames[n];
    //Initializing each block with -1
    for (int i=0;i<n;i++)
        frames[i]=-1;

    //Index to insert element
    int index=-1;

    //Counters
    int page_miss=0;
    int page_hits=0;

    //Pointer to indicate initially frames filled or not
    int full=0;

    //Traversing each symbol in fifo
    for (int i=0;i<size;i++)
    {
       
        int flag=0;

        for(int j=0;j<n;j++)
        {
            if (string[i]==frames[j])
            {
                flag=1;
                break;
            }
        }

        if (flag==1)
        {
            page_hits+=1;
        }
        else
        {
            //Frames are still empty
            if (full==0)
            {
                index=(index+1)%n;
                frames[index]=string[i];
                page_miss+=1;

                //Frames filled or not
                if (i==n-1)
                    full=1;
                
            }

            //Frames are full, now we can apply optimal page replacement
            else
            {
                //First find the index to replace with
                int pos=-1;
                int index=-1;

                //Traversing each symbol and checking their optimal possibility
                for(int j=0;j<n;j++)
                {
                    //Whether symbol in frame found or not in future cached frame
                    int found=0;
                    for (int k=i+1;k<size;k++)
                    {
                        //If symbol exists in cached string
                        if (frames[j]==string[k])
                        {
                            found=1;
                            if (pos<k)
                            {
                                pos=k;
                                index=j;
                            }
                            break;
                        } 
                    }
                    //Symbol does not exist in cached frame
                    if (found==0)
                    {
                        pos=size;
                        index=j;
                        
                    }
                }
                page_miss++;
                //Now assign symbol in lru position
                frames[index]=string[i];

            }
           
        }
    }
    printf("\nPage hits: %d",page_hits);
    printf("\nPage misses: %d",page_miss);
}

//Main function
int main(void)
{
    int string[]={2,4,7,6,7,2,2,3,3,3};
    int no_frames=3;
    int size=sizeof(string)/sizeof(int);
    printf("%d",size);
    optimal(string,no_frames,size);
    return 0;
}
