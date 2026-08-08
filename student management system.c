#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int i=0;
struct stu
{
	int rollno;
	char fname[50];
	char lname[50];
	float cgpa;
	int cid[10];
}st[55];
void add_stu()
{
	printf("enter a student data\n");
	printf("----------------------\n");
	printf("enter a first name...\n");
	scanf("%s",st[i].fname);
	printf("enter a last name...\n");
	scanf("%s",st[i].lname);
	printf("enter a rollno...\n");
	scanf("%d",&st[i].rollno);
	printf("enter a cgpa...\n");
	scanf("%f",&st[i].cgpa);
	printf("enter a ID of each course...\n");
	for(int j=0;j<5;j++)
	{
		scanf("%d",&st[i].cid[j]);
	}
	i=i+1;
}
void find_rollno()
{
    int x;
    int found = 0;

    printf("Enter roll number: ");
    scanf("%d",&x);

    for(int j=0; j<i; j++)
    {
        if(x == st[j].rollno)
        {
            printf("\nStudent Details\n");
            printf("---------------------\n");
            printf("First Name : %s\n", st[j].fname);
            printf("Last Name  : %s\n", st[j].lname);
            printf("Roll No    : %d\n", st[j].rollno);
            printf("CGPA       : %.2f\n", st[j].cgpa);

            printf("Course IDs : ");
            for(int k=0; k<5; k++)
            {
                printf("%d ", st[j].cid[k]);
            }
            printf("\n");

            found = 1;
            break;
        }
    }

    if(found == 0)
    {
        printf("Student not found.\n");
    }
}
void display_all()
{
    if(i == 0)
    {
        printf("\nNo student records found.\n");
        return;
    }

    printf("\n========== STUDENT RECORDS ==========\n");

    for(int j = 0; j < i; j++)
    {
        printf("\nStudent %d\n", j + 1);
        printf("-------------------------\n");
        printf("First Name : %s\n", st[j].fname);
        printf("Last Name  : %s\n", st[j].lname);
        printf("Roll No    : %d\n", st[j].rollno);
        printf("CGPA       : %.2f\n", st[j].cgpa);

        printf("Course IDs : ");
        for(int k = 0; k < 5; k++)
        {
            printf("%d ", st[j].cid[k]);
        }
        printf("\n");
    }

    printf("=====================================\n");
}
void search_fname()
{
    char name[50];
    int found = 0;

    printf("Enter First Name: ");
    scanf("%s", name);

    for(int j = 0; j < i; j++)
    {
        if(strcmp(name, st[j].fname) == 0)
        {
            printf("\nStudent Found\n");
            printf("-------------------------\n");
            printf("First Name : %s\n", st[j].fname);
            printf("Last Name  : %s\n", st[j].lname);
            printf("Roll No    : %d\n", st[j].rollno);
            printf("CGPA       : %.2f\n", st[j].cgpa);

            printf("Course IDs : ");
            for(int k = 0; k < 5; k++)
            {
                printf("%d ", st[j].cid[k]);
            }
            printf("\n");

            found = 1;
        }
    }

    if(found == 0)
    {
        printf("Student not found.\n");
    }
}
void search_cgpa()
{
    float cg;
    int found = 0;

    printf("Enter CGPA: ");
    scanf("%f", &cg);

    for(int j = 0; j < i; j++)
    {
        if(st[j].cgpa == cg)
        {
            printf("\nStudent Found\n");
            printf("-------------------------\n");
            printf("First Name : %s\n", st[j].fname);
            printf("Last Name  : %s\n", st[j].lname);
            printf("Roll No    : %d\n", st[j].rollno);
            printf("CGPA       : %.2f\n", st[j].cgpa);

            printf("Course IDs : ");
            for(int k = 0; k < 5; k++)
            {
                printf("%d ", st[j].cid[k]);
            }
            printf("\n");

            found = 1;
        }
    }

    if(found == 0)
    {
        printf("No student found with CGPA %.2f\n", cg);
    }
}
void update_student()
{
    int roll;
    int found = 0;

    printf("Enter Roll Number to Update: ");
    scanf("%d", &roll);

    for(int j = 0; j < i; j++)
    {
        if(st[j].rollno == roll)
        {
            found = 1;

            printf("\nStudent Found\n");
            printf("----------------------\n");

            printf("Enter New First Name: ");
            scanf("%s", st[j].fname);

            printf("Enter New Last Name: ");
            scanf("%s", st[j].lname);

            printf("Enter New Roll Number: ");
            scanf("%d", &st[j].rollno);

            printf("Enter New CGPA: ");
            scanf("%f", &st[j].cgpa);

            printf("Enter 5 New Course IDs:\n");
            for(int k = 0; k < 5; k++)
            {
                scanf("%d", &st[j].cid[k]);
            }

            printf("\nStudent record updated successfully.\n");
            break;
        }
    }

    if(found == 0)
    {
        printf("Student not found.\n");
    }
}
void delete_student()
{
    int roll;
    int found = 0;

    printf("Enter Roll Number to Delete: ");
    scanf("%d", &roll);

    for(int j = 0; j < i; j++)
    {
        if(st[j].rollno == roll)
        {
            found = 1;

            for(int k = j; k < i - 1; k++)
            {
                st[k] = st[k + 1];
            }

            i--; 

            printf("Student record deleted successfully.\n");
            break;
        }
    }

    if(found == 0)
    {
        printf("Student not found.\n");
    }
}
void sort_rollno()
{
    if(i == 0)
    {
        printf("No student records found.\n");
        return;
    }

    struct stu temp;

    for(int j = 0; j < i - 1; j++)
    {
        for(int k = 0; k < i - j - 1; k++)
        {
            if(st[k].rollno > st[k + 1].rollno)
            {
                temp = st[k];
                st[k] = st[k + 1];
                st[k + 1] = temp;
            }
        }
    }

    printf("Students sorted by Roll Number successfully.\n");
}
void sort_cgpa()
{
    if(i == 0)
    {
        printf("No student records found.\n");
        return;
    }

    struct stu temp;

    for(int j = 0; j < i - 1; j++)
    {
        for(int k = 0; k < i - j - 1; k++)
        {
            if(st[k].cgpa > st[k + 1].cgpa)
            {
                temp = st[k];
                st[k] = st[k + 1];
                st[k + 1] = temp;
            }
        }
    }

    printf("Students sorted by CGPA successfully.\n");
}
void save_file()
{
    FILE *fp;

    fp = fopen("student.txt", "w");

    if(fp == NULL)
    {
        printf("File cannot be opened.\n");
        return;
    }

    for(int j = 0; j < i; j++)
    {
        fprintf(fp, "%s %s %d %.2f ",
                st[j].fname,
                st[j].lname,
                st[j].rollno,
                st[j].cgpa);

        for(int k = 0; k < 5; k++)
        {
            fprintf(fp, "%d ", st[j].cid[k]);
        }

        fprintf(fp, "\n");
    }

    fclose(fp);

    printf("Student records saved successfully.\n");
}
void load_file()
{
    FILE *fp;

    fp = fopen("student.txt", "r");

    if(fp == NULL)
    {
        printf("File not found.\n");
        return;
    }

    i = 0;   

    while(fscanf(fp, "%s %s %d %f %d %d %d %d %d",
                 st[i].fname,
                 st[i].lname,
                 &st[i].rollno,
                 &st[i].cgpa,
                 &st[i].cid[0],
                 &st[i].cid[1],
                 &st[i].cid[2],
                 &st[i].cid[3],
                 &st[i].cid[4]) == 9)
    {
        i++;
    }

    fclose(fp);

    printf("Student records loaded successfully.\n");
}
void main()
{
	int op;
	while(1)
	{
		printf("=================================\n");
		printf("   STUDENT MANAGEMENT SYSTEM\n");
		printf("====================================\n");
		printf("1. add student data\n");
		printf("2.find the stu data by rollno\n");
		printf("3.display all stu data\n");
		printf("4.search stu by fname\n");
		printf("5. search stu by cgpa\n");
		printf("6.updates stu data\n");
		printf("7.delete stu by rollno\n");
		printf("8. sort stu data by rollno\n");
		printf("9.sort stu data by cgpa\n");
		printf("10.save file\n");
		printf("11.load file stu data\n");
		printf("enter a choice\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1: add_stu();break;
			case 2: find_rollno();break;
			case 3: display_all(); break;
			case 4: search_fname();break;
			case 5: search_cgpa();break;
			case 6: update_student();break;
			case 7: delete_student();break;
			case 8: sort_rollno();break;
			case 9: sort_cgpa();break;
			case 10: save_file();break;
			case 11: load_file();break;
			default: printf("invalid op\n");
		}
	}
}