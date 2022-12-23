#include<stdio.h>

void lru(int ref[],int size,int n)
{
    int frames[n];
    //initializing frames to -1(-1 will show that frame is empty)
    for(int i=0;i<n;i++){
        frames[i]=-1;
    }
    int pageMiss=0;
    int pageHits=0;
    for(int i=0;i<size;i++){
            int flag=0;
            for(int j=0;j<n;j++){
                    if(frames[j]==ref[i]){
                    //if reference string and frame is same then page hit
                            flag=1;
                            break;
                    }
            }
            if(flag==1){
                pageHits++;
            }
            else{
            //checks if the frames still has empty frames or not
                for(int j=0;j<n;j++){
                    if(frames[j]==-1){
                        frames[j]=ref[i];
                        break;
                    }else if(frames[j]==ref[n-1]){ //if frames do not have empty frames then use lru to replace page
                        frames[j]=ref[i];
                    }
                }
                 pageMiss++;
            }
    }
    printf("page faults:%d ,page hits:%d",pageMiss,pageHits);
}
//Main function
int main(void)
{
    int ref[]={1,2,3,4,4,5};
    int frames=3;
    //size of int is 4 if there are 6 integers then size is 6*4=24 and divide it by int size that is 24/4=6
    int size=sizeof(ref)/sizeof(int); 
    lru(ref,size,frames);
    return 0;
}
