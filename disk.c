/*DISK USAGE FOR STATUS REPORT-*/
#include<stdio.h>
#include<stdlib.h>
#include<sys/vfs.h>
struct statfs buf;

main()
{
	int i=statfs("/",&buf);
	if(i!=0)
	{
		printf("Failed\n");
		exit(0);
	}
	if(buf.f_type==0xEF53)
		printf("ext_fs file system\n");
	if(buf.f_type==0x4d44)
		printf("MS DOS_SUPER_MAGIC file system \n");
	printf("optimum transfer blocks =%1d/n",buf.f_bsize);
	printf("total data blocks in file system =%1d\n",buf.f_blocks);
	printf("free blocks in fs=%1d\n",buf.f_bfree);
	printf("f ree blocks avail to non-superuser =%1d\n",buf.f_bavail); 
	printf("total file nodes in file system =%1d\n",buf.f_files);
	printf("free file nodes in fs=%1d\n",buf.f_ffree);
	printf("file system id=%d\n",buf.f_fsid);
	printf("maximum length of file name =%1d\n",buf.f_namelen);
	
	return 0;
}
