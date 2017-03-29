#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct apprentice
{
    char Second_Name[20];
    char Name[20];
    int first_mark;
    int second_mark;
};

void Not_passed(apprentice app[], int N)
{
    int buf;
    char *temp = (char*)malloc(20*sizeof(char));

//sort the list alphabetically
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            if ( strcmp(app[j].Second_Name, app[i].Second_Name) > 0)
            {
                strcpy(temp,app[i].Second_Name);
                strcpy(app[i].Second_Name,app[j].Second_Name);
                strcpy(app[j].Second_Name,temp);

                strcpy(temp,app[i].Name);
                strcpy(app[i].Name,app[j].Name);
                strcpy(app[j].Name,temp);

                buf = app[i].first_mark;
                app[i].first_mark = app[j].first_mark;
                app[j].first_mark = buf;

                buf = app[i].second_mark;
                app[i].second_mark = app[j].second_mark;
                app[j].second_mark = buf;
            }
        }
//print list of students who do not pass the exam
    for (int i = 0; i < N; ++i)
        if ( app[i].first_mark < 30 || app[i].second_mark < 30)
            printf("%s %s \n", app[i].Second_Name, app[i].Name);
}

int main()
{
    apprentice app[500];
    int N;

//filling list from a file
    FILE *f_in;
    f_in = fopen("input.txt","r");
    fscanf(f_in,"%i",&N);

    for (int i = 0; i<N; ++i)
    {
        fscanf(f_in,"%s",app[i].Second_Name);
        fscanf(f_in,"%s",app[i].Name);
        fscanf(f_in,"%i",&app[i].first_mark);
        fscanf(f_in,"%i",&app[i].second_mark);
    }

    Not_passed(app,N);
    system("pause");
    return 1;
}
