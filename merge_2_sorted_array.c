 #include<stdio.h>
 void merge(int[],int,int[],int,int[]);
 int main()
 {
 	int a[50],b[50],r[100];
 	int n,m,x,k,i=0,j=0;
 	printf("Enter the number of elements in 1st array");
 	scanf("%d",&n);
 	printf("Enter the values");
 	for(i=0;i<n;i++)
 	{
 		scanf("%d",&a[i]);
 	}
 	printf("Enter the number of elements of 2 nd array");
 	scanf("%d",&m);
 	printf("Enter the values");
 	for(i=0;i<m;i++)
 	{
 		scanf("%d",&b[i]);
 	}
 	merge(a,n,b,m,r);
 }
  void merge(int a[],int n,int b[],int m,int r[])
  {
  	int i=0,k=0,j=0;
  	while(i<n && j<m)
  	{
  		if(a[i]<b[j])
  		{
  			r[k]=a[i];
  			k++;
  			i++;
  		}
  		else
  		{
  			r[k]=b[j];
  			k++;
  			j++;
  		}
  	}
  	while(i<n)
  	{
  		r[k]=a[i];
  		i++;
  		k++;
  	}
  	while(j<m)
  	{
  		r[k]=b[j];
  		j++;
  		k++;
  	}
  	for(k=0;k<m+n;k++)
	{
		printf("%d ",r[k]);
	}
  }
