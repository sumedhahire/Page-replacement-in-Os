#include<stdio.h>

void fifo(int string[20],int n,int size)//n no frames
{
    //Creating array for block storage
    int frames[n];
    //-1 for every block in frame to show that it is empty
    for (int i=0;i<n;i++)
        frames[i]=-1;


    int index=0;
	int i,j;
    //Counters
    int page_miss=0;
    int page_hits=0;

    //Traversing each symbol in fifo
    for (i=0;i<size;i++)
    {

        int flag=0;
        for(j=0;j<n;j++)
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
            if(index<2){
                frames[index]=string[i];
                page_miss+=1;
                index++;
            }else if(index==2){
                frames[index]=string[i];
                page_miss+=1;
                index=0;
            }
        }
    }
    printf("\nPage hits: %d",page_hits);
    printf("\nPage misses: %d",page_miss);
}

//Main function
int main(void)
{
    int string[]={7,0,1,2,0,3,0,4,2};
    int no_frames=3;
    //if we have 4 int values that means 4*4=16,divide it by int value that is 16/4 we got the size of the array
    int size=sizeof(string) / sizeof(int);//int size is 4 

    printf("%d",size);
    fifo(string,no_frames,size);
    return 0;
}
