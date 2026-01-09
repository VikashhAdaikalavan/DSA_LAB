#include <stdio.h>
#include <stdlib.h>

typedef struct{

    int id;
    char name[100];
    float marks[3];

}student;

int main()
{
    int t;
    scanf("%d",&t);
    student arr[t];
    for(int a = 0; a <t ; a++)
    {
        scanf("%d",&arr[a].id);
        scanf("%s",arr[a].name);
        scanf("%f",&arr[a].marks[0]);
        scanf("%f",&arr[a].marks[1]);
        scanf("%f",&arr[a].marks[2]);
    }
    float mavg  = 0;
    int j = 0;
    printf("Merit List\n");
    for(int i = 0; i<t ; i++)
    {
        float avg = (arr[i].marks[0]+arr[i].marks[1]+ arr[i].marks[2])/3;
        if(avg>mavg)
        {
            mavg = avg;
            j = i;
        }
        if(avg>75)
        {
            printf("%d %s %f", arr[i].id, arr[i].name, avg);
        }
    }
    printf("\n");
    printf("Toppers : ");
    printf("%s %.2f\n",arr[j].name,mavg);
    return 0;

}