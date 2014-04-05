#include <stdio.h>
#include <stdlib.h>
#include <libvirt/libvirt.h>

void main()
{

    int i,value=-1,ch,ch_id,num_dom;
    int *active;
    virConnectPtr conn;
    virDomainPtr vi,v;
    char ch_name[25],*name; 

    conn = virConnectOpen("xen:///");

    if (conn == NULL) {
        fprintf(stderr, "Error in opening connection to XEN:/// \n");
        exit(0);
    }
    else
    {

	num_dom=virConnectNumOfDomains(conn);
        active=malloc(sizeof(int) * num_dom);
        num_dom= virConnectListDomains(conn, active, num_dom);
	printf("Active domain IDs : \n");
        for (i = 0 ; i < num_dom ; i++) 
	{
	 v=virDomainLookupByID(conn,i);
	 name=virDomainGetName(v);
         printf(" %s\n",name);
        }
        free(active);


	printf("\nInsert the Domian name :");
        scanf("%s",ch_name);   
        while(1)
        {
            
            printf("\n1.Start\n2.Suspend\n3.Resume\n4.stop\n5.exit\n ");
            printf("\nEnter choice:");
            scanf("%d",&ch);
	
	    vi=virDomainLookupByName(conn,ch_name);

	    
            switch(ch)
            {
                case 1:/* Start */
		       value=virDomainCreate(vi);
                       if(value==0)
                           printf("Domain %s successfully created",ch_name);
                       else
                           printf("Failed");
                       break;
                case 2:/* Suspend */
		       value=virDomainSuspend(vi);
                       if(value==0)
                           printf("Domain %s successfully suspended",ch_name);
                       else
                           printf("Failed");
                       break;
                case 3:/* Resume */
		        value=virDomainResume(vi);
                        if(value==0)
                            printf("Domain %s successfully resumed",ch_name);
                        else
                            printf("Failed");
                        break;

                case 4: /* stop */
		        value=virDomainShutdown(vi);
                        if(value==0)
                            printf("Domain %s successfully stopped",ch_name);
                        else
                            printf("Failed");
                        break;
                default:exit(1);
            }
        }
        virConnectClose(conn);
    }
}
