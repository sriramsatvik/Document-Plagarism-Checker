#include <stdio.h>
#include<string.h>
#define n 5
struct student
{
  
char pwd[10];
   
int sub, pla;
   
char war[20];
   
char file[20];
 
};

typedef struct student student;

int
main () 
{
while(1){ 
int x, y, i,j,l,per;
FILE *f1,*f2;
int a[5][5];
char p[10], ps[10], sentence[1000],c,d;
int count=0,total=0;
  
student s[n];
  
printf
    ("enter whether ur a student or teacher if teacher press 1 or press 0 and 2 to exit");
  
scanf ("%d", &x);
if(x==2)
exit(0);
for (i = 0; i < n; i++)
    {
      
s[i].sub = 0;
      
s[i].pla = 0;
      
strcpy (s[i].war, "no comments");
    
}
for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
    {
        a[i][j]=0;
    }
}
  
strcpy (s[0].pwd, "sriram");
  
strcpy (s[1].pwd, "satvik");
  
strcpy (s[2].pwd, "siri");
  
strcpy (s[3].pwd, "chandana");
  
strcpy (s[4].pwd, "nope");
  
strcpy (s[0].file, "sriram");
  
strcpy (s[1].file, "satvik");
  
strcpy (s[2].file, "siri");
  
strcpy (s[3].file, "chandana");
  
strcpy (s[4].file, "nope");
  
if (x == 1)
    
    {
      
printf ("enter password");
      
scanf ("%s", p);
      
if (strcmp (p, "teacher") == 0)
	
	{
	  
printf ("\nwelcome");
	  
printf ("\n1.see submissions 2.evaluate the plagiarism");
	  
scanf ("%d", &y);
	  
if (y == 1)
	    
	    {
	      
for (i = 0; i < 5; i++)
		
		{
		  
if (s[i].sub == 0)
		    
		    {
		      
printf
			("\nstudent of id %d has not submitted the assignment",
			 i + 1);
		      
printf ("\nenter the message to be sent to student");
		      
scanf ("%s", s[i].war);
		    
}
		  
		  else
		    
		    {
		      
printf
			("\nstudent of id %d has submitted the assignment",
			 i + 1);
		    
}
		
}
	    if(y==2)
	    {
	        for(i=0;i<n;i++)
	        {
	            for(j=i+1;j<n;j++)
	            {
	                 count=0;
	                 total=0;
	                f1=fopen(s[i].file,"r");
	                f2=fopen(s[j].file,"r");
	                c = fgetc(f1);
	                d = fgetc(f2);
                    while (c != EOF) 
                    { 
                        //fputc(c, f2);
                        if(c==d)
                        count++;
                        total++;
                        c = fgetc(f1); 
                        d = fgetc(f2);
                    } 
                    per = (count/total)*100;
                    a[i][j] = per;
	            }
	        }
	        for (i = 0; i < n; i++) 
            { 
                for (j = 0; j < n; j++) 
                { 
                    if (i < j) 
                    { 
                         a[i][j]=a[j][i];
                    }
                } 
	         }
	         for(i=0;i<n;i++)
	         {
	             int max=0;
	             for(j=0;j<n;j++)
	             {
	                 if(a[i][j]>max)
	                 max=a[i][j];
	             }
	             s[i].pla=max;
	         }
	    }
}
	  
}
      
      else
	
	{
	  
printf ("enter valid credentials\n");
	
}
    
}
  
if (x == 0)
    
    {
      
printf ("enter login and password:\n");
      
scanf ("%d %s", &l, ps);
      
if (strcmp (s[l].pwd, ps) == 0)
	
	{
	  
printf ("\n1.submit assignments 2.see any messages and marks");
	  
scanf ("%d", &y);
	  
if (y == 1)
	    
	    {
	      
 
FILE * fptr;
	      
fptr = fopen (s[l].file, "w");
	      
if (fptr == NULL)
		
		{
		  
printf ("Error!");
		  
exit (1);
		
}
	      
 
printf ("Enter a sentence:\n");
	      
scanf ("%s", sentence);
	      
 
fprintf (fptr, "%s", sentence);
	      
fclose (fptr);
	      
s[l].sub = 1;
	    
}
	  
if (y == 2)
	    
	    {
	      
printf ("%s", s[l].war);
printf("\n %d",s[i].pla);
	    
}
	
}
      
      else
	
	{
	  
printf ("enter valid credentials");
	
}
    
 
}
}  
return 0;


}
