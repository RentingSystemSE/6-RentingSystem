#include <iostream>
using namespace std;

int getDate(int *day,int *month, int *year)
{
    int flag=1;
    
    if((*year>=1990 && *year<=2015)&&(*month>=1 && *month<=12)&&(*day>=1 && *day<=31))
    {
    	if(*month==2)
    	{
    	    if(((*year % 4 == 0) && (*year % 100 != 0)) || (*year % 400 == 0))
    	    {
    	       if(*day>29)
    	       {
    	           flag=0;
    	       }
    	    }
    	    else if(*day>28)
    	    {
    	       flag=0;
    	    }
    	}
    	else if(*month==4|| *month==6 || *month==9|| *month==11)
    	{
    		if(*day>30)
    		{
    	       flag=0;
    	    }
    	}
    }
    if(flag==1)
    {
        if(*day==1)
    	{
    	    flag=1;
    	    if(*month==1)
    	    {
    	        *day=31;
    			*month = 12;
    			*year = *year - 1 ;   
    	    }
    	    else if(*month==2)
    	    {
    	        *day=31;
    			*month = *month -1;
    	    }
    	    else if(*month==3)
    	    {
    	        if(((*year % 4 == 0) && (*year % 100 != 0)) || (*year % 400 == 0))	
    				*day=29;
    			else
    				*day=28;
    			
    			*month = *month -1;
    	    }
    	    else if(*month==4|| *month==6|| *month==8|| *month==9|| *month==11)
    		{
    			*day=31;
    			*month = *month -1;	
    		}
    		else
    		{
    			*day=30;
    			*month = *month -1;
    		}
    	}
    	else
    	{
    	    
    		*day = *day-1;
    	}
    }
return flag;
}

int main()
{
	int dd=1,mm=1,yy=2017;
	cin>>dd>>mm>>yy;
    if(getDate(&dd,&mm, &yy))
	    cout<<endl<<"Previous date : "<<dd<<"/"<<mm<<"/"<<yy;
	else
	    cout<<endl<<"Invalid";
	    
	return 0;    
}
